#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int intN ;
    cin >> intN ;

    if ( intN == 0 ) {
        cout << 1 ;
    } else {
        int sum{}, nowSum{ 1 }, thisIntN{ 1 } ;
        while ( thisIntN <= intN ) {
            nowSum *= thisIntN++ ;
            sum += nowSum ;
        }
        cout << sum ;
    }

    return 0 ;
}
