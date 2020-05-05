#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    long intA, intB ;
    cin >> intA >> intB ;
    int tmp ;
    while ( intB ) {
        tmp = intA % intB ;
        intA = intB ;
        intB = tmp ;
    }
    cout << intA ;

    return 0 ;
}

