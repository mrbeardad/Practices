#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string sstr ;
    cin >> sstr ;

    int Gnum{}, Pnum{}, Lnum{}, Tnum{} ;
    for ( char thischar : sstr ) {
        switch ( thischar ) {
            case 'G':
            case 'g':
                ++Gnum ;
                break ;
            case 'P':
            case 'p':
                ++Pnum ;
                break ;
            case 'L':
            case 'l':
                ++Lnum ;
                break ;
            case 'T':
            case 't':
                ++Tnum ;
                break ;
        }
    }

    while ( Gnum || Pnum || Lnum || Tnum ) {
        if ( Gnum ) {
            cout << 'G' ;
            --Gnum ;
        }
        if ( Pnum ) {
            cout << 'P' ;
            --Pnum ;
        }
        if ( Lnum ) {
            cout << 'L' ;
            --Lnum ;
        }
        if ( Tnum ) {
            cout << 'T' ;
            --Tnum ;
        }
    }

    return 0 ;
}

