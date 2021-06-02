#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <iostream>
#include <regex>
#include <sstream>
#include <thread>
#include <vector>

#include <fmt/format.h>
#define DISABLE_CLOSE_SYNC_WITH_STDIO
#include "mine.hpp"

struct T
{
    winsize wins_;
    T()
    {
         ::ioctl(STDOUT_FILENO, TIOCGWINSZ, &wins_);
    }
    static T g_Wins;
};

template<typename T>
T f(T t)
{
    std::cout << t << std::endl;
    return t;
}

int main()
{
    f(1);
    std::cout << T::g_Wins.wins_.ws_col;
    return 0;
}

