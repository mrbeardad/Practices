#include <iostream>

#include "asio.hpp"
#include "asio/co_spawn.hpp"

#include "mine.hpp"

asio::awaitable<void> simple_server()
{
    auto ioc = co_await asio::this_coro::executor;
    tcp::acceptor ac{ioc, tcp::endpoint{asio::ip::address_v4::loopback(), 60000}};
    auto session = co_await ac.async_accept(asio::use_awaitable);
    std::string buffer(1024, 0);
    while ( true ) {
        auto readSize = co_await session.async_read_some(asio::buffer(buffer), asio::use_awaitable);
        std::cout << buffer << std::endl;
    }
}

int main()
{
    asio::io_context ioc{1};
    asio::co_spawn(ioc, simple_server, asio::detached);
    ioc.run();
    std::cout << "finish!" << std::endl;

    return 0;
}

