#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int num, oddNum{}, evenNum{} ;
    cin >> num ;
    while ( cin >> num ) {
        if ( num & 1 ) {
            ++oddNum ;
        } else {
            ++evenNum ;
        }
    }
    cout << oddNum << ' ' << evenNum ;

    return 0 ;
}

