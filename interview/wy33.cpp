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
        vector<vector<int> > ret;
        for ( long time : tss ) {
            vector<int> query{};
            for ( size_t idx{}; idx < logs.size(); ++idx ) {
                if ( logs[idx][0] <= time && logs[idx][1] >= time )
                    query.emplace_back(idx);
            }
            ret.emplace_back(std::move(query));
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

