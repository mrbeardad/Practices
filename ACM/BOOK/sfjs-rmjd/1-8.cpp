#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int a, b ;
    cin >> a >> b ;
    int tmp{ a } ;
    a = b ;
    b = tmp ;
    cout << a << ' ' << b ;

    return 0 ;
}

