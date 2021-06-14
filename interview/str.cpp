#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

string replaceSpace(string s)
{
    auto spaceCnt = count(s.begin(), s.end(), ' ');
    auto mid = s.size();
    s.resize(s.size() + spaceCnt * 2);
    auto end = s.size() - 1;
    for ( auto idx = mid - 1; idx < mid; --idx ) {    // mid溢出回环到大值
        if ( s[idx] == ' ' ) {
            s[end--] = '0';
            s[end--] = '2';
            s[end--] = '%';
        } else {
            s[end--] = s[idx];
        }
    }
    return s;
}

int main()
{
    std::cout << .1f+.1f+.1f << std::endl;

    return 0;
}

