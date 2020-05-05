#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std ;

struct Vertex
{
    bool isKnown_m ;
    vector<size_t> adjList_m ;
} ;

vector<Vertex> Graph{} ;
deque<size_t> PathStack{} ;

void dfs(size_t thisIdx)
{
    Graph[thisIdx].isKnown_m = true ;
    PathStack.push_back(thisIdx) ;
    for ( size_t thisAdjIdx : Graph[thisIdx].adjList_m ) { // 基准情况：Graph[thisIdx]的adjList为空或者全为非树边
        if ( Graph[thisAdjIdx].isKnown_m ) {
            auto end{ PathStack.end() } ;
            auto findPos{ find( PathStack.begin(), end, thisAdjIdx ) } ;
            if ( findPos != end ) { // 在栈中则指向该adj的边为背向边
                cout << "cyclic: " << thisIdx ;
                for_each( findPos, end, [](size_t t){cout << '-' << t;} ) ;
                cout << '\n' ;
            } // 否则为前向边或者交叉边
        } else {
            dfs(thisAdjIdx) ;
        }
    }
    PathStack.pop_back() ;
}

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    string oneLine ;
    istringstream oneLineStrm ;
    vector<size_t> tmp4adjList ;
    while ( getline( cin, oneLine ) ) {
        oneLineStrm.str(move(oneLine)) ;
        size_t tmp4idx ;
        while ( oneLineStrm >> tmp4idx ) {
            tmp4adjList.push_back(tmp4idx) ;
        }
        Graph.push_back({ false, move(tmp4adjList) }) ;
        oneLineStrm.clear() ;
    }

    auto dfsTreeRootPos{ Graph.begin() } ;
    auto end{ Graph.end() } ;
    int iter2idx{} ;
    do {
        dfs(iter2idx) ;
        dfsTreeRootPos = find_if( ++dfsTreeRootPos, end,
            [&iter2idx] (Vertex& v) {
                ++iter2idx ;
                return !v.isKnown_m;
            } ) ;
    } while ( dfsTreeRootPos != end ) ;

    return 0 ;
}
