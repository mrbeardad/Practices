#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int intA, intB ;
    cin >> intA >> intB ;
    for ( int cnt{ intA + intB }; cnt; --cnt ) {
        cout << "Wang!" ;
    }

    return 0 ;
}

