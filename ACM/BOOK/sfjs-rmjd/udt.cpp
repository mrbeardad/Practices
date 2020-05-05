#include <iostream>
#include <set>
#include <cmath>

using namespace std ;

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    constexpr int N{ 2000 } ;
    const int SQRT_N = sqrt(N) ;
    set<int> prime ;
    for ( int i{ 2 }; i <= N; ++i ) {
        prime.insert(i) ;
    }
    auto begin{ prime.begin() } ;
    for ( int thisMin{ *begin }; thisMin <= SQRT_N; thisMin = *++begin ) {
        for ( int needErase{ thisMin + thisMin }; needErase <= N; needErase += thisMin ) {
            prime.erase(needErase) ;
        }
    }

    int num{15} ;
    // cin >> num ;
    begin = prime.begin() ;
    for ( int once{}; num > 1; ++begin ) {
        int thisPrime{*begin};
        if ( num % thisPrime ) {
            continue;
        } else {
            int pows{1};
            num /= thisPrime;
            while ( num % thisPrime == 0 ) {
                ++pows;
                num /= thisPrime;
            }
            
            if ( once ) {
                cout << " * " ;
            } else {
                once = true ;
            }
            cout << thisPrime << '^' << pows;
        }
    }


    return 0 ;
}

