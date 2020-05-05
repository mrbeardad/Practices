#include <functional>
#include <iostream>
#include <queue>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    priority_queue<int, vector<int>, greater<int>> pQueue ;
    for ( int tmp{}; cin >> tmp; ) {
        pQueue.push( tmp ) ;
    }

    while ( pQueue.size() ) {
        cout << pQueue.top() << ' ' ;
        pQueue.pop() ;
    }

    return 0 ;
}

