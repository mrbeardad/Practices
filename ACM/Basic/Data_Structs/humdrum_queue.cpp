#include <c++/9.3.0/x86_64-pc-linux-gnu/bits/c++config.h>
#include <cstddef>
#include <deque>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template <typename T, typename CMP = less<T> >
struct HumdQue
{
    deque<T> que_m;
    CMP cmp_m;

    void push(const T& val)
    {
        while ( !que_m.empty() && cmp_m(val, que_m.back()) ) {
            que_m.pop_back();
        }
        que_m.push_back(val);
    }

    void pop()
    {
        que_m.pop_front();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    /*
     * 滑动窗口
     */
    constexpr int WIN_SIZE{3};
    HumdQue<pair<int, int> > humdQueue;
    for ( int nr{}, tmp4que{}; cin >> tmp4que; ++nr ) {
        humdQueue.push({tmp4que, nr});
        constexpr int WIN_SIZE_1{WIN_SIZE - 1};
        if ( nr >= WIN_SIZE_1 ) {
            if ( nr - humdQueue.que_m.front().second + 1 > WIN_SIZE ) {
                humdQueue.pop();
            }
            cout << "min(" << nr - WIN_SIZE + 1 << ", " << nr << ") = " << humdQueue.que_m.front().first << endl;
        }
    }

    return 0;
}

