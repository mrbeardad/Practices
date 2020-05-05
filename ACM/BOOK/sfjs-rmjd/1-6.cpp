#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int num ;
    cin >> num ;
    cout << num % 10 << num / 10 % 10 << num / 100 ;

    return 0 ;
}

