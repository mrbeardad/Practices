#include <c++/9.3.0/x86_64-pc-linux-gnu/bits/c++config.h>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct KMP
{
    vector<int> next_m;
    string pat_m;

    explicit KMP(const string& patStr): pat_m{patStr}
    {
        int lenth = patStr.length();
        next_m.resize(lenth);
        for ( int idx{1}; idx < lenth; ++idx ) {
            int pubLen{next_m[idx - 1]};
            while ( pubLen >= 1 && patStr[pubLen] != patStr[idx] ) {
                pubLen = next_m[pubLen - 1];
            }
            if ( patStr[pubLen] == patStr[idx] ) {
                next_m[idx] = pubLen + 1;
            } else {
                next_m[idx] = 0;
            }
        }
    }

    size_t operator()(const string& cmpStr, size_t begin = 0)
    {
        int cmpIdx{}, cmpEnd = cmpStr.size(), patIdx{}, patEnd = next_m.size();
        while ( cmpIdx != cmpEnd && patIdx != patEnd ) {
            if ( cmpStr[cmpIdx] == pat_m[patIdx] ) {
                ++cmpIdx;
                ++patIdx;
            } else if ( patIdx != 0 ) {
                patIdx = next_m[patIdx - 1];
            } else {
                ++cmpIdx;
            }
        }

        if ( patIdx == patEnd ) {
            return cmpIdx - patEnd;
        } else {
            return UINT64_MAX;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    KMP kmp{"abcd"};
    cout << kmp("abcabcabcde") << '\n';
    cout << UINT64_MAX;

    return 0;
}

