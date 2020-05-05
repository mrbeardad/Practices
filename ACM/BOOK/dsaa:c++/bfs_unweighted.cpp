#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std ;

struct Vertex
{
    int dist_m ;
    size_t path_m ;
    vector<size_t> adjList_m ;
} ;

constexpr size_t SOURCE{ 1 } ;
constexpr size_t TARGET{ 7 } ;

int main()
{
    ios::sync_with_stdio( false ) ;
    cin.tie( nullptr ) ;

    vector<Vertex> Graph ;

    string oneLine ;
    istringstream oneLineStrm ;
    vector<size_t> tmp4Adj ;
    while ( getline( cin, oneLine ) ) {
        oneLineStrm.str( move( oneLine ) ) ;
        size_t tmp4Idx ;
        while ( oneLineStrm >> tmp4Idx ) {
            tmp4Adj.push_back( tmp4Idx ) ;
        }
        Graph.push_back( { -1, SOURCE, move( tmp4Adj ) } ) ;
        oneLineStrm.clear() ;
    }

    queue<size_t> bfsQueue ;
    bfsQueue.push( SOURCE ) ;
    int nowDist{} ;
    Graph[SOURCE].dist_m = nowDist ;
    while ( bfsQueue.size() ) {
        ++nowDist ;
        size_t thisVertexIdx{ bfsQueue.front() } ;
        auto& thisVertex{ Graph[thisVertexIdx] } ;
        bfsQueue.pop() ;
        for ( auto& thisAdjIdx : thisVertex.adjList_m ) {
            if ( Graph[thisAdjIdx].dist_m == -1 ) {
                Graph[thisAdjIdx].dist_m = nowDist ;
                Graph[thisAdjIdx].path_m = thisVertexIdx ;
                bfsQueue.push( thisAdjIdx ) ;
            }
        }
    }

    for ( size_t path2Source{ TARGET }; path2Source != SOURCE; path2Source = Graph[path2Source].path_m ) {
        cout << path2Source << ' ' ;
    }
    cout << SOURCE << "\nDistance: " << Graph[TARGET].dist_m ;

    return 0 ;
}
