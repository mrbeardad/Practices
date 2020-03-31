#include <iostream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int rowA, rowB, colA, colB ;
    int matrixA[10000], matrixB[10000], matrixC[10000] ;

    cin >> rowA >> colA ;
    for ( int nowcnt{}, tolcnt{ rowA * colA }; nowcnt < tolcnt; ++nowcnt ) {
        cin >> matrixA[nowcnt] ;
    }
    cin >> rowB >> colB ;
    for ( int nowcnt{}, tolcnt{ rowB * colB }; nowcnt < tolcnt; ++nowcnt ) {
        cin >> matrixB[nowcnt] ;
    }

    if ( colA != rowB ) {
        cout << "Error: " << colA << " != " << rowB ;
    } else {
        cout << rowA << ' ' << colB << '\n' ;
        for ( size_t thisRow{}; thisRow < rowA; ++thisRow ) {
            for ( size_t thisCol{}; thisCol < colB; ++thisCol ) {
                int result{} ;
                for ( size_t thisNum{}; thisNum < colA; ++thisNum ) {
                    result += matrixA[thisRow * colA + thisNum] * matrixB[thisCol + colB * thisNum] ;
                }
                if ( thisCol != 0 ) {
                    cout << ' ' ;
                }
                cout << result ;
            }
            cout << '\n' ;
        }
    }

    return 0 ;
}

