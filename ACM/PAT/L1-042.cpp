#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    char year[5], month[3], day[3] ;
    cin.get( month, 3 ) ;
    cin.ignore() ;
    cin.get( day, 3 ) ;
    cin.ignore() ;
    cin.get( year, 5 ) ;
    cout << year << '-' << month << '-' << day ;

    return 0 ;
}

