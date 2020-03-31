#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string chushou ;
    int jiange ;
    cin >> jiange ;
    cin >> chushou ;
    for ( int times{}; chushou != "End"; cin >> chushou ) {
        if ( times++ < jiange ) {
            if ( chushou == "JianDao" ) {
                cout << "ChuiZi\n" ;
            } else if ( chushou == "ChuiZi" ) {
                cout << "Bu\n" ;
            } else {
                cout << "JianDao\n" ;
            }
        } else {
            times = 0 ;
            cout << chushou << '\n' ;
        }
    }

    return 0 ;
}

