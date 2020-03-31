#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int notUse ;
    cin >> notUse ;
    string oneLine ;
    while ( cin >> oneLine ) {
        int sum1{}, sum2{} ;
        for ( size_t idx{}, end{ oneLine.size() }; idx < end; ++idx  ) {
            if ( idx < 3 ) {
                sum1 += oneLine[idx] - 0x30 ;
            } else {
                sum2 += oneLine[idx] - 0x30 ;
            }
        }
        if ( sum1 == sum2 ) {
            cout << "You are lucky!\n" ;
        } else {
            cout << "Wish you good luck.\n" ;
        }
    }

    return 0 ;
}

