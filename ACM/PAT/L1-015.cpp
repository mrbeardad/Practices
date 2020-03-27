#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int col, row ;
    char chart ;
    cin >> col >> chart ;
    row = col / 2.0 + 0.5 ;

    for ( int i{}; i < row; ++i ) {
        for ( int j{}; j < col; ++j ) {
            cout << chart ;
        }
        cout << '\n' ;
    }

    return 0 ;
}
