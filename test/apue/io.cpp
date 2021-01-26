#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <streambuf>
#include <string>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

#include "mine.hpp"

int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int* p{nullptr};
    signal(SIGSEGV, SIG_IGN);
    std::cout << *p << std::endl;

    return 0;
}

