#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string person2nd, person14th ;
    int personNum{} ;
    do {
        cin >> person14th ;
        if ( ++personNum == 2 ) {
            person2nd = person14th ;
        } else if ( personNum == 14 ) {
            ++personNum ; // 保证此处退出时personNum的语义与正常退出时一样
            break ;
        }
    } while ( person14th.front() != '.' ) ;

    if ( personNum <= 2 ) {
        cout << "Momo... No one is for you ..." ;
    } else if ( personNum <= 14 ) {
        cout << person2nd << " is the only one for you..." ;
    } else {
        cout << person2nd << " and " << person14th << " are inviting you to dinner..." ;
    }

    return 0 ;
}

