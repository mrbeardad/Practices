#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

int main()
{
    int len{};
    std::cin >> len;
    std::vector<std::vector<int> > matrix(len);
    for ( int idx{}, tmp{}; std::cin >> tmp; idx = (idx + 1) % len ) {
        matrix[idx].emplace_back(tmp);
    }

    std::vector<std::vector<int> > result(len, std::vector<int>(len));
    for ( ssize_t x1{}; x1 < len; ++x1 ) {
        for ( ssize_t y1{}; y1 < len; ++y1 ) {
            if ( matrix[x1][y1] == 1 ) {
                for ( ssize_t x2{}; x2 < len; ++x2 ) {
                    for ( ssize_t y2{}; y2 < len; ++y2 ) {
                        if ( matrix[x2][y2] != 1 ) {
                            if ( result[x2][y2] == 0 )
                                result[x2][y2] = std::abs(x1 - x2) + std::abs(y1 - y2);
                            else
                                result[x2][y2]
                        }
                    }
                }
            }
        }
    }

    int minAns{std::numeric_limits<int>::max()}, ansX{}, ansY{};
    for ( ssize_t x{len - 1}; x >= 0; --x ) {
        auto y = std::min_element(result[x].begin(), result[x].end()) - result[x].begin();
        if ( result[x][y] <= minAns ) {
            minAns = result[x][y];
            ansX = x;
            ansY = y;
        }
    }
    std::cout << ansX << ' ' << ansY;

    return 0;
}

