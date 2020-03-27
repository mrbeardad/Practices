#include <iostream>

using namespace std ;

int Weight[]{ 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 } ;
char Convert[]{ '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' } ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int numID ;
    string oneID ;
    cin >> numID ;
    numID = 0 ;
    while ( cin >> oneID ) {
        int sumWeighted{} ;
        bool isHaveX{ false } ;
        for ( size_t idx{}, end{ oneID.size() - 1 }; idx < end; ++idx ) {
            int thisInt{ oneID[idx] } ;
            thisInt = thisInt - 0x30 ;
            if ( thisInt > 9 ) {
                ++numID ;
                isHaveX = true ;
                cout << oneID << '\n' ;
                break ;
            } else {
                sumWeighted += thisInt * Weight[idx] ;
            }
        }

        if ( !isHaveX ) {
            sumWeighted = sumWeighted % 11 ;
            sumWeighted = Convert[sumWeighted] ;
            if ( oneID.back() != sumWeighted ) {
                ++numID ;
                cout << oneID << '\n' ;
            }
        }
    }

    if ( numID == 0 ) {
        cout << "All passed" ;
    }

    return 0 ;
}
