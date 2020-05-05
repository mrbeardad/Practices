#include <cstddef>
#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string needDeal ;
    getline( cin, needDeal ) ;

    for ( size_t pos{ needDeal.find( needDeal[0], 1 ) }; pos != string::npos; pos = needDeal.find( needDeal[0], pos + 1 ) ) {
        size_t& period{ pos } ;
        size_t strLen{ needDeal.size() } ;
        if ( strLen % period != 0 ) {
            continue ;
        }
        size_t periodBegin{ pos } ;
        while (  periodBegin < strLen ) {
            if ( !needDeal.compare( 0, period, needDeal, periodBegin, period ) ) {
                periodBegin += period ;
            } else {
                break ;
            }
        }
        if ( periodBegin == strLen ) {
            cout << period ;
            break ;
        }
    }

    return 0 ;
}

