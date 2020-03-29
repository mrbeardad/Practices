#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int thisInt ;
    size_t numr{ 1 } ;
    while ( cin >> thisInt ) {
        if ( thisInt == 250 ) {
            cout << numr ;
            return 0 ;
        }
        ++numr ;
    }

    return 0 ;
}

