#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    cout << setprecision( 8 ) << 1 + 2 * sqrt( 3 ) / (5 - 0.1) ;

    return 0 ;
}

