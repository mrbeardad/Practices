#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std ;

// 实现并查集数据结构
struct DisjointSet
{
    std::vector<int> ds ;

    DisjointSet(): ds{} {}

    explicit DisjointSet(size_t num): ds(num, -1) {}

    int find(int thisIdx)
    {
        if ( ds[thisIdx] < 0 ) {
            return thisIdx ;
        }
        ds[thisIdx] = find(ds[thisIdx]) ;
        return ds[thisIdx] ;
    }

    bool merge(int formerIdx, int laterIdx)
    {
        int root1{ find(formerIdx) }, root2{ find(laterIdx) } ;
        bool ret{ root1 == root2 ? true : false } ;
        if ( ds[root1] <= ds[root2] ) {
            if ( ds[root1] == ds[root2] ) {
                --ds[root1] ;
            }
            ds[root2] = root1 ;
        } else {
            ds[root1] == root2 ;
        }
        return ret ;
    }
} ;


DisjointSet Djs ;
vector<int> Species ;
int FalseNum{0} ;

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    size_t tmpSize, describeNum ;
    cin >> tmpSize >> describeNum ;
    Djs.ds.resize(tmpSize, -1) ;
    Species.resize(tmpSize) ;

    for (size_t i = 0; i < describeNum; ++i) {
        int type, animalA, animalB ;
        cin >> type >> animalA >> animalB ;

        if ( animalA > tmpSize || animalB > tmpSize || (type == 2 && animalA == animalB) ) {
            ++FalseNum ;
            //cout << "i=" << i << ": " << Species[animalA-1] << ':' << Species[animalB-1] << ' ' << FalseNum << endl ;
            continue ;
        }
        int rootA{ Djs.find(--animalA) }, rootB{ Djs.find(--animalB) } ; // 注意动物编码从1开始，而数组下标从0开始
        if ( rootA != rootB ) { // 没有集合关系，则合并两个集合
            int diff ; // 记录两个集合之间的相对差异，用以后面同化
            if ( type == 1 ) {
                diff = Species[animalA] - Species[animalB] ;
            } else {
                diff = (Species[animalA] + 1) % 3 - Species[animalB] ;
            }
            if ( diff < 0 ) {
                diff += 3 ;
            }
            for ( size_t i{0}; i < tmpSize; ++i ) { // 遍历将B集合的相对种类同化为A的相对种类
                if ( Djs.find(i) == rootB ) {
                    Species[i] = (Species[i] + diff) % 3 ;
                }
            }
            Djs.merge( animalA, animalB ) ;
        } else {
            if ( type == 1 && Species[animalA] != Species[animalB] ) {
                ++FalseNum ;
            } else if ( type == 2 ) {
                if ( Species[animalA] != 2 && Species[animalB] - Species[animalA] != 1 || Species[animalA] == 2 && Species[animalB] != 0 ) {
                    ++FalseNum ;
                }
            }
        }
        //cout << "i=" << i << ": " << Species[animalA] << ':' << Species[animalB] << ' ' << FalseNum << endl ;
    }
    cout << FalseNum ;

    return 0 ;
}
