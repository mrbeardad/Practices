#include <iostream>
#include <vector>

using namespace std;

struct BItree
{
    vector<int> arr_m; // 0索引空缺，注意多开一格

    void add(size_t idx, int addNum)
    {
        for ( size_t end{arr_m.size()}; idx < end; idx += idx & -idx ) {
            arr_m[idx] += addNum;
        }
    }

    int query(size_t begin, size_t end)
    {
        return arr_m[end] - arr_m[begin - 1];
    }

    void ru_add(size_t begin, size_t end, int addNum)
    {
        add(begin, addNum);
        add(end + 1, -addNum);
    }

    int ru_query(size_t idx)
    {
        return sum_tool(idx);
    }

    int sum_tool(size_t numIdx)
    {
        int sum{};
        for ( size_t idx{numIdx}; idx > 0; idx -= idx & -idx ) {
            sum += arr_m[idx];
        }
        return sum;
    }
};

struct RangeBIT
{
    vector<int> diff_m;
    vector<int> diffXi_m;

    void range_add(size_t begin, size_t end, int addNum)
    {
        add_tool(begin, addNum);
        add_tool(end + 1, -addNum);
    }

    int range_query(size_t begin, size_t end)
    {
        return sum_tool(end) - sum_tool(begin - 1);
    }

    int sum_tool(size_t idx)
    {
        int sum{};
        for ( size_t orgIdx{idx}; idx > 0; idx -= idx & -idx ) {
            sum += (orgIdx + 1) * diff_m[idx] - diffXi_m[idx];
        }
        return sum;
    }

    void add_tool(size_t idx, int addNum)
    {
        int diffXi = addNum * idx;
        for ( size_t end{diff_m.size()}; idx < end; idx += idx & -idx ) {
            diff_m[idx] += addNum;
            diffXi_m[idx] += diffXi;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    RangeBIT tree;
    tree.diff_m.resize(10);
    tree.diffXi_m.resize(10);
    tree.range_add(5, 6, 1);
    cout << tree.range_query(5, 6);

    return 0;
}

