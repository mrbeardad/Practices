#include <iostream>
#include <cmath>

using namespace std;

int quick_pow(int num, int pows)
{
    int ans{1};
    while ( pows > 0 ) {
        if ( pows & 0x1 ) {
            ans *= num;
        }
        num *= num;
        pows >>= 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cout << quick_pow(2, 3) << endl;
    // cout << pow(3, 9) << endl;

    return 0;
}

