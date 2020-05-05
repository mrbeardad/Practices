#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    for ( int num1{ 123 }; num1 <= 329; ++num1 ) {
        int num2{ num1 + num1 }, num3{ num2 + num1 } ;
        bool isExist[10]{} ;
        isExist[num1 / 100] = isExist[num1 / 10 % 10] = isExist[num1 % 10] = true ;
        isExist[num2 / 100] = isExist[num2 / 10 % 10] = isExist[num2 % 10] = true ;
        isExist[num3 / 100] = isExist[num3 / 10 % 10] = isExist[num3 % 10] = true ;
        if ( isExist[0] == false ) {
            int idx{ 1 } ;
            for ( ; idx < 10; ++idx ) {
                if ( isExist[idx] == false ) {
                    break ;
                }
            }
            if ( idx == 10 ) {
                cout << num1 << ' ' << num2 << ' ' << num3 << '\n' ;
            }
        }
    }

    return 0 ;
}

