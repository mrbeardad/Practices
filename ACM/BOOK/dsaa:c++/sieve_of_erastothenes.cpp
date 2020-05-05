#include <cstddef>
#include <cstdint>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std ;

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    using ull = uint64_t ;
    ull intN ;
    cin >> intN ;
    const ull SQRT_N = (int)sqrt(intN) + 1 ;
    vector<bool> results(intN + 1, true) ;

    bool onece{ true } ;
    ull low1val{2} ;
    for ( ; low1val <= SQRT_N; ++low1val ) {
        if ( !results[low1val] ) {
            continue ;
        }
        ull lowNval{low1val + low1val} ;
        if ( onece ) {
            onece = false ;
        } else {
            cout << ' ' ;
        }
        cout << low1val ;
        while ( lowNval <= intN ) {
            results[lowNval] = false ;
            lowNval += low1val ;
        }
    }

    while ( low1val <= intN ) {
        if ( results[low1val] ) {
            cout << ' ' << low1val ;
        }
        ++low1val ;
    }

    return 0 ;
}
