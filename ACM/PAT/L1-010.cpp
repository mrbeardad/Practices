#include <iostream>
#include <queue>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    priority_queue<int, vector<int>, greater<int>> minNumFirst ;
    int tmp ;
    while ( cin >> tmp ) {
        minNumFirst.push( tmp ) ;
    }
    cout << minNumFirst.top() ;
    minNumFirst.pop() ;
    while ( !minNumFirst.empty() ) {
        cout << "->" << minNumFirst.top() ;
        minNumFirst.pop() ;
    }

    return 0 ;
}
