#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <regex>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int lineNum ;
    cin >> lineNum ;
    cin.ignore() ;
    string oneLine ;
    stringstream oneLineStrm ;
    regex canyou{ R"((\b)(can|could) you(\b))" } ;
    regex meOrI{ R"((\b)(I|me)(\b))" } ;
    regex threeAnd{ R"(&&&)" } ;
    regex multiSpace{ R"((\s+))" } ;
    while ( getline( cin, oneLine ) ) {
        cout << oneLine << "\nAI: " ;
        for ( char& thisChar : oneLine ) { // 转换小写，转换 ? -> !
            if ( thisChar != 'I' && isupper( thisChar ) ) {
                thisChar = (char)tolower( thisChar ) ;
            } else if ( thisChar == '?' ) {
                thisChar = '!' ;
            }
        }
        oneLine = regex_replace( oneLine, multiSpace, " " ) ;
        oneLine = regex_replace( oneLine, meOrI, R"($1&&&$3)" ) ;
        oneLine = regex_replace( oneLine, canyou, R"($1I $2$3)" ) ;
        oneLine = regex_replace( oneLine, threeAnd, R"(you)" ) ;
        oneLineStrm.str( oneLine ) ;
        bool isFirstWord{ true } ;
        while ( oneLineStrm >> oneLine ) {
            if ( !ispunct( oneLine[0] ) && !isFirstWord ) {
                cout << ' ' ;
            } else if ( isFirstWord ) {
                isFirstWord = false ;
            }
            cout << oneLine ;
        }
        oneLineStrm.clear() ;
        cout << '\n' ;
    }

    return 0 ;
}

