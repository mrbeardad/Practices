#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    double weight, hight ;
    cin >> weight >> hight ;
    double pow2{ weight / hight / hight } ;

    cout << fixed << setprecision( 1 ) << pow2 << '\n' ;
    if ( pow2 > 25 ) {
        cout << "PANG" ;
    } else {
        cout << "Hai Xing" ;
    }

    return 0 ;
}

