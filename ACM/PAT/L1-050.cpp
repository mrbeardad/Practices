#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int len, nth ;
    cin >> len >> nth ;
    while ( len ) {
        int thisNumr{}, thisPow{ (int)pow( 26, --len ) }  ;
        if ( nth % thisPow == 0 ) { // 边界条件，左开右闭
            thisNumr = nth / thisPow  - 1 ;
            } else {
            thisNumr = nth / thisPow ;
            }
        cout << (char)('z' - thisNumr) ;
        nth -= thisNumr * thisPow ;
    }

    return 0 ;
}

