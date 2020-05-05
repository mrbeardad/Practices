#include <algorithm>
#include <iostream>
#include <array>

using namespace std ;

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    array<char, 0x7c> comp{} ;
    int numr ;
    cin >> numr ;
    while ( numr != -1 ) {
        char tmp ;
        cin.ignore() ;
        cin.get(tmp) ;
        while ( tmp != '\n' ) {
            comp[tmp] = tmp ;
            cin.get(tmp) ;
        }

        int choice{} ;
        cin.get(tmp) ;
        while ( tmp != '\n' ) {
            if ( comp[tmp] > 1 ) { // 0表示无，1表示有且正确，其他表示有但未猜
                comp[tmp] = 1 ;
            } else if ( comp[tmp] == 0 ) {
                ++choice ;
            }
            cin.get(tmp) ;
        }
        if ( choice > 6 ) {
            cout << "You lose\n" ;
        } else if ( any_of(comp.begin(), comp.end(), [](char c){return c > 1;}) ) {
            cout << "You chickened out\n" ;
        } else {
            cout << "You win\n" ;
        }
        comp = {} ;
        cin >> numr ;
    }

    return 0 ;
}

