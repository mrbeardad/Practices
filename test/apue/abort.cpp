#include <signal.h>
#include <unistd.h>

#include <iostream>

#include "mine.hpp"

void handle(int signal)
{
    std::cout << signal << std::endl;
    return;
}

int main()
{
    signal(SIGABRT, handle);
    // abort();
    sleep(100);
    std::cout << 1 << std::endl;

    return 0;
}

