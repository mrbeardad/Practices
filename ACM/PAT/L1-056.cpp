#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    vector<pair<int, string> > allPeople ;
    allPeople.reserve( 10000 ) ;
    string name ;
    int guessNum, avgNum{} ;
    cin >> guessNum ;
    while ( cin >> name >> guessNum ) {
        allPeople.push_back( { guessNum, move( name ) } ) ;
        avgNum += guessNum ;
    }
    sort( allPeople.begin(), allPeople.end() ) ;
    avgNum = avgNum / allPeople.size() / 2 ;

    decltype(allPeople.begin()) resultPos ;
    int nowClosest{ INT32_MAX } ;
    for ( auto pos{ allPeople.begin() }, end{ allPeople.end() }; pos != end; ) {
        int thisNum{ pos->first } ;
        int thisDist{ avgNum > thisNum ? avgNum - thisNum : thisNum - avgNum } ;
        if ( thisDist < nowClosest ) {
            nowClosest = thisDist ;
            resultPos = pos ;
        }
        if ( (++pos)->first - avgNum > nowClosest ) {
            break ;
        }
    }

    cout << avgNum << ' ' << resultPos->second ;

    return 0 ;
}

