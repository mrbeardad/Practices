#include <cstdlib>
#include <iostream>
#include <chrono>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    auto start{ chrono::steady_clock::now() } ;
    int numN ;
    cin >> numN ;
    if ( numN == 0 ) {
        cout << 1 ;
    } else {
        int sum{} ;
        for ( int nowN{ 1 }, jieCheng{ 1 }; nowN <= numN; ) {
            sum = (sum + jieCheng) % 1000000 ;
            jieCheng = jieCheng * ++nowN % 1000000 ;
        }
        cout << sum << '\n' ;
    }
    auto timeLen{ chrono::steady_clock::now() - start } ;
    cout << std::chrono::duration_cast<chrono::milliseconds>( timeLen ).count() ;

    return 0 ;
}

