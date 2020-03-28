#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int today, houtian ;
    cin >> today ;
    houtian = (today + 1) % 7 + 1 ;
    cout << houtian ;

    return 0 ;
}

