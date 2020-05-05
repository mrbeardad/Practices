#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    for ( int num{ 33 }, pingF{ 33 * 33 }; pingF <= 9999; ) {
        int hi1{ pingF / 1000 }, hi2{ pingF / 100 % 10 }, lo1{ pingF / 10 % 10 }, lo2{ pingF % 10 } ;
        if ( hi1 == hi2 && lo1 == lo2 ) {
            cout << pingF ;
        }
        ++num ;
        pingF = num * num ;
    }

    return 0 ;
}

