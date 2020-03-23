#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <utility>

using namespace std ;

struct GraphNode
{
    int dist_m ;
    size_t path_m ;
    bool isEnqueue_m ;
    vector<pair<size_t, int>> adjNodes_m ; // idx and weight
} ;

constexpr size_t BEGIN{ 0 } ;
constexpr size_t END{ 5 } ;

vector<GraphNode> Graph2bfs ;

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    string oneLine{} ;
    istringstream oneLineStrm{} ;
    vector<pair<size_t, int>> tmpAdjNodes{} ;
    size_t tmpIdx{}, tmpWeight{} ;
    while ( getline( cin, oneLine ) ) {
        oneLineStrm.str(move(oneLine)) ;
        while ( oneLineStrm >> tmpIdx >> tmpWeight ) {
            tmpAdjNodes.push_back(pair{ tmpIdx, tmpWeight }) ;
        }
        Graph2bfs.push_back({ -1, 0, 0, move(tmpAdjNodes) }) ;
        oneLineStrm.clear() ;
    }

    queue<size_t> bfsQueue{} ;
    bfsQueue.push(BEGIN) ;
    Graph2bfs[BEGIN].dist_m = 0 ;
    while ( !bfsQueue.empty() ) {
        auto& thisNodeIdx{ bfsQueue.front() } ;
        auto& thisNode{ Graph2bfs[thisNodeIdx] } ;
        for ( auto& thisAdjInVec : thisNode.adjNodes_m ) { // 遍历获取pair<size_t(idx), int(dist)>
            auto& thisAdjInGraph{ Graph2bfs[thisAdjInVec.first] } ; // 引用Grapu2bfs中的Node
            if ( thisAdjInGraph.dist_m == -1 ) {
                thisAdjInGraph.dist_m = thisNode.dist_m + thisAdjInVec.second ;
                thisAdjInGraph.path_m = thisNodeIdx ;
                thisAdjInGraph.isEnqueue_m = 1 ;
                bfsQueue.push(thisAdjInVec.first) ;
            } else if ( int thisDist{ thisNode.dist_m + thisAdjInVec.second }; thisAdjInGraph.dist_m > thisDist ) {
                thisAdjInGraph.dist_m = thisDist ;
                thisAdjInGraph.path_m = thisNodeIdx ;
                if ( !thisAdjInGraph.isEnqueue_m ) {  // 判断该邻节点是否已在队中
                    thisAdjInGraph.isEnqueue_m = 1 ;
                    bfsQueue.push(thisAdjInVec.first) ;
                }
            }
        }
        bfsQueue.pop() ;
    }

    int distance{} ;
    for ( auto prevPath{ END }; prevPath != BEGIN; prevPath = Graph2bfs[prevPath].path_m ) {
        cout << prevPath << ' ' ;
    }
    cout << BEGIN << '\n' << Graph2bfs[END].dist_m << endl ;

    return 0 ;
}
