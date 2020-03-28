#include <iostream>
#include <cmath>

using namespace std ;

bool isSuShu(int num)
{
    if ( num == 1 ) {
        return false ;
    }
    int sqrtN{ (int)sqrt( num ) } ;
    for ( int i{ 2 }; i <= sqrtN; ++i ) {
        if ( num % i == 0 ) {
            return false ;
        }
    }
    return true ;
}

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int thisNum ;
    cin >> thisNum ;
    while ( cin >> thisNum ) {
        if ( isSuShu( thisNum ) ) {
            cout << "Yes\n" ;
        } else {
            cout << "No\n" ;
        }
    }

    return 0 ;
}

