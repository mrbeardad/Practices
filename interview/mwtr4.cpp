#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <numeric>
#include <unordered_map>

int main()
{
    std::list<int> train{std::numeric_limits<int>::min()};
    using Itr = std::list<int>::iterator;
    std::unordered_map<std::string, std::pair<Itr, Itr> > cat{};
    std::string endCat{};
    int pushOrExc{};
    std::cin >> pushOrExc;
    while ( std::cin >> pushOrExc ) {
        if ( pushOrExc == 1 ) {   // push
            int id{};
            std::cin >> id;
            std::string thisCat{};
            std::cin >> thisCat;
            auto tagCat = cat.find(thisCat);
            if ( tagCat != cat.end() ) {
                cat[thisCat].second = train.insert(tagCat->second.second, id);
            } else {
                train.emplace_back(id);
                train.emplace_back(std::numeric_limits<int>::min());
                cat[thisCat] = std::make_pair(std::prev(train.end(), 2), std::prev(train.end()));
            }
        } else {
            std::string lhs, rhs;
            std::cin >> lhs >> rhs;
            auto& catLhs = cat[lhs];
            auto& catRhs = cat[rhs];
            train.splice(catLhs.second, train, catRhs.first, catRhs.second);
            auto catLhsEnd = catLhs.second;
            catLhs.second = catRhs.first;
            train.splice(catRhs.second, train, catLhs.first, catLhs.second);
            catRhs.second = catLhsEnd;
        }
    }
    for ( auto itr = std::next(train.begin()); ; ) {
        if ( *itr != std::numeric_limits<int>::min() )
            std::cout << *itr;
        if ( ++itr == train.end() )
            break;
        if ( *itr != std::numeric_limits<int>::min() )
            std::cout << ' ';
    }

    return 0;
}

