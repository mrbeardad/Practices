#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

void print_bignum(std::string& num)
{
    auto plus1 = [] (char& thisNum) {
        if ( thisNum == '9' ) {
            thisNum = '0';
            return true;
        } else {
            ++thisNum;
            return false;
        }
    };

    auto print = [] (std::string& str) {
        size_t start{str.find_first_not_of('0')};
        if ( start != std::string::npos )
            std::cout << str.data() + start << std::endl;
        else
            std::cout << '0' << std::endl;
    };

    for ( ; ; ) {
        print(num);
        for ( size_t idx{num.size() - 1}; plus1(num[idx]); --idx ) {
            if ( idx == 0 )
                return;
        }
    }
}

void print_bignum_recur(std::string& nums, size_t idx)
{
    auto print = [] (std::string& str) {
        size_t start{str.find_first_not_of('0')};
        if ( start != std::string::npos )
            std::cout << str.data() + start << std::endl;
        else
            std::cout << '0' << std::endl;
    };

    if ( idx == nums.size() - 1 ) {
        nums[idx] = '0';
        for ( ; nums[idx] <= '9'; ++nums[idx] )
            print(nums);
        return;
    }

    nums[idx] = '0';
    for ( ; nums[idx] <= '9'; ++nums[idx] )
        print_bignum_recur(nums, idx + 1);
}

int main()
{
    size_t len{};
    std::cin >> len;
    std::string num(len, '0');
    print_bignum_recur(num, 0);

    return 0;
}
