#include <iostream>
#include <vector>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    size_t n ;
    cin >> n ;
    vector<vector<int> > matrix( n, vector<int>(n) ) ;

    int num{ 1 } ;
    for ( int dimen = n, x{ -1 }, y{ dimen - 1 }; dimen > 0; ) {
        for ( int delim{ x + dimen }; x < delim; ) {
            matrix[++x][y] = num++ ;
        }
        for ( int delim{ y - dimen + 1 }; y > delim; ) {
            matrix[x][--y] = num++ ;
        }
        for ( int delim{ x - dimen + 1 }; x > delim; ) {
            matrix[--x][y] = num++ ;
        }
        dimen -= 2 ;
        for ( int delim{ y + dimen }; y < delim; ) {
            matrix[x][++y] = num++ ;
        }
    }

    for ( auto& thisVec : matrix ) {
        for ( auto& thisNum : thisVec ) {
            cout << thisNum << '\t' ;
        }
        cout << '\n' ;
    }

    return 0 ;
}

