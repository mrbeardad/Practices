#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    list<pair<bool,string>> students ;
    int isMan ;
    string name ;
    cin >> isMan ;
    while ( cin >> isMan >> name ) {
        students.push_back( { (bool)isMan, name } ) ;
    }

    while ( students.size() ) {
        bool isThisMan{ students.front().first } ;
        cout << students.front().second << ' ' << flush ;
        auto secondStudent{ find_if( students.rbegin(), students.rend(), [isThisMan](pair<bool, string>& p){return p.first != isThisMan;} ) } ;
        auto aboveBase{ --secondStudent.base() } ;
        cout << secondStudent->second << flush ;
        cout << '\n' ;
        students.pop_front() ;
        students.erase( aboveBase ) ;
    }

    return 0 ;
}

