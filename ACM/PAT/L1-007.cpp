#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string numString ;
    cin >> numString ;

    size_t idx{ 0 } ;
    if ( numString[0] == '-' ) {
        cout << "fu " ;
        idx = 1 ;
    }
    for ( size_t end{ numString.size() - 1 }; idx < end; ++idx ) {
        char thisNum{ numString[idx] } ;
        switch ( thisNum ) {
            case '0':
                cout << "ling " ;
                break ;
            case '1':
                cout << "yi " ;
                break ;
            case '2':
                cout << "er " ;
                break ;
            case '3':
                cout << "san " ;
                break ;
            case '4':
                cout << "si " ;
                break ;
            case '5':
                cout << "wu " ;
                break ;
            case '6':
                cout << "liu " ;
                break ;
            case '7':
                cout << "qi " ;
                break ;
            case '8':
                cout << "ba " ;
                break ;
            case '9':
                cout << "jiu " ;
                break ;
        }
    }
    switch ( numString.back() ) {
        case '0':
            cout << "ling" ;
            break ;
        case '1':
            cout << "yi" ;
            break ;
        case '2':
            cout << "er" ;
            break ;
        case '3':
            cout << "san" ;
            break ;
        case '4':
            cout << "si" ;
            break ;
        case '5':
            cout << "wu" ;
            break ;
        case '6':
            cout << "liu" ;
            break ;
        case '7':
            cout << "qi" ;
            break ;
        case '8':
            cout << "ba" ;
            break ;
        case '9':
            cout << "jiu" ;
            break ;
    }

    return 0 ;
}
