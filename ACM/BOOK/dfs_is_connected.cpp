#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std ;

struct Vertex
{
    bool isVisited ;
    vector<size_t> adjList ;
} ;

vector<Vertex> Graph ;

void dfs(size_t thisIdx)
{
    if ( Graph[thisIdx].isVisited ) {
        return ;
    }
    Graph[thisIdx].isVisited = true ;
    for ( size_t thisAdjIdx : Graph[thisIdx].adjList ) {
        dfs(thisAdjIdx) ;
    }
}

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    string oneLine ;
    istringstream oneLineStrm ;
    vector<size_t> tmp4adjList ;
    while( getline( cin, oneLine ) ) {
        oneLineStrm.str(move(oneLine)) ;
        size_t tmp4adjIdx ;
        while ( oneLineStrm >> tmp4adjIdx ) {
            tmp4adjList.push_back(tmp4adjIdx) ;
        }
        Graph.push_back({ false, move(tmp4adjList) }) ;
        oneLineStrm.clear() ;
    }

    dfs(0) ;
    for ( auto& thisVertex : Graph ) {
        if ( !thisVertex.isVisited ) {
            cout << "Not Connected!" << endl ;
            return 0 ;
        }
    }
    cout << "Is Connected!" << endl ;

    return 0 ;
}
