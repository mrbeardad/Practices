#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string theString( 10001ul, '\0' ) ;
    int oneColCnt ;
    cin >> oneColCnt ;
    cin.ignore() ;
    getline( cin, theString ) ;
    int stringSize{ (int)theString.size() } ;
    theString[--stringSize] = 0 ; // 丢弃newline

    int lastColStart{ stringSize % oneColCnt } ;
    int needSpace ; // 行号大于它就要输出行首空格占位符，行号1开始
    if ( lastColStart == 0 ) {
        lastColStart = stringSize - oneColCnt ;
        needSpace = oneColCnt ;
    } else {
        needSpace = lastColStart ;
        lastColStart = stringSize - lastColStart ;
    }

    for ( int rowNum{ 1 }; rowNum <= oneColCnt; ++rowNum ) {
        if ( rowNum > needSpace ) {
            cout << ' ' ;
        } else {
            cout << theString[lastColStart] ;
        }
        int thisCharInRow{ lastColStart - oneColCnt } ;
        while ( thisCharInRow >= 0 ) {
            cout << theString[thisCharInRow] ;
            thisCharInRow -= oneColCnt ;
        }
        cout << '\n' ;
        ++lastColStart ;
    }

    return 0 ;
}

