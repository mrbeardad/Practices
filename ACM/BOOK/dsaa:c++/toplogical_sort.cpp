#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std ;

struct Vertex
{
    int numr_m ;
    vector<size_t> adjList_m ;
} ;

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<Vertex> source ;
    vector<Vertex> target ;
    unordered_map<size_t, int> indegree ;
    queue<size_t> idg0 ;

    string oneLine ;
    istringstream oneLineStrm ;
    vector<size_t> tmp4Adj ;
    for ( int thisNumr{ 1 }; getline( cin, oneLine ); ++thisNumr ) {
        oneLineStrm.str( move( oneLine ) ) ;
        for ( size_t tmp4idx{}; oneLineStrm >> tmp4idx; ) {
            tmp4Adj.push_back( tmp4idx ) ;
            ++indegree[tmp4idx] ;
        }
        source.push_back( { thisNumr, move( tmp4Adj ) } ) ;
        oneLineStrm.clear() ;
    }

    auto idgEnd{ indegree.end() } ;
    for ( size_t idx{}, end{ source.size() }; idx < end; ++idx ) {
        if ( indegree.find( idx ) == idgEnd ) {
            idg0.push( idx ) ;
        }
    }

    while ( idg0.size() ) {
        auto& thisVt{ source[idg0.front()] } ;
        target.push_back( thisVt ) ;
        idg0.pop() ;
        for ( size_t thisAdjIdx : thisVt.adjList_m ) {
            if ( --indegree[thisAdjIdx] == 0 ) {
                idg0.push( thisAdjIdx ) ;
            }
        }
    }

    for ( auto& thisVt : target ) {
        cout << ' ' << thisVt.numr_m ;
    }

    return 0 ;
}
