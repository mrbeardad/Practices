#include <algorithm>
#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int edge[3] ;
    cin >> edge[0] >> edge[1] >> edge[2] ;
    sort( begin( edge ), end( edge ) ) ;
    if ( edge[0] * edge[0] + edge[1] * edge[1] == edge[2] * edge[2] ) {
        cout << "yes" ;
    } else if ( edge[0] + edge[1] > edge[2] ) {
        cout << "no" ;
    } else {
        cout << "not a triangle" ;
    }

    return 0 ;
}

