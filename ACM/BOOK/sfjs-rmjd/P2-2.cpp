#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int num3, num5, num7, cnt{ 1 } ;
    while ( cin >> num3 >> num5 >> num7 ) {
        cout << "Case " << cnt++ << ": " ;
        int people{ 10 } ;
        for ( ; people <= 100; ++people ) {
            if ( (people - num3) % 3 == 0 && (people - num5) % 5 == 0 && (people - num7) % 7 == 0 ) {
                cout << people<< '\n' ;
                break ;
            }
        }
        if ( people == 101 ) {
            cout << "No answer\n" ;
        }
    }

    return 0 ;
}

