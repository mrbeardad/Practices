#include <iostream>
#include <vector>
#include <utility>
#include <variant>

using namespace std ;

template <typename T = monostate>
class DisjointSet
{
public:
    DisjointSet(): disj_m{} {}
    explicit DisjointSet(size_t elemCount): disj_m{ elemCount, pair{ -1, T{} } } {}

    auto push_back(const T& t)
    {
        return disj_m.push_back(pair{ -1, t }) ;
    }

    auto push_back(T&& t)
    {
        return disj_m.push_back(move(pair{ -1, move(t) })) ;
    }

    auto resize(size_t size)
    {
        return disj_m.resize( size, pair{ -1, T{} } ) ;
    }

    size_t size()
    {
        return disj_m.size() ;
    }

    size_t find(size_t thisIdx)
    {
        if ( disj_m[thisIdx].first < 0 ) {
            return thisIdx ;
        }
        return disj_m[thisIdx].first = find(disj_m[thisIdx].first) ;
    }

    void unionSet(size_t root1, size_t root2)
    {
        if ( disj_m[root1].first < disj_m[root2].first ) {
            disj_m[root2].first = root1 ;
        } else {
            if ( disj_m[root1].first == disj_m[root2].first ) {
                --disj_m[root2].first ;
            }
            disj_m[root1].first = root2 ;
        }
    }

    T& operator[](size_t idx)
    {
        return disj_m[idx].second ;
    }

//private:
    vector<pair<int, T>> disj_m ;
} ;

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    DisjointSet<int> disj ;
    int tmp ;
    while ( cin >> tmp ) {
        disj.push_back(tmp) ;
    }

    for ( size_t idx{}, end{ disj.size() }; idx < end; ++idx ) {
        auto next{ idx + 1 } ;
        if ( disj[idx] > 0 && disj[next] > 0 || disj[idx] < 0 && disj[next] < 0 ) {
            disj.unionSet( disj.find(idx), disj.find(next) ) ;
        }
    }
    for (int i = 0; i < disj.size(); ++i) {
        cout << disj.find(i) << ' ' ;
    }

    return 0 ;
}
