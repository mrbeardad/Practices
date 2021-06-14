#include <iostream>
#include <vector>

int main()
{
    int groups{};
    std::cin >> groups;
    for ( ; groups > 0; --groups ) {
        std::vector<int> menA(3), womenA(3), menB(3), womenB(3);
        auto input = [] (std::vector<int>& container) {
            for ( size_t idx{}; idx < 3; ++idx ) {
                int tmp{};
                std::cin >> tmp;
                container[idx] = tmp;
            }
        };
        input(menA);
        input(womenA);
        input(menB);
        input(womenB);
        int ans{};
        for ( size_t idxManA{}; idxManA < menA.size(); ++idxManA ) {
            for ( size_t idxWomanA{}; idxWomanA < womenA.size(); ++idxWomanA) {
                for ( size_t idxManB{}; idxManB < menB.size(); ++idxManB ) {
                    for ( size_t idxWomanB{}; idxWomanB < womenB.size(); ++idxWomanB ) {
                        int groupA{menA[(idxManA + 1) % 3] + menA[(idxManA + 2) % 3]};
                        int groupB{menB[(idxManB + 1) % 3] + menB[(idxManB + 2) % 3]};
                        int winCount{};
                        winCount += (groupB > groupA);
                        groupA = menA[idxManA] + womenA[idxWomanA];
                        groupB = menB[idxManB] + womenB[idxWomanB];
                        winCount += (groupB > groupA);
                        groupA = womenA[(idxWomanA + 1) % 3] + womenA[(idxWomanA + 2) % 3];
                        groupB = womenB[(idxWomanB + 1) % 3] + womenB[(idxWomanB + 2) % 3];
                        winCount += (groupB > groupA);
                        ans += (winCount >= 2);
                    }
                }
            }
        }
        std::cout << ans << std::endl;
    }

    return 0;
}

