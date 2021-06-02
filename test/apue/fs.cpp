#include <grp.h>
#include <pwd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <unistd.h>

#include <filesystem>
#include <iomanip>
#include <iostream>


#include "bash/signames.h"
#include "fmt/core.h"
#include "mine.hpp"

int main()
{
    utsname osname{};
    mine::handle(::uname(&osname));
    fmt::print("{:15}{}\n{:15}{}\n{:15}{}\n{:15}{}\n{:15}{}\n{:15}{}\n",
            "sysname:", osname.sysname,
            "nodename:", osname.nodename,
            "release:", osname.release,
            "version:", osname.version,
            "machine:", osname.machine,
            "domainname:", osname.domainname);
    std::cout << signal_names[1];

    return 0;
}

