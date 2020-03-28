#include <iostream>
#include <sstream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string strA, strB ;
    cin >> strA ;
    cin.ignore() ;
    getline( cin, strB ) ;
    istringstream sstrmA{ move( strA ) }, sstrmB{ move( strB ) } ;

    int intA, intB ;
    bool isWrongA{ false }, isWrongB{ false } ;
    auto wrongA{ [&isWrongA](){cout << '?'; isWrongA = true;} } ;
    auto wrongB{ [&isWrongB](){cout << '?'; isWrongB = true;} } ;

    if ( sstrmA >> intA ) {
        if ( intA < 1 || intA > 1000 ) {
            wrongA() ;
        } else if ( sstrmA >> strA ) {
            wrongA() ;
        }
    } else {
        wrongA() ;
    }
    if ( !isWrongA ) {
        cout << intA ;
    }

    cout << " + " ;

    if ( strB.front() == ' ' ) {
        wrongB() ;
    } else if ( sstrmB >> intB ) {
        if ( intB < 1 || intB > 1000 ) {
            wrongB() ;
        }
        strB.clear() ;
        getline( sstrmB, strB ) ;
        if ( strB.size() ) {
            wrongB() ;
        }
    } else {
        wrongB() ;
    }
    if ( !isWrongB ) {
        cout << intB ;
    }

    cout << " = " ;

    if ( isWrongA || isWrongB ) {
        cout << '?' ;
    } else {
        cout << intA + intB ;
    }

    return 0 ;
}

