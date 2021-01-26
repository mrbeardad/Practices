#include <filesystem>
#include <grp.h>
#include <iomanip>
#include <iostream>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <unistd.h>

#include <mine.hpp>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << getsid(0) << std::endl;

    return 0;
}

