#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>


class RadixSort {
public:
    int* radixSort(int* A, size_t n) {
        // write code here
        std::vector<std::vector<int> > buckets(10);
        for ( int times{1}; buckets.front().size() < n; times *= 10 ) {
            std::for_each(buckets.begin(), buckets.end(), [](std::vector<int>& thisB){thisB.clear();});
            std::for_each(A, A + n, [&buckets, &times](int elem){buckets[elem / times % 10].emplace_back(elem);});
            size_t idx{};
            for ( auto& thisB : buckets ) {
                for ( int thisElem : thisB ) {
                    A[idx++] = thisElem;
                }
            }
        }
        return A;
    }
};


int main()
{
    std::vector<int> vec{std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{}};
    RadixSort{}.radixSort(vec.data(), vec.size());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, ","});

    return 0;
}

