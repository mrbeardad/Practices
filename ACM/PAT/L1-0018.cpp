#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    char hour[3], minte[3] ;
    cin.read( hour, 2 ) ;
    hour[2] = 0 ;
    cin.ignore() ;
    cin.read( minte, 2 ) ;
    minte[2] = 0 ;

    int hourNum{ atoi( hour ) } ;
    if ( hourNum >= 0 && hourNum < 12 || hourNum == 12 && minte == "00"s ) {
        cout << "Only " << hour << ':' << minte << ".  Too early to Dang." ;
    } else {
        hourNum -= 12 ;
        while ( hourNum ) {
            cout << "Dang" ;
            --hourNum ;
        }
        if ( minte != "00"s ) {
            cout << "Dang" ;
        }
    }

    return 0 ;
}
