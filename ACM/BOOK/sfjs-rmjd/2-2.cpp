#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    for ( int high2{ 1100 }; high2 <= 9900; high2 += 1100 ) {
        for ( int low2{ 0 }; low2 <= 99; low2 += 11 ) {
            int rlt{ high2 + low2 } ;
            int sqrtRlt = sqrt( rlt ) ;
            if ( sqrtRlt * sqrtRlt == rlt ) {
                cout << rlt << '\n' ;
            }
        }
    }

    return 0 ;
}

