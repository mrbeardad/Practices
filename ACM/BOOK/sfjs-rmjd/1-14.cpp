#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int a, b, c ;
    cin >> a >> b >> c ;

    if ( a > b ) {
        int tmp{ a } ;
        a = b ;
        b = tmp ;
    }
    if ( b > c ) {
        int tmp{ c } ;
        c = b ;
        b = tmp ;
    }
    if ( a > b ) {
        int tmp{ a } ;
        a = b ;
        b = tmp ;
    }
    cout << a << ' ' << b << ' ' << c ;

    return 0 ;
}

