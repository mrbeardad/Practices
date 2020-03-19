/*
 * 厄拉多塞筛法求N的素数
 */
#include <iostream>
#include <cmath>
#include <set>

using namespace std ;

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    int N ;
    cin >> N ;
    const int SQRT_N = sqrt(N) + 1 ;
    set<int> results ;
    for ( int i{ 2 }; i <= N; ++i ) {
        results.insert(i) ;
    }

    for (auto pos{ results.begin() }, end{ results.end() }; *pos < SQRT_N; ++pos ) {
        int low1val{ *pos } ;
        int lowNval{ low1val + low1val } ;
        while ( lowNval <= N ) {
            results.erase(lowNval) ;
            lowNval += low1val ;
        }
    }

    cout << results.size() << endl ;
    for ( auto& pos : results ) {
        cout << pos << ' ' ;
    }

    return 0 ;
}
