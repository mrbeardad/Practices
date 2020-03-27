#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    int intN, num, maxnum ;
    char chart ;
    cin >> intN >> chart ;
    if ( intN ) {
        num = sqrt( 2 + 2 * intN ) / 2 - 1 ;
    } else {
        num = 0 ;
    }
    maxnum = 2 * num + 1 ;

    int spaceNum{} ;
    for ( int nowNum{ maxnum }; nowNum > 0; nowNum -= 2, ++spaceNum ) {
        for (int i = 0; i < spaceNum; ++i) {
            cout << ' ' ;
        }
        for (int i = 0; i < nowNum; ++i) {
            cout << chart ;
        }
        cout << '\n' ;
    }
    spaceNum -= 2 ;
    for ( int nowNum{ 3 }; nowNum <= maxnum; nowNum += 2, --spaceNum ) {
        for (int i = 0; i < spaceNum; ++i) {
            cout << ' ' ;
        }
        for (int i = 0; i < nowNum; ++i) {
            cout << chart ;
        }
        cout << '\n' ;
    }
    cout << intN - (3 + maxnum) * num - 1 ;

    return 0 ;
}
