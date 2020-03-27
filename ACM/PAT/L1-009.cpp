#include <iostream>
#include <vector>
#include <utility>
//#include <numeric> // gcd被ban了

using namespace std ;

pair<long, long> addRatio(pair<long, long>& left, pair<long, long>& right)
{
    long leftNum{ left.first }, leftDen{ left.second }, rightNum{ right.first }, rightDen{ right.second } ;
    leftNum = leftNum * rightDen ;
    rightNum = rightNum * leftDen ;
    leftDen = leftDen * rightDen ;
    return { leftNum + rightNum, leftDen } ;
}

long gcd(long first, long second)
{
    while ( second != 0 ) {
        long tmp{ first % second } ;
        first = second ;
        second = tmp ;
    }
    return first ;
}

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    long numRatio ;
    cin >> numRatio ;
    vector<pair<long, long>> allRatio ;
    for ( long i{}; i < numRatio; ++i ) {
        long num, den ;
        cin >> num ;
        cin.ignore() ;
        cin >> den ;
        allRatio.push_back( { num, den } ) ;
    }

    pair<long, long> result{ allRatio[0] } ;
    for ( size_t idx{ 1 }, end{ allRatio.size() }; idx < end; ++idx ) {
        result = addRatio( result, allRatio[idx] ) ;
        //cout << result.first << '/' << result.second << endl ;
    }

    // 整数部分
    long num{ result.first }, den{ result.second } ;
    if ( num == 0 ) { // 0做被除数也浮点错误？什么zz平台
        cout << 0 ;
        return 0 ;
    }
    auto divt{ div( num, den ) } ;
    long partOfInt{ divt.quot } ;
    num = divt.rem ;

    // 化简
    long factor{ gcd( result.first, result.second ) } ;
    num /= factor ;
    den /= factor ;

    if ( partOfInt ) {
        cout << partOfInt ;
    }
    if ( num ) {
        if ( partOfInt ) {
            cout << ' ' ;
        }
        cout << num << '/' << den ;
    }

    return 0 ;
}
