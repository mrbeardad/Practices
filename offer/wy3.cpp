#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

using std::vector;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 搜索满足条件的日志。 返回值为二维数组，第一维对应待查询时间戳的下标，第二维是命中日志的事件ID
     * @param logs long长整型vector<vector<>> 日志数据，数组第一维的下标即为事件ID，第二维包含两个long型整数，分别表示起始和结束时间
     * @param tss long长整型vector timestamps，表示待查询的多个时间戳
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > search_log(const vector<vector<long> >& logs, const vector<long>& tss) {
        // write code here
        vector<std::pair<long, size_t> > start(logs.size()), end(logs.size());
        for ( size_t idx{}; idx < logs.size(); ++idx ) {
            start[idx] = std::make_pair(logs[idx][0], idx);
            end[idx] = std::make_pair(logs[idx][1], idx);
        }
        auto comp = [] (const std::pair<long, size_t>& lhs, const std::pair<long, size_t>& rhs) {
            return lhs.first < rhs.first;
        };
        std::sort(start.begin(), start.end(), comp);
        std::sort(end.begin(), end.end(), comp);

        vector<vector<int> > ret;
        for ( long time : tss ) {
            auto head = std::upper_bound(start.begin(), start.end(), std::make_pair(time, 0UL), comp);
            vector<size_t> sID{};
            for ( auto itr = start.begin(); itr < head; ++itr ) {
                sID.emplace_back(itr->second);
            }
            auto tail = std::lower_bound(end.begin(), end.end(), std::make_pair(time, 0UL), comp);
            vector<size_t> eID{};
            for ( auto itr = tail; itr < end.end(); ++itr ) {
                eID.emplace_back(itr->second);
            }
            vector<int> thisQ{};
            // std::copy(sID.begin(), sID.end(), std::ostream_iterator<int>{std::cout, ","});
            // std::cout << std::endl;
            // std::copy(eID.begin(), eID.end(), std::ostream_iterator<int>{std::cout, ","});
            // std::cout << std::endl;
            std::set_intersection(sID.begin(), sID.end(), eID.begin(), eID.end(), std::back_inserter(thisQ));
            ret.emplace_back(std::move(thisQ));
        }
        return ret;
    }
};


int main()
{
    for ( auto& thisV : Solution{}.search_log({{1,2},{2,3},{2,3}}, {1,2}) ) {
        for ( auto thisv : thisV ) {
            std::cout << thisv << ',';
        }
        std::cout << std::endl;
    }
}
