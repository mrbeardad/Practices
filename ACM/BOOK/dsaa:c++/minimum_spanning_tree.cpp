#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std ;

struct Adj
{
    size_t adjIdx_m ;
    int weight_m ;
} ;

using Vertex = vector<Adj> ;

struct DisjointSet
{
    vector<int> disSet_m ;

    size_t find(size_t thisIdx)
    {
        if ( disSet_m[thisIdx] < 0 ) {
            return thisIdx ;
        }
        return disSet_m[thisIdx] = find(disSet_m[thisIdx]) ;
    }

    void unionSet(size_t root1, size_t root2) // 需要参数为root
    {
        if ( disSet_m[root1] < disSet_m[root2] ) {
            disSet_m[root2] = root1 ;
        } else {
            if ( disSet_m[root1] == disSet_m[root2] ) {
                --disSet_m[root2] ;
            }
            disSet_m[root1] = root2 ;
        }
    }
} ;

struct Eage
{
    size_t first_m ;
    size_t second_m ;
    int weight_m ;
} ;

bool inline
operator<( const Eage& first, const Eage& second )
{
    return first.weight_m > second.weight_m ;
}

vector<Vertex> Graph ;
DisjointSet DisjSet ;
priority_queue<Eage> MinEage ;

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    string oneLine ;
    istringstream oneLineStrm ;
    Vertex tmpVertex ;
    size_t thisVertexIdx{} ;
    while ( getline( cin, oneLine ) ) {
        oneLineStrm.str(move(oneLine)) ;
        size_t tmpIdx ;
        int tmpWeight ;
        while ( oneLineStrm >> tmpIdx >> tmpWeight ) {
            tmpVertex.push_back({ tmpIdx, tmpWeight }) ;
            MinEage.push({ thisVertexIdx, tmpIdx, tmpWeight }) ;
        }
        Graph.push_back(move(tmpVertex)) ;
        oneLineStrm.clear() ;
        ++thisVertexIdx ;
    }
    DisjSet.disSet_m.resize( Graph.size(), -1 ) ;

    int eageNum{ 1 } ; // N个vertex，N-1条边
    while ( eageNum != Graph.size() ) {
        auto& thisEage{ MinEage.top() } ;
        size_t root1{ DisjSet.find(thisEage.first_m) }, root2{ DisjSet.find(thisEage.second_m) } ;
        if ( root1 != root2 ) {
            DisjSet.unionSet( root1, root2 ) ;
            ++eageNum ;
            cout << thisEage.first_m << "--" << thisEage.second_m << endl ;
        }
        MinEage.pop() ;
    }

    return 0 ;
}
