#include <algorithm>
#include <c++/9.3.0/x86_64-pc-linux-gnu/bits/c++config.h>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename T>
struct STable
{
    vector<vector<T> > table_m;

    template <typename ITER>
    void build(ITER begin, ITER end)
    {
        while ( begin != end ) {
            table_m.push_back({});
            table_m.back().push_back(*begin++);
        }

        int tableSize = table_m.size();
        for ( int maxPow = log(tableSize) / log(2), curPow{1}; curPow <= maxPow; ++curPow ) {
            for ( int idx{}; idx + (1 << curPow) <= tableSize; ++idx ) {
                table_m[idx].push_back(max(table_m[idx][curPow - 1], table_m[idx + (1 << (curPow - 1))][curPow - 1]));
            }
        }
    }

    T query(size_t left, size_t right)
    {
        int maxPow = log1p(right - left) / log(2);
        return max(table_m[left][maxPow], table_m[right - (1 << maxPow) + 1][maxPow]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> v{1, 2, 3, 2, 4, 1, 6, 9, 5};
    STable<int> st;
    st.build(v.begin(), v.end());
    cout << st.query(2, 7) << endl;

    return 0;
}

