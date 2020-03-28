#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int height, weight ;
    cin >> height ;
    while ( cin >> height >> weight ) {
        double stdWeight{ (height - 100) * 0.9 * 2 } ;
        double wucha{ abs( weight - stdWeight ) }, tenPTG{ stdWeight * 0.1 } ;
        if ( wucha < tenPTG ) {
            cout << "You are wan mei!\n" ;
        } else {
            if ( weight > stdWeight ) {
                cout << "You are tai pang le!\n" ;
            } else {
                cout << "You are tai shou le!\n" ;
            }
        }
    }

    return 0 ;
}

