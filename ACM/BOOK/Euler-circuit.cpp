#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <string>

using namespace std ;

struct Vertex
{
    unordered_set<size_t> adjList_m ;
} ;

vector<Vertex> Graph{} ;
list<size_t> Result{} ;

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    string oneLine ;
    istringstream oneLineStrm ;
    unordered_set<size_t> tmp4adjList ;
    while ( getline( cin, oneLine ) ) {
        oneLineStrm.str(move(oneLine)) ;
        size_t tmp4adjIdx ;
        while ( oneLineStrm >> tmp4adjIdx ) {
            tmp4adjList.insert(tmp4adjIdx) ;
        }
        Graph.push_back({ move(tmp4adjList) }) ;
        oneLineStrm.clear() ;
    }

    size_t begin{ 5 } ;
    Result.push_back(begin) ;
    auto pos2insert{ Result.begin() } ;
    while ( true ) {
        for ( size_t idx{ begin }; Graph[idx].adjList_m.size() != 0; ) {
            Result.insert( pos2insert, idx ) ;
            size_t tmp4idx = *Graph[idx].adjList_m.begin() ;
            Graph[idx].adjList_m.erase(tmp4idx) ;
            Graph[tmp4idx].adjList_m.erase(idx) ;
            idx = tmp4idx ;
        }
        while ( !Graph[*--pos2insert].adjList_m.size() ) {
            if ( pos2insert == Result.begin() ) { // 防止到头时仍继续迭代
                break ;
            }
        }
        if ( pos2insert == Result.begin() ) { // 结束循环
            break ;
        }
        begin = *pos2insert ;
    }

    for ( size_t thisIdx : Result ) {
        cout << thisIdx << ' ' ;
    }
    cout << endl ;

    return 0 ;
}
