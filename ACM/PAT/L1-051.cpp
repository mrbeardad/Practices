#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    double origin, discount ;
    cin >> origin >> discount ;
    double result{ origin * discount / 10 } ;
    cout << fixed << setprecision( 2 ) << result ;

    return 0 ;
}

