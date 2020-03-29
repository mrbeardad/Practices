#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    double fpA, fpB ;
    cin >> fpA >> fpB ;
    cout << fpA << '/' ;
    if ( fpB < 0 ) {
        cout << '(' << fpB << ")=" << fixed << setprecision( 2 ) << fpA / fpB ;
    } else if ( fpB == 0 ) {
        cout << "0=Error" ;
    } else {
        cout << fpB << '=' << fixed << setprecision( 2 ) << fpA / fpB ;
    }

    return 0 ;
}

