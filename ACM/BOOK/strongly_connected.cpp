#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <utility>

using namespace std ;

struct Vertex
{
    int numr_m ;
    vector<size_t> adjList_m ;
    vector<size_t> revAdjList_m ;
} ;

vector<Vertex> Graph{} ;
map<int, size_t> MaxNumrAtEnd{} ; // 排序按numr，搜索按idx
vector<vector<size_t>> StrongBranch{} ;
int NowNumr{} ;

void dfs2numr(size_t thisIdx)
{
    Graph[thisIdx].numr_m = 0 ;
    for ( size_t thisAdjIdx : Graph[thisIdx].adjList_m ) {
        Graph[thisAdjIdx].revAdjList_m.push_back(thisIdx) ;
        if ( Graph[thisAdjIdx].numr_m < 0 ) {
            dfs2numr(thisAdjIdx) ;
        }
    }
    Graph[thisIdx].numr_m = NowNumr ;
    MaxNumrAtEnd.insert({ NowNumr++, thisIdx }) ;
}

void dfs2branch(size_t thisIdx) // 需要提前设置好StrongBranch中的空位
{
    StrongBranch.back().push_back(thisIdx) ;
    MaxNumrAtEnd.erase(Graph[thisIdx].numr_m) ;
    Graph[thisIdx].numr_m = -1 ; // 在dfs2numr中已全部设置为true，则此时true代表unknown
    for ( size_t thisAdjIdx : Graph[thisIdx].revAdjList_m ) {
        if ( Graph[thisAdjIdx].numr_m >= 0 ) {
            dfs2branch(thisAdjIdx) ;
        }
    }
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
        int tmp4adjIdx ;
        while ( oneLineStrm >> tmp4adjIdx ) {
            tmp4adjList.push_back(tmp4adjIdx) ;
        }
        Graph.push_back({ -1, move(tmp4adjList), {} }) ;
        oneLineStrm.clear() ;
    }

    for ( size_t idx{}, end{ Graph.size() }; idx < end; ++idx ) {
        auto& thisVertex{ Graph[idx] } ;
        if ( thisVertex.numr_m < 0 ) {
            dfs2numr(idx) ;
        }
    }

    while ( !MaxNumrAtEnd.empty() ) {
        StrongBranch.push_back({}) ;
        dfs2branch((--MaxNumrAtEnd.end())->second) ;
    }

    for ( auto& thisBranch : StrongBranch ) {
        for ( int numrInBranch : thisBranch ) {
            cout << numrInBranch << ' ' ;
        }
        cout << endl ;
    }

    return 0 ;
}
