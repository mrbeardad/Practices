#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <utility>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    list<pair<size_t, int> > studNumInSchool ;
    array<vector<int>, 100> numrEachSchool ;
    int schoolNum ;
    cin >> schoolNum ;
    for ( int teamNum{}, idx{}; cin >> teamNum; ++idx ) {
        studNumInSchool.push_back( { idx, teamNum * 10 } ) ;
    }

    int thisNumr{ 1 } ;
    bool onlyOneFirst{ true };
    for ( auto pos{ studNumInSchool.begin() }; studNumInSchool.size(); ++thisNumr ) {
        auto& thisPair{ *pos } ;
        if ( studNumInSchool.size() == 1 ) {
            if ( onlyOneFirst ) {
                onlyOneFirst = false ;
            } else {
                ++thisNumr ;
            }
        }
        numrEachSchool[thisPair.first].push_back( thisNumr ) ;
        if ( --thisPair.second == 0 ) {
            studNumInSchool.erase( pos++ ) ;
            if ( pos == studNumInSchool.end() && studNumInSchool.size() ) {
                pos = studNumInSchool.begin() ;
            }
            continue ;
        }
        if ( ++pos == studNumInSchool.end() && studNumInSchool.size() ) {
            pos = studNumInSchool.begin() ;
        }
    }

    for ( size_t idx{}; idx < schoolNum; ++idx ) {
        cout << '#' << idx + 1 << '\n' ;
        int coutNum{} ;
        for ( int numr : numrEachSchool[idx] ) {
            cout << numr ;
            if ( ++coutNum == 10 ) {
                cout << '\n' ;
                coutNum = 0 ;
            } else {
                cout << ' ' ;
            }
        }
    }

    return 0 ;
}

