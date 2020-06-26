#include <cmath>
#include <iostream>

using namespace std;

long quick_pow(long num, long maxPow, long mod)
{
    long ans{1};
    while ( maxPow ) {
        if ( maxPow & 0x1 ) {
            ans = (ans % mod) * (num % mod) % mod;
        }
        num = (num % mod) * (num % mod) % mod;
        maxPow >>= 1;
    }
    return ans;
}


long quick_pow(long num, long pows)
{
    long ans{1};
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

    long num, maxPow, mod;
    cin >> num;
    while ( cin >> num >> maxPow >> mod ) {
        long up{quick_pow(num, maxPow + 1, (num - 1) * mod) - 1 + (num - 1) * mod};
        cout << up << ' ' << up / (num - 1) % mod << endl;
        // cout << ((quick_pow(num, maxPow + 1, (long)(num - 1) * mod) - 1 + (num - 1) * mod) / (num - 1) % mod - 1 + mod) % mod << endl;
        // cout << (long)pow(num, maxPow) % mod << endl << (long)quick_pow(num, maxPow, maxPow * mod) % mod << endl;
    }

    return 0;
}

