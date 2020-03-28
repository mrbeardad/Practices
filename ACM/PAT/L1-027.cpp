#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    set<char, greater<char>> arr ;
    string telNum ;
    cin >> telNum ;
    for ( char thisChar : telNum ) {
        arr.insert( thisChar ) ;
    }

    unordered_map<char, char> num2idx ;
    char thisIdx{ '0' } ;
    auto beg{ arr.begin() }, end{ arr.end() } ;
    char firstNum{ *beg++ } ;
    cout << "int[] arr = new int[]{" ;
    cout << firstNum ;
    num2idx[firstNum] = thisIdx++ ;
    while ( beg != end ) {
        char thisNum{ *beg++ } ;
        cout << ',' << thisNum ;
        num2idx[thisNum] = thisIdx++ ;
    }
    cout << "};\n" ;

    cout << "int[] index = new int[]{" ;
    cout << num2idx[telNum.front()] ;
    for ( size_t idx{ 1 }, end{ telNum.size() }; idx < end; ++idx  ) {
        cout << ',' << num2idx[telNum[idx]] ;
    }
    cout << "};" ;

    return 0 ;
}

