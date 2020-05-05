#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    double rlt{} ;
    int plusOrMinus{ 1 } ;
    double chuShu{ 1 }, cmpFld{ 1 } ;
    while ( cmpFld >= 1e-6 ) {
        rlt += plusOrMinus * cmpFld ;
        plusOrMinus *= -1 ;
        chuShu += 2 ;
        cmpFld = 1 / chuShu ;
    }
    cout.precision( 6 ) ;
    cout << rlt * 4 ;

    return 0 ;
}

