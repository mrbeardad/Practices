#include <condition_variable>
#include <execution>
#include <future>
#include <iomanip>
#include <ios>
#include <iostream>
#include <mutex>
#include <numeric>
#include <regex>
#include <sstream>
#include <thread>
#include <vector>

using namespace std;

mutex MutexLock;
condition_variable CondVar;

stringstream strm;

int C{};

void p1()
{
    // unique_lock lg{MutexLock};
    // CondVar.wait(lg, [](){return !C;});
    for (int i{}; i < 10; ++i) {
        strm << "1" << flush ;
    }
    ++C;
} 

void p2()
{
    // unique_lock lg{MutexLock};
    // CondVar.wait(lg, [](){return C;});
    for (int i{}; i < 10; ++i) {
        strm << "0" << flush;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // string s{"function()  函数()"};
    // cout << regex_replace(s, regex{R"((\(.*?\)))"}, "\033[7m$1\033[m") << endl;
    cout << "AMD YES!" << endl;

    return 0;
}


