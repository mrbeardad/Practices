#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

constexpr int PRIME_NUM{5};
array<int, PRIME_NUM> Primes{2, 3, 5, 7, 9};

array<int, PRIME_NUM> udt(int num)
{
    array<int, PRIME_NUM> ret;
    for ( int idx{}; idx < PRIME_NUM; ++idx) {
        int thisPrime{Primes[idx]};
        auto divt{div(num, thisPrime)};
        int thisPow{};
        while ( divt.rem == 0 ) {
            ++thisPow;
            num = divt.quot;
            divt = div(num, thisPrime);
        }
        ret[idx] = thisPow;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto ans{udt(20)};
    for ( int thisPow : ans ) {
        cout << thisPow << ' ' << endl;
    }

    return 0;
}

