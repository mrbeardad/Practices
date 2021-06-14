#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using std::vector;

vector<int> findBuilding(vector<int>& heights) {
    vector<int> seeing(heights.size(), 1);
    vector<int> stackVal{};
    vector<size_t> stackIdx{};
    for ( size_t idx{}; idx < heights.size(); ++idx ) {
        // 将破坏单调性的元素弹出
        for ( ; stackVal.size() && stackVal.back() <= heights[idx]; ) {
            auto topIdx = stackIdx.back();
            seeing[topIdx] += idx - topIdx;
            stackVal.pop_back();
            stackIdx.pop_back();
        }
        stackVal.emplace_back(heights[idx]);
        stackIdx.emplace_back(idx);
    }
    std::copy(seeing.begin(), seeing.end(), std::ostream_iterator<int>{std::cout, ","});
    std::cout << std::endl;
    stackVal.clear();
    stackIdx.clear();
    for ( size_t idx{heights.size() - 1}; idx < heights.size(); --idx ) {   // --idx溢出后回环
        // 将破坏单调性的元素弹出
        for ( ; stackVal.size() &&stackVal.back() <= heights[idx]; ) {
            auto topIdx = stackIdx.back();
            seeing[topIdx] += topIdx - idx;
            stackVal.pop_back();
            stackIdx.pop_back();
        }
        stackVal.emplace_back(heights[idx]);
        stackIdx.emplace_back(idx);
    }
    return seeing;
}

int main()
{
    vector<int> input(std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{});
    auto ans = findBuilding(input);
    std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>{std::cout, ","});
    std::cout << std::endl;

    return 0;
}
