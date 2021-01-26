#include <algorithm>
#include <asio.hpp>
#include <asio/co_spawn.hpp>
#include <asio/ssl.hpp>
#include <iostream>
#include <iterator>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

#include "mine.hpp"

void test_timer_expires_after()
{
    asio::io_context ioc{};
    asio::steady_timer timer{ioc, 3s};
    // timer.expires_after(3s);
    std::this_thread::sleep_for(3s);
    timer.async_wait([] (const std::error_code& ec) {
        std::cout << "async_wait success." << std::endl;
    });
}

void test_asio_ssl_server()
{
    asio::io_context            ioc{};
    tcp::acceptor               acceptor{ioc, tcp::endpoint{ip::address_v4::loopback(), 50001}};
    tcp::socket                 sock{ioc};
    std::vector<char>           buf(1024);

    acceptor.accept(sock);

    ssl::context                ctx{ssl::context::sslv23};

    ctx.set_options(ssl::context::default_workarounds);
    ctx.set_password_callback([] (size_t maxLen, int passwdPurpose) {return "1234";});
    ctx.use_certificate_file("ssl/server.crt", ssl::context::pem);
    ctx.use_private_key_file("ssl/server.key", ssl::context::pem);
    ctx.set_verify_mode(ssl::verify_peer);
    ctx.set_verify_callback([] (bool preverified, const ssl::verify_context& vctx) {
        std::cout << std::boolalpha << "preverified " << preverified << std::endl;
        return preverified;
    });
    // ctx.use_rsa_private_key_file("ssl/ca.key", ssl::context::pem);
    // ctx.use_tmp_dh_file("ssl/dh1024.pem");
    ssl::stream<tcp::socket>    sslSock{std::move(sock), ctx};

    sslSock.handshake(ssl::stream_base::server);

    auto readBytes = sslSock.read_some(asio::buffer(buf));
    std::copy_n(buf.begin(), readBytes, std::ostream_iterator<char>{std::cout, ", "});
}

void test_asio_ssl_client()
{
    asio::io_context            ioc{};
    ssl::context                ctx{ssl::context::sslv23};
    std::string                 buf{};

    ctx.load_verify_file("ssl/ca.crt");
    ctx.set_verify_mode(ssl::verify_peer);
    // ctx.set_verify_callback([] (bool preverified, const ssl::verify_context& vctx) {
        // std::cout << std::boolalpha << "preverified " << preverified << std::endl;
        // return preverified;
    // });
    ssl::stream<tcp::socket>    sock{ioc, ctx};
    sock.lowest_layer().connect(tcp::endpoint{ip::address_v4::loopback(), 50001});
    sock.handshake(ssl::stream_base::client);

    std::cin >> buf;
    sock.write_some(asio::buffer(buf));
    std::cout << "write successfully. " << buf << std::endl;
}

asio::awaitable<void> test_asio_coroutine_impl(asio::io_context& ioc)
{
    tcp::acceptor acceptor{ioc, tcp::endpoint{ip::address_v4::loopback(), 50001}};

    auto sock = co_await acceptor.async_accept(asio::use_awaitable);
    std::cout << "acceptor: " << sock.remote_endpoint() << std::endl;
}

void test_asio_coroutine()
{
    asio::io_context ioc{1};
    // asio::co_spawn(ioc, test_asio_coroutine_impl(ioc), asio::detached);
    test_asio_coroutine_impl(ioc);
    std::cout << "co_spawn reuturn." << std::endl;
    ioc.run();
}

void test_default_option()
{
    ssl::context ctx{ssl::context::sslv23};
    std::cout << sizeof(ssl::context::password_purpose) << std::endl;
}

class Server: public std::enable_shared_from_this<Server>
{
    std::vector<int> readBuf_;
    std::vector<int> writeBuf_;
public:
    Server(size_t readBufSize, size_t writeBufSize)
        : readBuf_(readBufSize), writeBuf_(writeBufSize) {  }

    void start(asio::io_context& ioc)
    {
        // asio::co_spawn(ioc, listen(), asio::detached);
        asio::co_spawn(ioc,
            [self = shared_from_this()] () {return self->listen(); },
            asio::detached);
    }

private:
    asio::awaitable<void> listen()
    try {
        auto            ex = co_await asio::this_coro::executor;
        tcp::acceptor   acceptor{ex, tcp::endpoint{tcp::v4(), 50001}};
        auto            sock = co_await acceptor.async_accept(asio::use_awaitable);
        auto            size = co_await sock.async_read_some(asio::buffer(readBuf_), asio::use_awaitable);
        std::copy_n(readBuf_.begin(), size, std::ostream_iterator<int>{std::cout, ", "});
        std::copy_n(readBuf_.begin(), size, writeBuf_.begin());
        size = co_await sock.async_write_some(asio::buffer(writeBuf_), asio::use_awaitable);
    } catch (std::exception& excep) {
        std::cout << excep.what() << std::endl;
    }
};

void test_shared_co_spawn(asio::io_context& ioc)
{
    // Server server{1024, 1024};
    // server.start(ioc);
    auto server = std::make_shared<Server>(1024, 1024);
    server->start(ioc);
}

int main()
{
    asio::io_context ioc{1};
    test_shared_co_spawn(ioc);
    ioc.run();
    // test_asio_coroutine();
    // test_asio_ssl_client();
    // test_asio_ssl_server();
    // test_default_option();

    return 0;
}

