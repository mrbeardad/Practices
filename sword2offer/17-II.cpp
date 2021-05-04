#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

std::string add_unsigned_bignumber(const std::string& lhs, const std::string& rhs)
{
    auto plus3 = [] (char lhs, char rhs, char& carry) {
        int sum{lhs - '0' + rhs - '0' + carry - '0'};
        carry = sum % 10 + '0';
        return sum / 10 + '0';
    };

    std::string ans{"0"};
    size_t leftIdx{lhs.size() - 1}, rightIdx{rhs.size() - 1};
    for ( ; leftIdx < lhs.size() || rightIdx < rhs.size(); --leftIdx, --rightIdx ) {
        if ( leftIdx >= lhs.size() )
            ans.push_back(plus3('0', rhs[rightIdx], ans.back()));
        else if ( rightIdx >= rhs.size() )
            ans.push_back(plus3(lhs[leftIdx], '0', ans.back()));
        else
            ans.push_back(plus3(lhs[leftIdx], rhs[rightIdx], ans.back()));
    }
    if ( ans.back() == '0' )
        ans.pop_back();
    std::reverse(ans.begin(), ans.end());
    return ans;
}

std::string reduce_unsigned_bignumber(const std::string& lhs, const std::string& rhs)
{
    if ( lhs < rhs )
        return "-" + reduce_unsigned_bignumber(rhs, lhs);

    auto minus3 = [] (char lhs, char rhs, char& borrow) {
        int diff{lhs - rhs + borrow - '0'};
        borrow = (10 + diff) % 10 + '0';
        return diff / 10 + '0';
    };

    std::string ans{"0"};
    size_t leftIdx{lhs.size() - 1}, rightIdx{rhs.size() - 1};
    for ( ; leftIdx < lhs.size(); --leftIdx, --rightIdx ) {
        if ( rightIdx < rhs.size() )
            ans.push_back(minus3(lhs[leftIdx], rhs[rightIdx], ans.back()));
        else
            ans.push_back(minus3(lhs[leftIdx], '0', ans.back()));
    }
    if ( ans.back() == '0' )
        ans.pop_back();
    std::reverse(ans.begin(), ans.end());
    return ans;
}

std::string multiplies_unsigned_bignumber(const std::string& lhs, const std::string& rhs)
{
    auto multi3 = [] (char lhs, char rhs, char& carry) {
        int prod{(lhs - '0') * (rhs - '0') + carry - '0'};
        carry = prod % 10 + '0';
        return prod / 10 + '0';
    };

    std::string ans{"0"};
    size_t rightIdx{rhs.size() - 1};
    for ( ; rightIdx < rhs.size(); --rightIdx ) {
        std::string multiAns{"0"};
        for ( size_t leftIdx{lhs.size() - 1}; leftIdx < lhs.size(); --leftIdx ) {
            multiAns.push_back(multi3(lhs[leftIdx], rhs[rightIdx], multiAns.back()));
        }
        if ( multiAns.back() == '0' )
            multiAns.pop_back();
        std::reverse(multiAns.begin(), multiAns.end());
        multiAns.append(std::string(rhs.size() - rightIdx - 1, '0'));
        ans = add_unsigned_bignumber(ans, multiAns);
        // std::cout << "\e[31mfuck:\e[m " << ans << std::endl;
    }
    return ans;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(add_unsigned_bignumber("123", "89"), "212");
    EXPECT_EQ(reduce_unsigned_bignumber("23", "89"), "-66");
    EXPECT_EQ(multiplies_unsigned_bignumber("23", "89"), "2047");
}
