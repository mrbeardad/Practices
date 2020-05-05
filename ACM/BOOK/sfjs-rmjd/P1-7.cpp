#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int year ;
    cin >> year ;
    if ( !(year % 4) && year % 400 ) {
        cout << "yes" ;
    } else {
        cout << "no" ;
    }

    return 0 ;
}

