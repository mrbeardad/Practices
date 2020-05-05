#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int a, b, c ;
    cin >> a >> b >> c ;
    cout << fixed << setprecision(3) << (a + b + c) / 3.0 ;

    return 0 ;
}

