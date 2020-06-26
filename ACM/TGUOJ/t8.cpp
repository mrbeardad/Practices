#include <cstdlib>
#include <iostream>

using namespace std;

long maxFac(long num, long maxNum)
{
    if ( maxNum >= num ) {
        return 1;
    }
    auto divt{div(num, maxNum)};
    while ( divt.rem ) {
        divt = div(num, --maxNum);
    }
    return divt.quot;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long num, maxNum;
    cin >> num;
    while ( cin >> num >> maxNum ) {
        if ( maxNum >= num ) {
            cout << 1 << '\n';
        } else{
            long ans{num / (num / maxNum)};
            if ( ans > maxNum ) {
                cout << num / (num / maxNum + 1) << '\n';
            } else {
                cout << num / (num / maxNum)  << '\n';
            }
        }
    }

    return 0;
}

