#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int jiuliangA, jiuliangB, notUse ;
    cin >> jiuliangA >> jiuliangB ;
    cin >> notUse ;

    int haveA{}, haveB{} ;
    int hanA, hanB, chuA, chuB ;
    while ( cin >> hanA >> chuA >> hanB >> chuB ) {
        int sum{ hanA + hanB } ;
        if ( chuA == sum && chuB != sum ) {
            ++haveA ;
        } else if ( chuB == sum && chuA != sum ) {
            ++haveB ;
        }
        if ( haveA > jiuliangA ) {
            cout << "A\n" << haveB ;
            return 0 ;
        } else if ( haveB > jiuliangB ) {
            cout << "B\n" << haveA ;
            return 0 ;
        }
    }

    return 0 ;
}
