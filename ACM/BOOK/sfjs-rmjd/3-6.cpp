#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string str{ "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./" } ;
    int needDeal ;
    while ( (needDeal = cin.get()) != EOF ) {
        auto pos{ str.find( needDeal ) } ;
        if ( pos != string::npos ) {
            cout << str[pos - 1] ;
        } else {
            cout << (char)needDeal ;
        }
    }

    return 0 ;
}

