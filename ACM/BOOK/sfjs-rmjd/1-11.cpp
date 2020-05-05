#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int num, feet ;
    cin >> num >> feet ;
    int tuNum{ feet / 2 - num }, jiNum{ 2 * num - feet / 2 } ;
    if ( jiNum * 2 + tuNum * 4 != feet || jiNum < 0 || tuNum < 0 ) {
        cout << "No answer" ;
    } else {
        cout << jiNum << ' ' << tuNum ;
    }

    return 0 ;
}

