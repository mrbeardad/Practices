#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int sex, height, weight ;
    cin >> sex ;
    while ( cin >> sex >> height >> weight ) {
        if ( sex ) {
            if ( height > 130 ) {
                cout << "ni li hai! " ;
            } else if ( height == 130 ) {
                cout << "wan mei! " ;
            } else {
                cout << "duo chi yu! " ;
            }
            if ( weight > 27 ) {
                cout << "shao chi rou!\n" ;
            } else if ( weight == 27 ) {
                cout << "wan mei!\n" ;
            } else {
                cout << "duo chi rou!\n" ;
            }
        } else {
            if ( height > 129 ) {
                cout << "ni li hai! " ;
            } else if ( height == 129 ) {
                cout << "wan mei! " ;
            } else {
                cout << "duo chi yu! " ;
            }
            if ( weight > 25 ) {
                cout << "shao chi rou!\n" ;
            } else if ( weight == 25 ) {
                cout << "wan mei!\n" ;
            } else {
                cout << "duo chi rou!\n" ;
            }
        }
    }

    return 0 ;
}

