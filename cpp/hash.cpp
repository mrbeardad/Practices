#include <iostream>
#include <unordered_map>

#include "fmt/ranges.h"

#include "mine.hpp"

int main()
{
    std::unordered_multimap<int, int> hashTable{};
    hashTable.emplace(1, 1);
    hashTable.emplace(1, 3);
    hashTable.emplace(1, 2);
    fmt::print("{}", hashTable);
    fmt::print("{}", hashTable.equal_range(1).first->second);

    return 0;
}

