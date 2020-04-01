#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std ;

array<array<unordered_multimap<string, string>, 20>, 20> LenPosMapWords ;

int main()
{
    ios::sync_with_stdio( false ) ;
    cin.tie( nullptr ) ;

    fstream input{ "/tmp/words_representitive.input", ios::in } ;
    for ( string tmp{}, rep{}; input >> tmp; ) {
        size_t lenth{ tmp.size() } ;
        for ( size_t pos{ 0 }; pos < lenth; ++pos ) {
            rep = tmp ;
            rep.erase( pos ) ;
            LenPosMapWords[lenth - 1][pos].insert( pair{ move(rep), tmp } ) ; // 单词长度最短为1
        }
    }

    string target, targetRep ;
    while ( cin >> target ) {
        auto& thisLen{ LenPosMapWords[target.size() - 1] } ;
        for ( size_t idx{}, end{ target.size() }; idx < end; ++idx ) {
            targetRep = target ;
            targetRep.erase( idx ) ;
            auto iterPair{ thisLen[idx].equal_range(targetRep) } ;
            auto& pos{ iterPair.first } ;
            while ( pos != iterPair.second ) {
                if ( pos->second != target ) { // target自己的副本会出现在多个位置对代表中，而其他单词只有删除了那个不同的字母才可能形成相同代表
                    cout << pos->second << ' ' ;
                }
                ++iterPair.first ;
            }
        }
    }

    return 0 ;
}
