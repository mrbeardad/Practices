#include <termios.h>
#include <unistd.h>

#include <iostream>

#include "mine.hpp"

int main()
{
    termios term{};
    tcgetattr(STDOUT_FILENO, &term);
    std::cout << (term.c_cflag & ICANON);

    return 0;
}

