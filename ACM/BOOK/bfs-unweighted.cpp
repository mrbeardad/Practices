#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std ;

struct GraphNode
{
    int dist_m ;
    size_t path_m ;
    vector<size_t> adjNodes_m ;
} ;

constexpr size_t BEGIN{ 0 } ;
constexpr size_t END{ 7 } ;
vector<GraphNode> Graph2bfs{} ;

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    string oneLine{} ;
    istringstream oneLineStrm{} ;
    vector<size_t> tmp2push{} ;
    while ( getline( cin, oneLine ) ) {
        oneLineStrm.str(move(oneLine)) ;
        size_t tmp ;
        while ( oneLineStrm >> tmp ) {
            tmp2push.push_back(tmp) ;
        }
        Graph2bfs.push_back({ -1, 0, move(tmp2push) }) ;
        oneLineStrm.clear() ;
    }

    queue<size_t> bfsQueue ;
    bfsQueue.push(BEGIN) ;
    int nowDist{} ;
    Graph2bfs[BEGIN].dist_m = nowDist ;
    while ( !bfsQueue.empty() ) {
        ++nowDist ;
        auto& needProc{ Graph2bfs[bfsQueue.front()] } ;
        for ( auto& adj : needProc.adjNodes_m ) {
            if ( Graph2bfs[adj].dist_m != -1 ) {
                continue ;
            }
            Graph2bfs[adj].dist_m = nowDist ;
            Graph2bfs[adj].path_m = bfsQueue.front() ;
            bfsQueue.push(adj) ;
        }
        bfsQueue.pop() ;
    }

    cout << "fuck!" << endl ;
    for ( size_t path2prev{ END }; path2prev != BEGIN; path2prev = Graph2bfs[path2prev].path_m ) {
        cout << path2prev << ' ' ;
    }
    cout << BEGIN << endl ;

    return 0 ;
}
