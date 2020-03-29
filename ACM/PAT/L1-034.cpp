#include <iostream>
#include <unordered_map>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    unordered_map<int, int> allFeature ;
    int articleNum ;
    cin >> articleNum ;
    while ( articleNum-- ) {
        int featureNum ;
        cin >> featureNum ;
        while ( featureNum-- ) {
            int thisFeature ;
            cin >> thisFeature ;
            ++allFeature[thisFeature] ;
        }
    }

    int maxFeature{}, maxNum{} ;
    for ( auto& thisPair : allFeature ) {
        int thisFeature{ thisPair.first }, thisNum{ thisPair.second } ;
        if ( thisNum > maxNum || thisNum == maxNum && thisFeature > maxFeature ) {
            maxFeature = thisFeature ;
            maxNum = thisNum ;
        }
    }

    cout << maxFeature << ' ' << maxNum ;

    return 0 ;
}

