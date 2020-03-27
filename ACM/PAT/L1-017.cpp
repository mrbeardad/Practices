#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string int2 ;
    cin >> int2 ;

    size_t numDigit{ int2.size() } ;
    double nagetive{ 1.0 } ;
    if ( int2.front() == '-' ) {
        --numDigit ;
        nagetive += 0.5 ;
    }
    long numOf2{ count( int2.begin(), int2.end(), '2' ) } ;

    double result{ (double)numOf2 / numDigit * nagetive } ;
    if ( (int2.back() - 0x30 & 1) == 0 ) {
        result += result ;
    }
    cout << fixed << showpoint << setprecision( 2 ) << result * 100 << '%' ;

    return 0 ;
}
