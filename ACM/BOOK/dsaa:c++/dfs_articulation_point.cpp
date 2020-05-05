#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std ;

struct Vertex
{
    int num_m ;
    int low_m ;
    vector<size_t> adjList_m ;
} ;

vector<Vertex> Graph{} ;
int NowNum{} ;

int dfs(size_t prevIdx, size_t thisIdx)
{
    Graph[thisIdx].num_m = NowNum ;
    int thisLow{ NowNum++ } ;
    for ( size_t thisAdjIdx : Graph[thisIdx].adjList_m ) { // 均为known结束递归
        auto& thisAdjVertex{ Graph[thisAdjIdx] } ;
        if ( thisAdjVertex.num_m == -1 ) { // Unknown则为树边
            int retLow{ dfs( thisIdx, thisAdjIdx ) } ;
            thisLow = thisLow < retLow ? thisLow : retLow ;
            if ( retLow >= Graph[thisIdx].num_m ) {
                cout << thisIdx << endl ;
            }
        } else if ( thisAdjIdx != prevIdx ) { // 非树边
            int noTreeEageNum{ Graph[thisAdjIdx].num_m } ;
            thisLow = thisLow < noTreeEageNum ? thisLow : noTreeEageNum ;
        }
    }
    Graph[thisIdx].low_m = thisLow ;
    return thisLow ;
}

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    string oneLine ;
    istringstream oneLineStrem ;
    vector<size_t> tmp4adjList ;
    while ( getline( cin, oneLine ) ) {
        oneLineStrem.str(move(oneLine)) ;
        size_t tmp4adjIdx ;
        while ( oneLineStrem >> tmp4adjIdx ) {
            tmp4adjList.push_back(tmp4adjIdx) ;
        }
        Graph.push_back({ -1, -1, move(tmp4adjList) }) ;
        oneLineStrem.clear() ;
    }

    Graph[0].num_m = NowNum++ ;
    Graph[0].low_m = 0 ;
    int rootSubTreeNum{} ;
    for ( size_t thisAdjIdx : Graph[0].adjList_m ) {
        auto& thisAdjVertex{ Graph[thisAdjIdx] } ;
        if ( thisAdjVertex.num_m == -1 ) { // Unknown则为树边
            dfs( 0, thisAdjIdx ) ;
            ++rootSubTreeNum ;
        }
    }
    if ( rootSubTreeNum > 1 ) {
        cout << 0 << endl ;
    }

    return 0 ;
}
