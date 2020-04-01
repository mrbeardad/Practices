#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <unordered_map>

using namespace std ;

struct Vertex
{
    bool isInQueue_m ;
    int early_m ;
    int late_m = INT32_MAX ;
    vector<pair<int, int> > prev_m ;
    vector<pair<int, int> > next_m ;
} ;

bool dfs(int thisNumr, int targetNumr, unordered_map<int, Vertex>& graph, stack<int>& slackStack)
{
    auto& thisVertex{ graph[thisNumr] } ;
    int slackTime{ thisVertex.late_m - thisVertex.early_m } ;
    if ( slackTime != 0 ) {
        return false ;
    }
    slackStack.push( thisNumr ) ;
    if ( thisNumr == targetNumr ) {
        return true ;
    }
    for ( auto& thisAdj : thisVertex.next_m ) {
        if ( dfs( thisAdj.first, targetNumr, graph, slackStack ) ) {
            return true ;
        }
    }
    slackStack.pop() ;
    return false ;
}

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    unordered_map<int, Vertex> Graph ;
    Graph.insert( { 0, Vertex{} } ) ;

    string oneLine ;
    istringstream oneLineStrm ;
    int numOfRealVertex{} ;
    while ( getline( cin, oneLine ) ) { // 输入：权值，依赖节点(从1开始)
        ++numOfRealVertex ;
        oneLineStrm.str( oneLine ) ;
        int thisWeight ;
        vector<int> thisPrev ;
        oneLineStrm >> thisWeight ;
        for ( int tmp4prev{}; oneLineStrm >> tmp4prev; ) {
            thisPrev.push_back( tmp4prev ) ;
        }

        if ( thisPrev.empty() ) { // 连接到 0 节点
            Graph[numOfRealVertex].prev_m.push_back( { 0, thisWeight } ) ;
            Graph[0].next_m.push_back( { numOfRealVertex, thisWeight } ) ;
        } else if ( thisPrev.size() == 1 ) { // 连接到该 prev 节点
            Graph[numOfRealVertex].prev_m.push_back( { thisPrev[0], thisWeight } ) ;
            Graph[thisPrev[0]].next_m.push_back( { numOfRealVertex, thisWeight} ) ;
        } else { // 建立哑节点与哑边
            int thisDumNumr{ -numOfRealVertex } ;
            for ( int thisPrevNumr : thisPrev ) {
                Graph[thisDumNumr].prev_m.push_back( { thisPrevNumr, 0 } ) ;
                Graph[thisPrevNumr].next_m.push_back( { thisDumNumr, 0 } ) ;
            }
            Graph[numOfRealVertex].prev_m.push_back( { thisDumNumr, thisWeight } ) ;
            Graph[thisDumNumr].next_m.push_back( { numOfRealVertex, thisWeight } ) ;
        }
        oneLineStrm.clear() ;
    }

    queue<int> bfsQueue ;

    // 正向bfs最长路
    bfsQueue.push( 0 ) ;
    Graph[0].early_m = 0 ;
    Graph[0].isInQueue_m = true ;
    while ( bfsQueue.size() ) {
        int thisNumr{ bfsQueue.front() } ;
        auto& thisVertex{ Graph[thisNumr] } ;
        thisVertex.isInQueue_m = false ;
        bfsQueue.pop() ;
        for ( auto& thisNext : thisVertex.next_m ) {
            auto& thisNextAdj{ Graph[thisNext.first] } ;
            int thisEarly{ thisVertex.early_m + thisNext.second } ;
            if ( thisEarly > thisNextAdj.early_m ) {
                thisNextAdj.early_m = thisEarly ;
                if ( !thisNextAdj.isInQueue_m ) {
                    bfsQueue.push( thisNext.first ) ;
                    thisNextAdj.isInQueue_m = true ;
                }
            }
        }
    }

    // 反向bfs最短路
    Graph[numOfRealVertex].late_m = Graph[numOfRealVertex].early_m ;
    Graph[numOfRealVertex].isInQueue_m = true ;
    bfsQueue.push( numOfRealVertex ) ;
    while ( bfsQueue.size() ) {
        int thisNumr{ bfsQueue.front() } ;
        auto& thisVertex{ Graph[thisNumr] } ;
        Graph[thisNumr].isInQueue_m = false ;
        bfsQueue.pop() ;
        for ( auto& thisPrev : Graph[thisNumr].prev_m ) {
            auto& thisPrevAdj{ Graph[thisPrev.first] } ;
            int thisLate{ thisVertex.late_m - thisPrev.second } ;
            if ( thisLate < thisPrevAdj.late_m ) {
                thisPrevAdj.late_m = thisLate ;
                if ( !thisPrevAdj.isInQueue_m ) {
                    bfsQueue.push( thisPrev.first ) ;
                    thisPrevAdj.isInQueue_m = true ;
                }
            }
        }
    }

    stack<int> slackStack ;
    dfs( 0, numOfRealVertex, Graph, slackStack ) ;
    for ( int criticalNumr{}; slackStack.size();  ) {
        criticalNumr = slackStack.top() ;
        slackStack.pop() ;
        if ( criticalNumr >= 0 ) {
            cout << criticalNumr << ' ' ;
        }
    }

    return 0 ;
}
