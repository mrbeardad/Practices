#include <fcntl.h>
#include <iostream>
#include <regex>
#include <sstream>
#include <thread>
#include <unistd.h>
#include <vector>

#define DISABLE_CLOSE_SYNC_WITH_STDIO
#include "mine.hpp"

struct T
{
    int i_;
    T(int i = 0):i_{i} {}
    T(const T& t):i_{t.i_} {std::cout << "copy" << std::endl;}
    T(T&& t):i_{t.i_} {std::cout << "move" << std::endl;}
    ~T() {std::cout << "destroy" << std::endl;}
};

void t(const T& v)
{
    std::this_thread::sleep_for(1s);
    std::cout << std::this_thread::get_id() << std::endl;
    std::cout << pthread_self() << std::endl;
}

int main()
{
    T tt{};
    std::thread t1{t, std::ref(tt)};
    std::cout << t1.get_id() << std::endl;
    t1.join();

    return 0;
}

