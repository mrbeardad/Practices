#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/shm.h>
#include <unistd.h>

#include "mine.hpp"

namespace
{
    char* mp{};
    void catch_read(int signal);
    void catch_write(int signal);
} // namespace

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::hex << IPC_CREAT << std::endl;
    exit(0);
    struct shmid_ds s{};
    int fds[2]{};
    pipe(fds);
    std::cout << fpathconf(fds[0], _PC_PIPE_BUF) << std::endl;

    exit(0);
    signal(SIGINT, catch_read);
    signal(SIGTSTP, catch_write);
    mp = static_cast<char*>(mmap(nullptr, 10, PROT_READ | PROT_WRITE, MAP_PRIVATE, open("t", O_RDWR), 0));
    while ( true ) {
        pause();
    }

    return 0;
}

namespace
{
    void catch_read(int signal)
    {
        std::cout << "mmap == " << mp << std::endl;
    }

    void catch_write(int signal)
    {
        *mp = 'X';
        std::cout << "write to mmap == " << mp << std::endl;
    }
} // namespace
