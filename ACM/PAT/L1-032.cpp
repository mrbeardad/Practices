#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    size_t charNum ;
    char chart ;
    string originStr ;
    cin >> charNum >> chart ;
    cin.ignore() ;
    getline( cin, originStr ) ;
    if ( originStr.size() >= charNum ) {
        cout << &originStr[originStr.size() - charNum] ;
    } else {
        for ( size_t i{ charNum - originStr.size() }; i; --i ) {
            cout << chart ;
        }
        cout << originStr ;
    }

    return 0 ;
}

