#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int notUse ;
    cin >> notUse ;
    string name ;
    int huxi, maibo ;
    while ( cin >> name >> huxi >> maibo ) {
        if ( huxi < 15 || huxi > 20 || maibo < 50 || maibo > 70 ) {
            cout << name << '\n' ;
        }
    }

    return 0 ;
}

