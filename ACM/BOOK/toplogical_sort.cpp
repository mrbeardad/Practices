#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std ;

struct Graph2sort
{
    vector<size_t> adjNodes_m ;
    int numr_m ;
    int indegree_m ;
} ;

vector<Graph2sort> toplogicalSort(vector<Graph2sort>& needSort)
{
    vector<Graph2sort> ret ;
    queue<Graph2sort> indegree0 ;
    for ( auto pos{ needSort.begin() }, end{ needSort.end() }; pos != end; ++pos ) { // 先将indegree==0的元素入队
        if ( pos->indegree_m == 0 ) {
            indegree0.push(*pos) ;
        }
    }

    while ( !indegree0.empty() ) {
        auto& thisNode{ indegree0.front() } ;
        ret.push_back(thisNode) ;
        for ( auto idx : thisNode.adjNodes_m ) {
            if ( idx >= needSort.size() ) {
                cout << "What are you fucking inputing?! Index " << idx << " is not exsit!" << endl ;
                continue ;
            }
            if ( --needSort[idx].indegree_m == 0 ) { // 如果目标不存(输入有病)就会segmentfault
                indegree0.push(needSort[idx]) ;
            }
        }
        indegree0.pop() ;
    }
    return ret ;
}

vector<Graph2sort> Source ;
vector<Graph2sort> Target ;
unordered_map<size_t, int> SourceIndegree ;

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    string oneLine ;
    istringstream oneLineStrm ;
    vector<size_t> oneLineAdj ;
    int thisNumr{} ;
    while ( getline(cin, oneLine) ) {
        oneLineStrm.str(move(oneLine)) ;
        size_t tmp ;
        while ( oneLineStrm >> tmp ) { // 读取一个节点的数据，更新SourceIndegree和Source
            oneLineAdj.push_back(tmp) ;
            ++SourceIndegree[tmp] ;
        }
        Source.push_back(Graph2sort{ move(oneLineAdj), thisNumr++, 0 }) ;
        oneLineStrm.clear() ; // .str(string)并不会刷新缓冲区
    }
    for ( size_t idx{}, end{Source.size()}; idx < end; ++idx ) {
        Source[idx].indegree_m = SourceIndegree[idx] ;
    }

    Target = toplogicalSort(Source) ;
    for ( size_t idx{}, end{ Target.size() }; idx < end; ++idx ) {
        cout << Target[idx].numr_m << ' '  << endl ;
    }

    return 0 ;
}
