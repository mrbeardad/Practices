#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int notUse ;
    cin >> notUse ;
    cin.ignore() ;
    string oneLine ;
    while ( getline( cin, oneLine ) ) {
        size_t leftEnd{ oneLine.find( ',' ) } ;
        if ( leftEnd < 3 ) {
            cout << "Skipped\n" ;
            continue ;
        }
        if ( oneLine.substr( oneLine.size() - 4, 3 ) == "ong" && oneLine.substr( leftEnd - 3, 3 ) == "ong" ) {
            size_t idx{ oneLine.size() - 1 } ;
            for ( int spaceNum{}; spaceNum < 3; ) {
                idx = oneLine.rfind( ' ', idx ) - 1 ;
                ++spaceNum ;
            }
            oneLine[idx + 1] = 0 ;
            cout << oneLine.data() << " qiao ben zhong.\n" ;
        } else {
            cout << "Skipped\n" ;
        }
    }

    return 0 ;
}

