#include <iostream>
#include <vector>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int numDeng, numPerson ;
    cin >> numDeng >> numPerson ;
    vector<int> isOn( numDeng + 1, false ) ;

    for ( int PersonNr{ 1 }; PersonNr <= numPerson; ++PersonNr ) {
        for ( int thisNr{ PersonNr }; thisNr <= numDeng; thisNr += PersonNr ) {
            isOn[thisNr] ^= 0x1 ;
        }
    }

    for ( int idx{ 1 }; idx <= numDeng; ++idx ) {
        if ( isOn[idx] ) {
            cout << idx << ' ' ;
        }
    }

    return 0 ;
}

