#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

#include "mine.hpp"

namespace
{
    std::mutex Mx{};
    std::condition_variable Cv{};
    std::queue<int> Que{};

    void consumer();
    void producer();
    void test_detach();
} // namespace

int main()
{
    std::thread t{test_detach};
    t.detach();

    // auto f0 = std::async(consumer);
    // auto f1 = std::async(consumer);
    // auto f2 = std::async(consumer);
    // auto f3 = std::async(consumer);

    // auto f4 = std::async(producer);
    // auto f5 = std::async(producer);
    // auto f6 = std::async(producer);
    // auto f7 = std::async(producer);

    return 0;
}

namespace
{
    void consumer()
    {
        { // synchronism
            std::unique_lock ul{Mx};
            Cv.wait(ul, [](){return Que.size();});
            std::cout << "consumer pop " << Que.front() << std::endl;
            Que.pop();
        }
    }

    void producer()
    {
        static int Cntr{};

        {
            std::unique_lock ul{Mx};
            Que.push(++Cntr);
            std::cout << "producer push " << Cntr << std::endl;
        }
        Cv.notify_one();
    }

    void test_detach()
    {
        th::sleep_for(30s);
        std::cout << "Detached thread exit." << std::endl;
    }
} // namespace
