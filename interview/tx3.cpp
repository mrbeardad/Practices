#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

int main()
{
    int times{};
    std::cin >> times;
    for ( int cnt{}; std::cin >> cnt; ) {
        std::vector<std::pair<int, int> > data(cnt);
        for ( int i{}; i < cnt; ++i )
            std::cin >> data[i].first;
        for ( int i{}; i < cnt; ++i )
            std::cin >> data[i].second;
        std::sort(data.begin(), data.end());
        int curTime{};
        std::vector<int> vals{};
        for ( size_t idx{data.size() - 1}; idx < data.size(); --idx ) {
            if ( data[idx].first != curTime ) {
                curTime = data[idx].first;
            } else {
                vals.emplace_back(data[idx].second);
            }
        }
        std::cout << std::accumulate(vals.begin(), vals.end(), 0) << '\n';
    }
    

    return 0;
}

