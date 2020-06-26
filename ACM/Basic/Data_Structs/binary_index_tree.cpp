#include <algorithm>
#include <c++/9.3.0/x86_64-pc-linux-gnu/bits/c++config.h>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename T>
struct BITree
{
    vector<T> tree_m;

    explicit BITree(size_t size): tree_m(size + 1) {}

    T sum_tool(size_t idx)
    {
        T sum{};
        for ( int curIdx = idx; curIdx > 0; curIdx -= curIdx & -curIdx ) {
            sum += tree_m[curIdx];
        }
        return sum;
    }

    void point_add(size_t idx, const T& val) // point_change&range_query
    {
        int size = tree_m.size();
        for ( int curIdx = idx; curIdx < size; curIdx += curIdx & -curIdx ) {
            tree_m[curIdx] += val;
        }
    }

    T range_query(size_t left, size_t right) // point_change&range_query
    {
        return sum_tool(right) - sum_tool(left - 1);
    }

    void range_add(size_t left, size_t right, T val) // range_change&point_query
    {
        point_add(left, val);
        point_add(right + 1, -val);
    }

    T point_query(size_t idx) // range_change&point_query
    {
        return sum_tool(idx);
    }

    void range_add(size_t left, size_t right, T val, vector<T>& diff) // range_change&range_query
    {
        range_add(left, right, val);

        int size = tree_m.size();
        auto pointAdd = [&] (int idx, T val) {
            while ( idx < size ) {
                diff[idx] += val;
                idx += idx & -idx;
            }
        };

        pointAdd(left, val * (left - 1));
        pointAdd(right + 1, val * -(right - 1));
    }

    T range_query(size_t left, size_t right, vector<T>& diff) // range_change&range_query
    {
        auto pointQuery = [&] (int idx) {
            T sum{};
            int orgIdx{idx};
            while ( idx > 0 ) {
                sum += orgIdx * this->tree_m[idx] - diff[idx];
                idx -= idx & -idx;
            }
            return sum;
        };

        return pointQuery(right) - pointQuery(left - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    BITree<int> bit{10};
    // bit.point_add(1, 2);
    // bit.point_add(3, 6);
    // cout << bit.range_query(1, 6) << endl;

    // bit.range_add(1, 6, 2);
    // bit.range_add(5, 7, 3);
    // cout << bit.point_query(5) << endl;

    vector<int> v(11);
    bit.range_add(2, 5, 2, v);
    bit.range_add(4, 7, 3, v);
    cout << bit.range_query(2, 5, v) << endl;
    copy(bit.tree_m.begin(), bit.tree_m.end(), ostream_iterator<int>{cout, " "});

    return 0;
}

