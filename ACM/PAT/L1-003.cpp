#include <iostream>
#include <string>
#include <map>

using namespace std ;

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    map<char, int> results ;
    string numString ;
    cin >> numString ;

    for ( char thisChar : numString ) {
        ++results[thisChar] ;
    }

    for ( auto& thisPair : results ) {
        cout << thisPair.first << ':' << thisPair.second << '\n' ;
    }

    return 0 ;
}
