#include <arpa/inet.h>
#include <fcntl.h>
#include <fstream>
#include <future>
#include <grp.h>
#include <grp.h>
#include <inttypes.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <limits.h>
#include <math.h>
#include <netdb.h>
#include <pthread.h>
#include <pty.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/un.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

#include "mine.hpp"

void unix_socket_server()
{
    constexpr auto* SOCK_PATH = "/tmp/test-sock";

    auto sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    sockaddr_un adun{AF_UNIX};
    strcpy(adun.sun_path, SOCK_PATH);
    bind(sockfd, reinterpret_cast<sockaddr*>(&adun), sizeof(adun));

    listen(sockfd, SOMAXCONN);

    sockaddr_un caddr{};
    socklen_t alen{};
    auto cfd = accept(sockfd, reinterpret_cast<sockaddr*>(&caddr), &alen);
    std::cout << caddr.sun_path << std::endl;

    char buf[1024]{};
    recv(cfd, buf, 1024, 0);
    std::cout << buf << std::endl;

    unlink(SOCK_PATH);
}

void unix_socket_client()
{
    constexpr auto* SOCK_PATH = "/tmp/test-sock";

    auto sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    sockaddr_un adun{AF_UNIX};
    strcpy(adun.sun_path, SOCK_PATH);
    connect(sockfd, reinterpret_cast<sockaddr*>(&adun), sizeof(adun));
    send(sockfd, SOCK_PATH, strlen(SOCK_PATH), 0);
}

void inet_socket_server()
{
    struct addrinfo hint{AI_PASSIVE, 0, SOCK_STREAM};
    struct addrinfo *aiList{};
    getaddrinfo(0, "5001", &hint, &aiList);
    auto sfd = socket(AF_INET, SOCK_STREAM, 0);
    while ( aiList != nullptr ) {
        // std::cout << reinterpret_cast<sockaddr_in*>(aiList->ai_addr)->sin_addr.s_addr << std::endl;
        // std::cout << reinterpret_cast<sockaddr_in*>(aiList->ai_addr)->sin_port << std::endl;
        char host[100]{};
        char service[100]{};
        getnameinfo(aiList->ai_addr, aiList->ai_addrlen, host, 100, service, 100, NI_NUMERICHOST|NI_NUMERICSERV);
        std::cout << host << std::endl;
        std::cout << service << std::endl;
        // if ( bind(sfd, aiList->ai_addr, aiList->ai_addrlen) == 0 ) {
        //     break;
        // }
        aiList = aiList->ai_next;
    }
    // listen(sfd, SOMAXCONN);
//
    // auto addr = reinterpret_cast<sockaddr_in*>(aiList->ai_addr);
    // char domain[INET_ADDRSTRLEN]{};
    // inet_ntop(AF_INET, &addr->sin_addr, domain, INET_ADDRSTRLEN);
    // std::cout << "Server IP:" << domain << " Port:" << addr->sin_port << std::endl;
    // while ( true ) {
        // sockaddr_in peerAddr{};
        // auto fd = accept(sfd, (struct sockaddr*)&peerAddr, sizeof(peerAddr));
        // std::cout << peerAddr.sin_addr.s_addr << std::endl;
    // }
}

void donothing(int signal) {}

#if 0
void pty_test(int argc, char* argv[])
{
    int fdm{}, fds{};
    termios t{};
    t.c_iflag = ICRNL | IXON;
    t.c_oflag = OPOST | ONLCR;
    t.c_cflag = CS8 | CREAD;
    t.c_lflag = ISIG | ICANON | IEXTEN;
    t.c_cc[VMIN] = 1;
    t.c_cc[VTIME] = 0;
    t.c_cc[VINTR] = '\003';
#if 0
    if ( forkpty(&fdm, nullptr, &t, nullptr) == 0 ) {
        execvp(argv[1], argv + 1);
    }
#else
    openpty(&fdm, &fds, nullptr, &t, nullptr);
    if ( fork() == 0 ) {
        setsid();
        dup2(fds, STDIN_FILENO);
        dup2(fds, STDOUT_FILENO);
        dup2(fds, STDERR_FILENO);
        execvp(argv[1], argv + 1);
    }
#endif

    if ( fork() == 0 ) {
        for ( char buf[512]{}; true; ) {
            auto nread = read(fdm, buf, 512);
            if ( nread <= 0 ) break;
            std::cout << "read " << nread << " from ptm: " << buf << std::endl;
            kill(getppid(), SIGUSR1);
        }
        exit(0);
    }

    signal(SIGUSR1, donothing);
    for ( std::string s{}; true; ) {
        std::cout << "read from stdin: " << std::flush;
        std::cin >> s;
        s += "\003\n";
        std::cout << "write " << write(fdm, s.c_str(), s.size()) << " to ptm" << std::endl;
        pause();
    }

}
#endif

void v()
{
    sigset_t getMask{};
    pthread_sigmask(SIG_BLOCK, nullptr, &getMask);
    std::cout << sigismember(&getMask, SIGTSTP) << std::endl;
}
void* p(void* p) {sleep(2); std::cout << "pthread" << std::endl;  return nullptr; }

void s(int signal)
{
    std::cout << "CONT" << std::endl;
}

int main(int argc, char* argv[])
{
    printf("fuck");

    return 0;
}

