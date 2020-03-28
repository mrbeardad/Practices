#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int height ;
    cin >> height ;
    cout << fixed << setprecision( 1 ) << (height - 100) * 0.9 * 2 ;

    return 0 ;
}

