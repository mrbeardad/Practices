#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int x, y ;
    cin >> x >> y ;
    cout << 5000 - x * y / 2 - (100 - y) * (100 - x) / 2 - (100 - x) * y ;

    return 0 ;
}

