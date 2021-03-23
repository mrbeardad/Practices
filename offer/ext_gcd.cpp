#include <iostream>

int ext_gcd(int a, int b, int& x, int& y)
{
    if ( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }
    auto gcd = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return gcd;
}

int main()
{
    int a, b, mod, x, y;
    std::cin >> a >> b >> mod;
    auto gcd = ext_gcd(b, mod, x, y);
    if ( gcd == 1 ) {
        std::cout << '(' << a << " / " << b << ") % " << mod
            << " == ((" << a << " % " << mod << ") * (" << x << " % " << mod << ")) % " << mod
            << " == " << ((a % mod) * (x % mod)) % mod << std::endl;
    }
    std::cout << a % mod << std::endl;
    std::cout << x % mod << std::endl;

    return 0;
}

