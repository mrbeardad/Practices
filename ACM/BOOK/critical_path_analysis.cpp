#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std ;

struct Vertex
{
    bool isInQueue ;
    int early_m ;
    int late_m ;
    vector<pair<int, int>> prev_m ; // pair<numr, weight>
    vector<pair<int, int>> next_m ;
} ;

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    unordered_map<int, Vertex> Graph ;
    Graph.insert( { 0, { 0, 0, -1, {}, {} } } ) ;

    string oneLine ;
    istringstream oneLineStrm ;
    int numOfRealVertex{} ;
    while ( getline( cin, oneLine ) ) {
        ++numOfRealVertex ;
        oneLineStrm.str( move( oneLine ) ) ;
        int thisNumr, thisWeight ;
        vector<int> thisPrev ;
        oneLineStrm >> thisNumr >> thisWeight ;
        int tmp4numr ;
        while ( oneLineStrm >> tmp4numr ) {
            thisPrev.push_back( tmp4numr ) ;
        }

        if ( thisPrev.empty() ) {
            Graph.insert( { thisNumr, { 0, thisWeight, -1, { { 0, thisWeight } }, {} } } ) ; // 注意：如果输入没有拓扑排序，则应该使用operator[]代替insert，否则修改prev时会隐式的添加元素导致后面插入失败
            Graph[0].next_m.push_back( { thisNumr, thisWeight } ) ;
        } else if ( thisPrev.size() == 1 ) {
            Graph.insert( { thisNumr, { 0, Graph[thisPrev.front()].early_m + thisWeight, -1, { { thisPrev.front(), thisWeight } }, {} } } ) ;
            Graph[thisPrev.front()].next_m.push_back( { thisNumr, thisWeight} ) ;
        } else {
            int thisDumNumr{ -thisNumr }, thisDumEarly{} ;
            Graph.insert( { thisDumNumr, { 0, 0, -1, {}, {} } } ) ;
            for ( int thisPrevNumr : thisPrev ) {
                Graph[thisDumNumr].prev_m.push_back( { thisPrevNumr, 0 } ) ;
                Graph[thisPrevNumr].next_m.push_back( { thisDumNumr, 0 } ) ;
                int thisPrevEarly{ Graph[thisPrevNumr].early_m } ;
                thisDumEarly = thisPrevEarly > thisDumEarly ? thisPrevEarly : thisDumEarly ; // 更新哑节点的early
            }
            Graph[thisDumNumr].early_m = thisDumEarly ;
            Graph.insert( { thisNumr, { 0, thisDumEarly + thisWeight, -1, { { thisDumNumr, thisWeight } }, {} } } ) ; // 插入哑节点的真身
            Graph[thisDumNumr].next_m.push_back( { thisNumr, thisWeight } ) ;
        }

        oneLineStrm.clear() ;
    }

    queue<int> queue4bfs ;
    Graph[numOfRealVertex].late_m = Graph[numOfRealVertex].early_m ;
    Graph[numOfRealVertex].isInQueue = true ;
    queue4bfs.push( numOfRealVertex ) ;
    while ( !queue4bfs.empty() ) {
        int thisNumr{ queue4bfs.front() } ;
        queue4bfs.pop() ;
        Graph[thisNumr].isInQueue = false ;
        if ( Graph[thisNumr].late_m - Graph[thisNumr].early_m == 0 ) {
            cout << thisNumr << endl ;
        }

        for ( auto& thisPrev : Graph[thisNumr].prev_m ) {
            int thisPrevNumr{ thisPrev.first } ;
            if ( Graph[thisPrevNumr].late_m == -1 ) {
                Graph[thisPrevNumr].late_m = Graph[thisNumr].late_m - thisPrev.second ;
                queue4bfs.push( thisPrevNumr ) ;
                Graph[thisPrevNumr].isInQueue = true ;
            } else if ( int thisLate{ Graph[thisNumr].late_m - thisPrev.second }; thisLate < Graph[thisPrevNumr].late_m ) {
                Graph[thisPrevNumr].late_m = thisLate ;
                if ( !Graph[thisPrevNumr].isInQueue ) {
                    queue4bfs.push( thisPrevNumr ) ;
                    Graph[thisPrevNumr].isInQueue = true ;
                }
            }
        }
    }

    return 0 ;
}
