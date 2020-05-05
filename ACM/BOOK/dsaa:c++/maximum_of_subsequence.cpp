#include <iostream>
#include <vector>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    cin.tie( nullptr ) ;

    vector<int> allSeq ;
    for ( int tmp{}; cin >> tmp; ) {
        allSeq.push_back(tmp) ;
    }

    size_t maxBeg{}, maxEnd{} ; int maxVal{} ;
    size_t thisBeg{}, thisEnd{} ; int thisMax{} ;
    int nowSum{} ;
    for ( size_t idx{}, end{ allSeq.size() }; idx < end; ++idx ) {
        nowSum += allSeq[idx] ;
        if ( nowSum > thisMax ) {
            thisMax = nowSum ;
            thisEnd = idx + 1 ;
        } else if ( nowSum < 0 ) {
            if ( thisMax > maxVal ) {
                maxBeg = thisBeg ;
                maxEnd = thisEnd ;
                maxVal = thisMax ;
            }
            thisBeg = thisEnd = idx + 1 ;
            thisMax = 0 ;
            nowSum = 0 ;
        }
    }
    if ( thisMax > maxVal ) {
        maxBeg = thisBeg ;
        maxEnd = thisEnd ;
        maxVal = thisMax ;
    }

    if ( maxBeg == maxEnd ) {
        cout << "No Positive Num" ;
    } else {
        cout << "Begin: " << maxBeg << "\nEnd: " << maxEnd << "\nSum: " << maxVal ;
    }

    return 0 ;
}
