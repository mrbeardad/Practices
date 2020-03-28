#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std ;

inline bool
isOK(string& year, size_t diffNum)
{
    array<int, 10> numOfYearNum{} ;
    if ( year.size() < 4 ) {
        ++numOfYearNum[0] ;
    }
    for ( size_t thisNum : year ) {
        thisNum -= 0x30 ;
        ++numOfYearNum[thisNum] ;
    }
    long countOfdiff{ count_if( numOfYearNum.begin(), numOfYearNum.end(), [](int i){return i;} ) } ;
    if ( countOfdiff != diffNum ) {
        return false ;
    } else {
        return true ;
    }
}

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string year, outputYear ;
    size_t diffNum ;
    cin >> year >> diffNum ;
    outputYear = year ;
    while ( !isOK( outputYear, diffNum ) ) {
        int yearInt{ stoi( outputYear ) } ;
        outputYear = to_string( ++yearInt ) ;
    }

    int outputYearInt{ stoi( outputYear ) }, yearInt{ stoi( year ) } ;
    cout << outputYearInt - yearInt << ' ' ;
    size_t numOfZero{ 4 - outputYear.size() } ;
    while ( numOfZero-- ) {
        cout << 0 ;
    }
    cout << outputYear ;

    return 0 ;
}

