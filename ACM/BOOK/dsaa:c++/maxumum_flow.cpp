#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include <utility>
#include <queue>

using namespace std ;

struct Vertex
{
    size_t path_m ;
    int pathFlow_m ;
    int nthVisit_m ;
    unordered_map<size_t, int> flowAdjList_m ;
    unordered_map<size_t, int> resAdjList_m ;
} ;

constexpr size_t SOURCE{ 0 } ;
constexpr size_t TARGET{ 5 } ;
vector<Vertex> Graph{} ;
queue<size_t> bfsQueue{} ;

void selectPath( int nthVisit )
{
    Graph[SOURCE].nthVisit_m = nthVisit ;
    bfsQueue.push( SOURCE ) ;
    while ( bfsQueue.size() ) {
        size_t thisVertexIdx{ bfsQueue.front() } ;
        auto& thisVertex{ Graph[thisVertexIdx] } ;
        bfsQueue.pop() ;
        for ( auto& thisAdj : thisVertex.resAdjList_m ) {
            auto& thisAdjVertex{ Graph[thisAdj.first] } ;
            if ( thisAdjVertex.nthVisit_m < nthVisit && thisAdj.second ) {
                thisAdjVertex.nthVisit_m = nthVisit ;
                thisAdjVertex.path_m = thisVertexIdx ;
                int prevFlow{ thisVertex.pathFlow_m }, thisFlow{ thisAdj.second } ;
                thisAdjVertex.pathFlow_m = prevFlow < thisFlow ? prevFlow : thisFlow ;
                bfsQueue.push( thisAdj.first ) ;
            }
        }
    }
}

int maxFlow()
{
    Graph[SOURCE].pathFlow_m = INT32_MAX ;
    int nthVisit{ 1 } ;
    selectPath( nthVisit ) ;
    while ( Graph[TARGET].nthVisit_m == nthVisit ) {
        for ( size_t idx{TARGET}; idx != SOURCE; idx = Graph[idx].path_m ) {
            auto& thisVertex{ Graph[idx] } ;
            int pathFlow{ Graph[TARGET].pathFlow_m } ;
            thisVertex.resAdjList_m[thisVertex.path_m] += pathFlow ;
            Graph[thisVertex.path_m].resAdjList_m[idx] -= pathFlow ;
        }
        ++nthVisit ;
        selectPath( nthVisit ) ;
    }

    for ( size_t idx{}, end{ Graph.size() }; idx < end; ++idx ) {
        auto& thisVertex{ Graph[idx] } ;
        for ( auto& thisAdj : thisVertex.flowAdjList_m ) {
            auto& point2this{ Graph[thisAdj.first] } ;
            if ( point2this.flowAdjList_m.find( idx ) != point2this.flowAdjList_m.end() ) {
                thisAdj.second = point2this.resAdjList_m[idx] - point2this.flowAdjList_m[idx] ;
            } else {
                thisAdj.second = point2this.resAdjList_m[idx] ;
            }
        }
    }

    int maxFlow{} ;
    for ( auto& eachAdj : Graph[TARGET].resAdjList_m ) {
        maxFlow += eachAdj.second ;
    }
    return maxFlow ;
}

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    string oneLine ;
    istringstream oneLineStrm ;
    unordered_map<size_t, int> tmpresAdjList ;
    unordered_map<size_t, int> tmpflowAdjList ;
    while ( getline( cin, oneLine ) ) {
        oneLineStrm.str( move( oneLine ) ) ;
        size_t tmpIdx{} ;
        int tmpCap{} ;
        while ( oneLineStrm >> tmpIdx >> tmpCap ) {
            tmpresAdjList[tmpIdx] = tmpCap ;
            tmpflowAdjList[tmpIdx] = tmpCap ;
        }
        Graph.push_back( Vertex{ 0, 0, 0, move( tmpflowAdjList ), move( tmpresAdjList ) } ) ;
        oneLineStrm.clear() ;
    }
    cout << maxFlow() << endl ;
    for ( size_t idx{}, end{ Graph.size() }; idx < end; ++idx ) {
        cout << idx << ": " ;
        auto& thisVertex{ Graph[idx] } ;
        for ( auto& thisAdj : thisVertex.flowAdjList_m ) {
            cout << thisAdj.first << ' ' << thisAdj.second << "\t\t" ;
        }
        cout << endl ;
    }

    return 0 ;
}
