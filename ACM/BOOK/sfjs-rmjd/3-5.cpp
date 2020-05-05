#include <iostream>
#include <string>
#include <regex>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    string senten ;
    getline( cin, senten ) ;

    senten = regex_replace( senten, regex{R"dl("([^"]*)")dl"}, R"(``$1&&)" ) ;
    senten = regex_replace( senten, regex{R"(&&)"}, R"(")" ) ;
    cout << senten ;

    return 0 ;
}

