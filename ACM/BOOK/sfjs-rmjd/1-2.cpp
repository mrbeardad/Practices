#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    cout << fixed << setprecision( 1 ) << 8.0 / 5.0 ;

    return 0 ;
}

