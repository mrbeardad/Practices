#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int num ;
    cin >> num ;

    int cnt{} ;
    while ( num != 1 ) {
        if ( num & 0x1 ) {
            num = 3 * num + 1 ;
        } else {
            num /= 2 ;
        }
        ++cnt ;
    }

    cout << cnt ;

    return 0 ;
}

