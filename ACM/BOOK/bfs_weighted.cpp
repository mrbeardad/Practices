#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <utility>

using namespace std ;

struct Vertex
{
    int dist_m ;
    size_t path_m ;
    bool isInQueue_m ;
    vector<pair<size_t, int> > adjList_m ;
} ;

constexpr size_t SOURCE{ 1 } ;
constexpr size_t TARGET{ 6 } ;


int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<Vertex> Graph ;
    string oneLine ;
    istringstream oneLineStrm ;
    vector<pair<size_t, int> > tmp4Adj ;
    size_t tmpIdx, tmpWeight ;
    while ( getline( cin, oneLine ) ) {
        oneLineStrm.str( move( oneLine ) ) ;
        while ( oneLineStrm >> tmpIdx >> tmpWeight ) {
            tmp4Adj.push_back( { tmpIdx, tmpWeight } ) ;
        }
        Graph.push_back( { INT32_MAX, SOURCE, false, move( tmp4Adj ) } ) ;
        oneLineStrm.clear() ;
    }

    queue<size_t> bfsQueue ;
    bfsQueue.push( SOURCE ) ;
    Graph[SOURCE].dist_m = 0 ;
    Graph[SOURCE].isInQueue_m = true ;
    while ( bfsQueue.size() ) {
        auto& thisVertexIdx{ bfsQueue.front() } ;
        auto& thisVertex{ Graph[thisVertexIdx] } ;
        bfsQueue.pop() ;
        thisVertex.isInQueue_m = false ;
        for ( auto& thisAdj : thisVertex.adjList_m ) {
            int thisDist{ thisVertex.dist_m + thisAdj.second } ;
            auto& thisAdjVertex{ Graph[thisAdj.first] } ;
            if ( thisDist < thisAdjVertex.dist_m ) {
                thisAdjVertex.dist_m = thisDist ;
                thisAdjVertex.path_m = thisVertexIdx ;
                if ( !thisAdjVertex.isInQueue_m ) {
                    bfsQueue.push( thisAdj.first ) ;
                    thisAdjVertex.isInQueue_m = true ;
                }
            }
        }
    }

    for ( auto path2Target{ TARGET }; path2Target != SOURCE; path2Target = Graph[path2Target].path_m ) {
        cout << path2Target << ' ' ;
    }
    cout << SOURCE << "\nDistance: " << Graph[TARGET].dist_m << endl ;

    return 0 ;
}
