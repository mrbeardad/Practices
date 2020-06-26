#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<int> prime_sieve(int maxNum)
{
    vector<int> ret;
    vector<int> ans(maxNum + 1, 1);
    int sqrtNum = sqrt(maxNum);
    for ( int lowNum{2}; lowNum <= sqrtNum; ++lowNum ) {
        if ( ans[lowNum] ) {
            ret.push_back(lowNum);
            for ( int idx{lowNum + lowNum}; idx <= maxNum; idx += lowNum ) {
                ans[idx] = 0;
            }
        }
    }

    for ( int idx{sqrtNum + 1}; idx <= maxNum; ++idx ) {
        if ( ans[idx] ) {
            ret.push_back(idx);
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto primes{prime_sieve(20)};
    cout << primes.size() << endl;
    copy(primes.begin(), primes.end(), ostream_iterator<int>{cout, " "});

    return 0;
}

