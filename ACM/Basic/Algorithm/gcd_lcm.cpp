#include <iostream>

using namespace std;

inline int
gcd(int m, int n)
{
    while ( n != 0 ) {
        int tmp{m % n};
        m = n;
        n = tmp;
    }
    return m;
}

inline int
lcm(int m, int n)
{
    return m * n / gcd(m, n);
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cout << gcd(24, 18) << endl;
    cout << lcm(6, 8) << endl;

    return 0;
}

