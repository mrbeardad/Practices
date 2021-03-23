#if !defined(MRBEARDAD_MINE_HPP_TIMER)
#define MRBEARDAD_MINE_HPP_TIMER

#include <chrono>
#include <iostream>
#include <vector>

namespace mine
{
class ProfTimer
{
    std::vector<std::chrono::steady_clock::time_point> timePoints_;
public:
    ProfTimer()
    {
        timePoints_.emplace_back(std::chrono::steady_clock::now());
    }

    ~ProfTimer()
    {
        if ( timePoints_.size() <= 1 ) return;

        auto total = timePoints_.back() - timePoints_.front();
        int cnter{};
        for ( auto itr = std::next(timePoints_.begin()), end = timePoints_.end(); itr != end; ++itr ) {
            auto curDuration = *itr - *std::prev(itr);
            auto timeCnt = std::chrono::duration_cast<std::chrono::milliseconds>(curDuration).count();
            auto timeLen = timeCnt > 1e3 ? timeCnt / 1e3 : timeCnt;
            auto timeUnit = timeCnt > 1e3 ? "s" : "ms";
            printf("\e[1;32m===>\e[m Timer Point\t%d:\t%.2f%s\t%.2f%%\n", cnter++, timeLen, timeUnit,
                    static_cast<double>(curDuration.count()) / total.count() * 100 );
        }
    }

    void operator()()
    {
        timePoints_.emplace_back(std::chrono::steady_clock::now());
    }
};
} // namespace mine
#endif // !defined(MRBEARDAD_MINE_HPP_CHRONO)
