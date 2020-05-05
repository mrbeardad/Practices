#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    char bBit, sBit, gBit ;
    cin.get( bBit ) ;
    cin.get( sBit ) ;
    cin.get( gBit ) ;
    cout << gBit << sBit << bBit ;

    return 0 ;
}

