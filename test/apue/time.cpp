#include <pthread.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>

#include <iostream>

#include "mine.hpp"

void* do_something(void* args=nullptr)
{
    int i{};
    std::cin >> i;
    for ( ; i < 1e9; ++i );
    std::cout << i;
}

int main()
{
    pthread_t tid{};
    pthread_create(nullptr, nullptr, ::do_something, nullptr);
    if ( fork() == 0 ) {
        ::do_something();
        exit(0);
    } else {
        ::do_something();
    }
    wait(nullptr);
    tms cputime{};
    auto stTime = times(&cputime);
    auto clkPerSecond = sysconf(_SC_CLK_TCK);
    std::cout << stTime << std::endl;
    std::cout << cputime.tms_utime << std::endl;
    std::cout << cputime.tms_stime << std::endl;
    std::cout << cputime.tms_cutime << std::endl;
    std::cout << cputime.tms_cstime << std::endl;

    return 0;
}

