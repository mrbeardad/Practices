#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    int tempoF ;
    cin >> tempoF ;
    cout << "Celsius = " ;
    cout << 5 * (tempoF - 32) / 9 ;

    return 0 ;
}
