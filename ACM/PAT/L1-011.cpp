#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string oneLine, chars2erase ;
    getline( cin, oneLine ) ;
    getline( cin, chars2erase ) ;

    for ( char thisChar : oneLine ) {
        if ( chars2erase.find( thisChar ) == string::npos ) {
            cout << thisChar ;
        }
    }

    return 0 ;
}
