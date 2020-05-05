#include <ios>
#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    double tepF ;
    cin >> tepF ;
    cout << fixed << setprecision( 3 ) << (tepF - 32) * 5 / 9 ;

    return 0 ;
}

