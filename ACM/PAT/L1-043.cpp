#include <iostream>
#include <unordered_map>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    unordered_map<int, int> dataInOneDay ;
    int numJie{}, timeLen{} ;
    int dayNum ;
    cin >> dayNum ;
    while ( dayNum ) {
        int bookNumr ;
        cin >> bookNumr ;
        if ( bookNumr == 0 ) {
            if ( numJie == 0 ) {
                cout << "0 0\n" ;
            } else {
                double avgTime{ (double)timeLen / numJie + 0.5 } ;
                cout << numJie << ' ' << (int)avgTime << '\n' ;
            }
            --dayNum ;
            numJie = 0 ;
            timeLen = 0 ;
            dataInOneDay.clear() ;
            cin.ignore( 9, '\n' ) ;
            continue ;
        }
        char isSorE ;
        cin.ignore() ;
        isSorE = cin.get() ;
        int nowHour, nowTime ;
        cin >> nowHour ;
        cin.ignore() ;
        cin >> nowTime ;
        nowTime = nowHour * 60 + nowTime ;
        if ( isSorE == 'S' ) {
            dataInOneDay[bookNumr] = nowTime ;
        } else {
            auto findS{ dataInOneDay.find( bookNumr ) } ;
            if ( findS != dataInOneDay.end() ) {
                ++numJie ;
                timeLen += nowTime - findS->second ;
                dataInOneDay.erase( findS ) ;
            }
        }
    }

    return 0 ;
}

