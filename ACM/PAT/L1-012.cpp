#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int powNum ;
    cin >> powNum ;
    cout << "2^" << powNum << " = " << pow( 2, powNum ) ;

    return 0 ;
}
