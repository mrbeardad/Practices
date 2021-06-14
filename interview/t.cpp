#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <numeric>
#include <vector>

int main()
{
    std::list<int> ls{1,2,3,4,5};
    ls.splice(ls.begin(), ls, ++ls.begin(), ls.end());
    std::copy(ls.begin(), ls.end(),std::ostream_iterator<int>{std::cout, ","});

    return 0;
}

