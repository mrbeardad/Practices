#include <iostream>
#include <string>
#include <vector>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    vector<string> ChineseWord ;
    char chart ;
    int notUse ;
    cin >> chart >> notUse ;
    string tmp4word ;
    cin.ignore() ;
    while ( getline( cin, tmp4word ) ) {
        ChineseWord.push_back( tmp4word ) ;
    }

    bool isMirror{ true } ;
    if ( ChineseWord.size() % 2 ) {
        for ( auto beg{ ChineseWord.begin() }, end( --ChineseWord.end() ); beg != end; ++beg, --end ) {
            if ( *beg != *end ) {
                isMirror = false ;
            }
        }
    } else {
        isMirror = false ;
    }
    if ( isMirror ) {
        cout << "bu yong dao le\n" ;
    }

    for ( auto pos{ ChineseWord.rbegin() }, end{ ChineseWord.rend() }; pos != end; ++pos  ) {
        for ( size_t idx{ pos->size() }; idx; ) {
            char thisChar{ (*pos)[--idx] } ;
            if ( thisChar != ' ' ) {
                cout << chart ;
            } else {
                cout << ' ' ;
            }
        }
        cout << '\n' ;
    }

    return 0 ;
}

