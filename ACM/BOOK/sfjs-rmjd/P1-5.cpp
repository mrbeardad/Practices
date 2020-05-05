#include <iomanip>
#include <ios>
#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int cnt ;
    cin >> cnt ;
    cout << fixed << setprecision( 2 ) ;
    if ( cnt >= 4 ) {
        cout << 95.0 * cnt * 0.85 ;
    } else {
        cout << 95.5 * cnt ;
    }

    return 0 ;
}

