#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std ;

array<array<unordered_multimap<string, string>, 20>, 20> LenPosMapWords ;

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    string target ;
    cin >> target ;
    for ( string tmp{}; cin >> tmp; ) {
        size_t lenth{ tmp.size() } ;
        for ( size_t pos{ 0 }; pos < lenth; ++pos ) { // 顺序删除位置上的字母形成代表
            string repres{ tmp, 0, pos } ; // 此处可以减少一次拷贝
            repres.append( tmp, pos + 1, lenth - pos -1 ) ;
            LenPosMapWords[lenth][pos].insert(pair{ move(repres), tmp }) ;
        }
    }

    size_t pos2erase{} ;
    string targetRepres ;
    for ( auto &posMap : LenPosMapWords[target.length()] ) {
        if ( pos2erase >= target.length() ) {
            break ;
        }
        targetRepres = target ;
        targetRepres.erase( pos2erase, 1 ) ;
        auto ret{ posMap.equal_range(targetRepres) } ;
        for ( auto pos{ ret.first }; pos != ret.second; ++pos ) {
            if ( pos->second != target ) { // target自己的副本会出现在多个位置对代表中，而其他单词只有删除了那个不同的字母才可能形成相同代表
            cout << pos->second << ' ' ;
            }
        }
        ++pos2erase ;
    }


    return 0 ;
}
