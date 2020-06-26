#include <algorithm>
#include <c++/9.3.0/x86_64-pc-linux-gnu/bits/c++config.h>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct DisSet
{
    vector<int> vec_m;

    explicit DisSet(size_t size): vec_m(size, -1) {}

    size_t root(size_t idx)
    {
        if ( vec_m[idx] < 0 ) {
            return idx;
        }

        size_t itsRoot{root(vec_m[idx])};
        return vec_m[idx] = itsRoot;
    }

    void merge(size_t root1, size_t root2)
    {
        int& dep1{vec_m[root1]};
        int& dep2{vec_m[root2]};
        if ( dep1 < dep2 ) {
            dep2 = root1;
        } else {
            if ( dep1 == dep2 ) {
                --dep2;
            }
            dep1 = root2;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    DisSet disj{10};
    disj.merge(disj.root(1), disj.root(5));
    disj.merge(disj.root(1), disj.root(6));
    disj.merge(disj.root(2), disj.root(3));
    // disj.merge(disj.root(2), disj.root(5));
    copy(disj.vec_m.begin(), disj.vec_m.end(), ostream_iterator<int>{cout, " "});

    return 0;
}

