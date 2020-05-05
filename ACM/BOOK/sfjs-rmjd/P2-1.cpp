#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    for ( int num{ 100 }; num < 1000; ++num ) {
        int sum{} ;
        sum += pow( num / 100, 3 ) ;
        sum += pow( num % 100 / 10, 3 ) ;
        sum += pow( num % 10, 3 ) ;
        if ( sum == num ) {
            cout << sum << '\n' ;
        }
    }

    return 0 ;
}

