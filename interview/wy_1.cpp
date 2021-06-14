#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<int, int> countOfChar{
        {'s', 3},
        {'d', 4},
        {'u', 5},
        {'p', 6},
        {'f', 7},
        {'%', 9}
    };
    std::string oneline{};
    std::cin >> oneline;
    for ( ; std::cin >> oneline; ) {
        int count{};
        for ( size_t idx{}; idx < oneline.size(); ++idx ) {
            if ( oneline[idx] != '%' ) {
                count += 3;
            } else {
                count += 3;
                for ( ; ++idx < oneline.size() && std::isdigit(oneline[idx]); ) {
                    count += 8;
                }
                // 此时idx可能等于size
                int lastCharCount{countOfChar[oneline[idx]]};
                if ( lastCharCount == 0 && idx < oneline.size() ) {
                    count += 9;
                } else {
                    count += lastCharCount;
                }
            }
        }
        std::cout << ++count << std::endl;
    }

    return 0;
}

