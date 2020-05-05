#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct STList
{
    vector<vector<int> > st_m; // 初始化[i][0]

    void build()
    {
        for ( size_t powIdx{1}, powEnd{st_m[0].size()}; powIdx < powEnd; ++powIdx ) {
            size_t powNum = exp2(powIdx);
            for ( size_t numIdx{}, numEnd{st_m.size()}; numIdx + powNum <= numEnd; ++numIdx ) {
                st_m[numIdx][powIdx] = max(st_m[numIdx][powIdx - 1], st_m[numIdx + exp2(powIdx - 1)][powIdx - 1]);
            }
        }
    }

    int query(size_t begin, size_t end)
    {
        size_t maxPow = log(end - begin + 1) / log(2);
        return max(st_m[begin][maxPow], st_m[end - exp2(maxPow) + 1][maxPow]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    STList st;
    size_t maxPow = log(10) / log(2);
    for ( size_t numIdx{}; numIdx < 10; ++numIdx ) {
        st.st_m.push_back(vector<int>(maxPow));
        st.st_m[numIdx][0] = numIdx;
    }
    st.build();
    cout << st.query(2, 6);

    return 0;
}

