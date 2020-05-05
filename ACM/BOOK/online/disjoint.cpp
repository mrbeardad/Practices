#include <iostream>
#include <vector>

using namespace std;

struct Disjoint
{
    vector<int> union_m; // 初始化为-1

    size_t root(size_t idx)
    {
        int& parentIdx = union_m[idx];
        if ( parentIdx < 0 ) {
            return idx;
        }

        size_t rootIdx{root(parentIdx)};
        return parentIdx = rootIdx;
    }

    void merge(size_t root1, size_t root2)
    {
        int& dep1{union_m[root1]};
        int& dep2{union_m[root2]};
        if ( dep1 >= 0 || dep2 >= 0 ) {
            cout << "C++Error: Disjoint::merge() need 2 parameters  that are both index of root." << endl;
            exit(1);
        }

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

    

    return 0;
}

