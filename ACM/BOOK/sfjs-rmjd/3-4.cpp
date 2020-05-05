#include <iostream>
#include <sstream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    char range[10]{} ;
    for ( char thisD{}; cin.get( thisD ); ) {
        range[thisD - 0x30] = true ;
    }

    auto isOK = [range] (int num) {
        for ( int chuShu{ 1 }, shang{ num }; shang > 0; chuShu *= 10, shang = num / chuShu ) {
            if ( !range[shang % 10] ) {
                return false ;
            }
        }
        return true ;
    } ;

    for ( int de{ 10 }; de < 100; ++de ) {
        for ( int abc{ 100 }; abc < 1000; ++abc ) {
            int x{ abc * (de % 10) }, y{ abc * (de / 10) }, z{ abc * de } ;
            if ( isOK( abc ) && isOK( de ) && isOK( x ) && isOK( y ) && isOK( z ) ) {
                cout << abc << " * " << de << " = " << z << '\n' ;
            }
        }
    }

    return 0 ;
}

