#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int n ;
    cin >> n ;
    cout << (1 + n) * n / 2 ;

    return 0 ;
}

