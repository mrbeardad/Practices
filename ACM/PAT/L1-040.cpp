#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    char sex ;
    double height ;
    int notUse ;
    cin >> notUse ;
    cout << fixed << setprecision( 2 ) ;
    while ( cin >> sex >> height ) {
        if ( sex == 'M' ) {
            cout << height / 1.09 << '\n' ;
        } else {
            cout << height * 1.09 << '\n' ;
        }
    }

    return 0 ;
}

