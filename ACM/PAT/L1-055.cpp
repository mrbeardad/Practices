#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int pA, pB, pwB{} ;
    cin >> pA >> pB ;
    for ( int tmp{}; cin >> tmp; ) {
        pwB += tmp ;
    }

    cout << "The winner is " ;
    if ( pA > pB && pwB != 3 || pwB == 0 ) {
        cout << "a: " << pA << " + " << 3 - pwB ;
    } else {
        cout << "b: " << pB << " + " << pwB ;
    }

    return 0 ;
}

