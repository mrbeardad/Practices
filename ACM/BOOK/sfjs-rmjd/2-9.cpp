#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int getN, minN{ INT32_MAX }, maxN{ INT32_MIN }, sum{}, cnt{} ;
    while ( cin >> getN ) {
        if ( getN < minN ) {
            minN = getN ;
        } else if ( getN > maxN ) {
            maxN = getN ;
        }
        ++cnt ;
        sum += getN ;
    }

    cout << fixed << setprecision( 3 ) << minN << ' ' << maxN << ' ' << sum / (double)cnt  ;

    return 0 ;
}

