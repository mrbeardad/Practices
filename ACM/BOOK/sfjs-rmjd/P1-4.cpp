#include <iomanip>
#include <ios>
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    double n ;
    cin >> n ;
    double pi{ atan( 1 ) * 4 } ;
    n = n / 180 * pi ;
    cout << sin( n ) << ' ' << cos( n ) ;

    return 0 ;
}

