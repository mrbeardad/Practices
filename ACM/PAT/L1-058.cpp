#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string sent ;
    getline( cin, sent ) ;
    for ( size_t idx{}, end{ sent.size() }; idx < end; ) {
        if ( sent[idx] == '6' ) {
            int numOf6{ 1 } ;
            while ( sent[++idx] == '6' ) {
                ++numOf6 ;
            }
            if ( numOf6 <= 3 ) {
                while ( numOf6-- ) {
                    cout << '6' ;
                }
            } else if ( numOf6 <= 9 ) {
                cout << '9' ;
            } else {
                cout << "27" ;
            }
        } else {
            cout << sent[idx++] ;
        }
    }

    return 0 ;
}

