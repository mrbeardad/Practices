#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int intN, sqrtN ;
    cin >> intN ;
    sqrtN = (int)sqrt( intN ) ;

    int maxStart{ 1 }, maxLenth{ 0 } ; // maxLenth应该为0，让长度为1的因子也被记录
    for ( int startNum{ 2 }; startNum <= sqrtN; ++startNum ) {
        int nowProd{ startNum }, nowStart{ startNum } ;
        while ( nowStart <= sqrtN + 1 && intN % nowProd == 0 ) {
            nowProd *= ++nowStart ;
        }
        int nowLenth{ nowStart - startNum } ;
        if ( nowLenth > maxLenth ) {
            maxLenth = nowLenth ;
            maxStart = startNum ;
        }
    }

    if ( maxStart == 1 ) {
        cout << 1 << '\n' << intN ;
    } else {
        cout << maxLenth-- << '\n' ;
        cout << maxStart++ ;
        for ( int i{}; i < maxLenth; ++i ) {
            cout << '*' << maxStart++ ;
        }
    }

    return 0 ;
}
