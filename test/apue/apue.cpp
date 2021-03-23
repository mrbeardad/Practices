#include <array>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <netdb.h>
#include <pthread.h>
#include <signal.h>
#include <string>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <syslog.h>
#include <termios.h>
#include <thread>
#include <unistd.h>

#include <bash/signames.h>
#include "mine.hpp"

namespace
{
    void trac(int signal);
    void trac_void() {std::cout << "fuck" << std::endl;}
    void* tracv(void* p);
    void catch_signal(int signal);

    class Test
    {
    public:
        Test(int i) noexcept: i_m{i} {}
        ~Test()
        {
            std::cout << "Destory" << std::endl;
        }
    private:
        int i_m;
    };
} // namespace

void signal_handler(int signal)
{
    std::ofstream outf{"test", io::out | io::trunc};
    outf << signal_names[signal] << std::endl;
}

void test_sighup()
{
    if ( fork() == 0 ) {
        setsid();
    } else {
        exit(0);
    }
    signal(SIGHUP, signal_handler);
    if ( fork() == 0 ) {
        if ( fork() == 0 ) {
            setpgid(0, 0);
        }
    }
    std::this_thread::sleep_for(30s);
}

void test_link()
{
    mine::handle(link("tl", "tlllll"));
}

int main()
{
    char a[2]{'a', 'b'};
    auto [b, std::ignore] = a;
    return 0;
}
int not_main()
{
    // std::array limits{
        // RLIMIT_AS,
        // RLIMIT_CORE,
        // RLIMIT_CPU,
        // RLIMIT_DATA,
        // RLIMIT_FSIZE,
        // RLIMIT_MEMLOCK,
        // RLIMIT_MSGQUEUE,
        // RLIMIT_NICE,
        // RLIMIT_NOFILE,
        // RLIMIT_NPROC,
        // RLIMIT_RSS,
        // RLIMIT_SIGPENDING,
        // RLIMIT_STACK
    // };
    // for (struct rlimit rl{}; auto l : limits ) {
        // getrlimit(l, &rl);
        // std::cout << rl.rlim_cur << std::endl;
    // }
    // auto fdptMain = posix_openpt(O_RDWR);
    // grantpt(fdptMain);
    // unlockpt(fdptMain);
    // auto fdptSlave = open(ptsname(fdptMain), O_RDWR);
    // dup2(fdptMain, 0);
    // while ( true ) {
        // char s[10]{};
        // std::cout << "read return with \033[31m" << read(fdptMain, s, 10) << "\033[m and s is \033[31m" << s << "\033[m" << std::endl;
    // }
    auto fd = open("/dev/pts/6", O_RDWR);
    char buf[1024]{};
    if ( read(fd, buf, 1024) < 0 ) {
        std::perror("read error");
        exit(1);
    }
    std::cout << buf << std::endl;

    return 0;
}

namespace
{
    void trac(int signal)
    {
        std::cout << "catch signal: " << signal_names[signal] << std::endl;
    }

    void* tracv(void* p)
    {
        while ( true ) {
            std::cout << "Thread 2: " << getpriority(PRIO_PROCESS, 0) << std::endl;
            std::this_thread::sleep_for(3s);
        }
    }

    void catch_signal(int signal)
    {
        std::cout << signal_names[signal] << std::endl;
    }
} // namespace
