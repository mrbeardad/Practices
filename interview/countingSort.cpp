#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>


class CountingSort {
public:
    // int* countingSort(int* A, size_t n) {
    //     // write code here
    //     auto minmax = std::minmax_element(A, A + n);
    //     int minNum{*minmax.first}, maxNum{*minmax.second};
    //     std::vector<size_t> counts(static_cast<size_t>(maxNum - minNum) + 1);
    //     std::for_each(A, A + n, [&counts, minNum](int elem){++counts[static_cast<size_t>(elem - minNum)];});
    //     std::partial_sum(counts.begin(), counts.end(), counts.begin());
    //     std::vector<int> sorted(n);
    //     for ( int right{static_cast<int>(n) - 1}; right >= 0; --right ) {
    //         sorted[--counts[static_cast<size_t>(A[right] - minNum)]] = A[right];
    //     }
    //     std::copy(sorted.begin(), sorted.end(), A);
    //     return A;
    // }
    int* countingSort(int* A, size_t n)
    {
        auto minmax = std::minmax_element(A, A + n);
        int min{*minmax.first}, max{*minmax.second};
        std::vector<std::vector<int> > buckets(max - min + 1);
        std::for_each(A, A + n, [&buckets, min](int elem){buckets[elem - min].emplace_back(elem);});
        size_t idx{};
        for ( auto& thisBkt : buckets ) {
            for ( auto thisElem : thisBkt ) {
                A[idx++] = thisElem;
            }
        }
        return A;
    }
};


int main()
{
    std::vector<int> vec{std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{}};
    CountingSort{}.countingSort(vec.data(), vec.size());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, ","});

    return 0;
}

