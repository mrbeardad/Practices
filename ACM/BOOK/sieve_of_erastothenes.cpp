#include <iostream>
#include <cmath>
#include <set>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    long intN ;
    cin >> intN ;
    const long SQRT_N = (int)sqrt( intN ) + 1 ;
    set<int> results ;
    for ( long i{ 2 }; i <= intN; ++i ) {
        results.insert( i ) ;
    }

    for ( auto pos{ results.begin() }, end{ results.end() }; *pos < SQRT_N; ++pos ) {
        long low1val{ *pos } ;
        long lowNval{ low1val + low1val } ;
        while ( lowNval <= intN ) {
            results.erase(lowNval) ;
            lowNval += low1val ;
        }
    }

    cout << results.size() << endl ;
    //for ( auto& pos : results ) {
        //cout << pos << ' ' ;
    //}

    return 0 ;
}
