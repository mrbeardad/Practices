#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename ITER>
vector<int> cnt_sort(ITER begin, ITER end, int minNum, int maxNum)
{
    int eleCnt{};
    vector<int> cnt(maxNum - minNum + 1);
    for ( auto pos{begin}; pos != end; ++pos ) {
        ++cnt[*pos - minNum];
    }
    for ( int idx{1}, end = cnt.size(); idx < end; ++idx ) {
        cnt[idx] += cnt[idx - 1];
    }
    vector<int> ret(cnt.back());
    for ( auto pos{begin}; pos != end; ++pos ) {
        ret[--cnt[*pos - minNum]] = *pos;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> v{5, 7, 8, 4, 1, 3, 2, 0, 9, 6};
    auto r{cnt_sort(v.begin(), v.end(), 0, 9)};
    for_each(r.begin(), r.end(), [](int i){cout << i << ' ';});

    return 0;
}

