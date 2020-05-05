#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    double r, h ;
    cin >> r >> h ;
    cout << "Area = " << fixed << setprecision( 3 ) << 2 * 3.1415926 * r * h + 3.1415962 * r * r * 2 ;

    return 0 ;
}

