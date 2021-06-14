
#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

bool comp(std::string& lhs, size_t lBegin, size_t lEnd, std::string& rhs, size_t rBegin, size_t rEnd)
{
    size_t lLen{lEnd - lBegin}, rLen{rEnd - rBegin};
    if ( lLen != rLen )
        return false;
    if ( lLen & 0x1 )
        return lhs.substr(lBegin, lLen) == rhs.substr(rBegin, rLen);
    size_t lMid{lBegin + lLen / 2}, rMid{rBegin + rLen / 2};
    return comp(lhs, lBegin, lMid, rhs, rBegin, rMid)
        && comp(lhs, lMid, lEnd, rhs, rMid, rEnd)
        || comp(lhs, lBegin, lMid, rhs, rMid, rEnd)
        && comp(lhs, lMid, lEnd, rhs, rBegin, rMid);
}

int main()
{
    int g;
    std::string strA, strB;
    std::cin >> g;
    while ( std::cin >> strA >> strB ) {
        if ( comp(strA, 0, strA.size(), strB, 0, strB.size()) )
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}

