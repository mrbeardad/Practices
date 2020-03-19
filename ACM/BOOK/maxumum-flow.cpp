#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include <utility>

using namespace std ;

struct GraphVertex
{
    size_t maxPath_m ;
    int nthVisit ;
    unordered_map<size_t, int> flowAdjList_m ;
    unordered_map<size_t, int> resAdjList_m ;
} ;

constexpr size_t SOURCE{ 0 } ;
constexpr size_t TARGET{ 5 } ;
vector<GraphVertex> Graph{} ;

int selectPath( int nthVisit, size_t thisIdx )
{
    if ( thisIdx == TARGET ) {
        return INT32_MAX ;
    } else if ( Graph[thisIdx].resAdjList_m.size() == 0 || Graph[thisIdx].nthVisit == nthVisit ) {
        return 0 ;
    }

    Graph[thisIdx].nthVisit = nthVisit ;
    int maxFlow{} ;
    size_t maxPath{} ;
    for ( auto& thisAdj : Graph[thisIdx].resAdjList_m ) {
        if ( thisAdj.second == 0 ) { // 残余流量为0则代表此路不通
            continue ;
        }
        int thisFlow{ selectPath( nthVisit, thisAdj.first ) } ;
        thisFlow = thisFlow < thisAdj.second ? thisFlow : thisAdj.second ;
        if ( thisFlow > maxFlow ) {
            maxFlow = thisFlow ;
            maxPath = thisAdj.first ;
        }
    }
    Graph[thisIdx].maxPath_m = maxPath ;
    return maxFlow ;
}

void computeFlow()
{
    size_t end{ Graph.size() } ;
    for ( size_t idx{}; idx < end; ++idx ){
        auto& thisVertex{ Graph[idx] } ;
        for ( auto& thisAdj : thisVertex.flowAdjList_m ) {
            thisAdj.second = Graph[thisAdj.first].resAdjList_m[idx] ;
        }
    }
}

int maxFlow()
{
    for ( int thisPathFlow{}, nthVisit{ 1 }; thisPathFlow = selectPath( nthVisit, SOURCE ); ++nthVisit ) {
        for ( size_t idx{SOURCE}; idx != TARGET; idx = Graph[idx].maxPath_m ) {
            auto& thisVertex{ Graph[idx] } ;
            thisVertex.resAdjList_m[thisVertex.maxPath_m] -= thisPathFlow ;
            Graph[thisVertex.maxPath_m].resAdjList_m[idx] += thisPathFlow ;
        }
    }

    computeFlow() ;

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

    string oneLine{} ;
    istringstream oneLineStrm{} ;
    unordered_map<size_t, int> tmpflowAdjList{} ;
    unordered_map<size_t, int> tmpresAdjList_m{} ;
    while ( getline( cin, oneLine ) ) {
        oneLineStrm.str(move(oneLine)) ;
        size_t tmpIdx{} ;
        int tmpCap{} ;
        while ( oneLineStrm >> tmpIdx >> tmpCap ) {
            tmpflowAdjList[tmpIdx] = 0 ;
            tmpresAdjList_m[tmpIdx] = tmpCap ;
        }
        Graph.push_back(GraphVertex{ 0, 0, move(tmpflowAdjList), move(tmpresAdjList_m) }) ;
        oneLineStrm.clear() ;
    }
    cout << maxFlow() << endl ;
    for ( auto& thisVertex : Graph ) {
        for ( auto& thisAdj : thisVertex.flowAdjList_m ) {
            cout << thisAdj.first << ' ' << thisAdj.second << "\t\t" ;
        }
        cout << endl ;
    }

    return 0 ;
}
