#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std ;

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    unordered_map<int, pair<size_t, int>> infoStudents ;
    int numStudents ;
    cin >> numStudents ;
    for (int i{}; i < numStudents; ++i) {
        size_t zkzNum ;
        int sjNum, ksNum ;
        cin >> zkzNum >> sjNum >> ksNum ;
        infoStudents[sjNum] = { zkzNum, ksNum } ;
    }

    vector<int> need2find ;
    int num2find ;
    cin >> num2find ;
    for ( int i{}; i < num2find; ++i ) {
        int tmp4sjNum ;
        cin >> tmp4sjNum ;
        need2find.push_back( tmp4sjNum ) ;
    }

    for ( int sjNum2find : need2find ) {
        auto& thisPair{ infoStudents[sjNum2find] } ;
        cout << thisPair.first << ' ' << thisPair.second << '\n' ;
    }

    return 0 ;
}
