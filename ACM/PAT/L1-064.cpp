#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int lineNum ;
    cin >> lineNum ;
    cin.ignore() ;
    string oneLine ;
    istringstream oneLineStream ;
    while ( getline( cin, oneLine ) ) {
        cout << oneLine << "\nAI: " ;
        oneLineStream.str( move( oneLine ) ) ;
        string thisWord ;
        oneLineStream >> thisWord ;
        bool notFirst{ false } ;
        while ( true ) {
            if ( !ispunct( thisWord[0] ) && notFirst ) { // 删除标点前空格
                cout << ' ' ;
            }
            notFirst = true ;


            for ( auto& thisChar : thisWord ) { // 转换 ? -> !，转换小写
                if ( isalpha( thisChar ) && thisChar != 'I' ) {
                    thisChar = tolower( thisChar ) ;
                } else if ( thisChar == '?' ) {
                    thisChar = '!' ;
                }
            }

            size_t wordSize{ thisWord.size() } ;
            size_t idxOfme{ thisWord.find( "me" ) } ;
            while ( idxOfme != string::npos ) { // 转换 me -> you
                if ( (idxOfme == 0 || ispunct( thisWord[idxOfme - 1] )) && (idxOfme + 2 == wordSize || ispunct( thisWord[idxOfme + 2] )) ) {
                    thisWord.replace( idxOfme, 2, "you" ) ;
                    wordSize = thisWord.size() ;
                }
                idxOfme = thisWord.find( "me", idxOfme + 2 ) ;
            }

            wordSize = thisWord.size() ;
            size_t idxOfI{ thisWord.find( 'I' ) } ;
            while ( idxOfI != string::npos ) { // 转换 I -> you
                if ( (idxOfI == 0 || ispunct( thisWord[idxOfI - 1] )) && (idxOfI + 1 == wordSize || ispunct( thisWord[idxOfI + 1] )) ) {
                    thisWord.replace( idxOfI, 1, "you" ) ;
                    wordSize = thisWord.size() ;
                }
                idxOfI = thisWord.find( 'I', idxOfI + 1 ) ;
            }

            // "can you" 和 "could you" 中间只能有一个空格，f**k，重新用regex库写
            wordSize = thisWord.size() ;
            bool next2this{ false } ;
            string nextWord ;
            if ( wordSize >= 3 && thisWord.substr( wordSize - 3 ) == "can" && ( wordSize == 3 || ispunct( thisWord[wordSize - 4] )) ) {
                if ( !(oneLineStream >> nextWord) ) {
                    cout << thisWord ;
                    break ;
                }
                next2this = true ;
                if ( nextWord.size() >= 3 && nextWord.substr( 0, 3 ) == "you" ) {
                    if ( nextWord.size() == 3 ) {
                        thisWord.replace( wordSize - 3, 3, "I can" ) ;
                        next2this = false ;
                    } else if ( ispunct(nextWord[3]) ) {
                        thisWord.replace( wordSize - 3, 3, "I can" ) ;
                        nextWord.erase( 0, 3 ) ;
                    }
                }
            } else if ( wordSize >= 5 && thisWord.substr( wordSize - 5 ) == "could" && (thisWord.size() == 5 || ispunct( thisWord[wordSize - 6] )) ) {
                if ( !(oneLineStream >> nextWord) ) {
                    cout << thisWord ;
                    break ;
                }
                next2this = true ;
                if ( nextWord.size() >= 3 && nextWord.substr( 0, 3 ) == "you" ) {
                    if ( nextWord.size() == 3 ) {
                        thisWord.replace( wordSize - 5, 5, "I could" ) ;
                            next2this = false ;
                    } else if ( ispunct( nextWord[3] ) ) {
                        thisWord.replace( wordSize - 5, 5, "I could" ) ;
                        nextWord.erase( 0, 3 ) ;
                    }
                }
            }
            cout << thisWord ;
            if ( next2this ) {
                thisWord = nextWord ;
            } else if ( !(oneLineStream >> thisWord) ) {
                break ;
            }
        }
        cout << '\n' ;
        oneLineStream.clear() ;
    }

    return 0 ;
}

