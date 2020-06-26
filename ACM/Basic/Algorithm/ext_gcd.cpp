#include <iomanip>
#include <iostream>

using namespace std;

int ext_gcd(int a, int b, int& x, int& y)
{
    if ( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }

    int ans{ext_gcd(b, a % b, y, x)};
    /*
     * 因 ans == b * y + (a % b) * x
     * 又 a % b == a - (a / b) * b
     * 故 ans == b * y + (a - (a / b) * b) * x == x * a + (y - (a / b) * x) * b
     */
    y -= a / b * x;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // bx + my = 1
    int x, y;
    cout << ext_gcd(2, 7, x, y) << ' ' << x << ' ' << y << endl;
    cout << -6 % 7 << endl;

    return 0;
}

