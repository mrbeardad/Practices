#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int minNum, maxNum, sum{} ;
    cin >> minNum >> maxNum ;

    for ( int nowNum{ minNum }; nowNum <= maxNum; ++nowNum ) {
        sum += nowNum ;
    }

    --minNum ;
    while ( minNum + 5 <= maxNum ) {
        cout << setw( 5 ) << ++minNum ;
        cout << setw( 5 ) << ++minNum ;
        cout << setw( 5 ) << ++minNum ;
        cout << setw( 5 ) << ++minNum ;
        cout << setw( 5 ) << ++minNum ;
        cout << '\n' ;
    }

    for ( int nowNum{ minNum + 1 }; nowNum <= maxNum; ++nowNum ) {
        cout << setw( 5 ) << nowNum ;
    }
    if ( minNum != maxNum ) {
        cout << '\n' ;
    }

    cout << "Sum = " << sum ;

    return 0 ;
}
