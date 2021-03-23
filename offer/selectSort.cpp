#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
        // write code here
        for ( int right{n}; right > 0; --right ) {
            int maxIdx{};
            for ( size_t idx{1}; idx < right; ++idx ) {
                if ( A[idx] > A[maxIdx] )
                    maxIdx = idx;
            }
            std::swap(A[maxIdx], A[right - 1]);
        }
        return A;
    }
};

int main()
{
    std::vector<int> vec{std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{}};
    SelectionSort{}.selectionSort(vec.data(), vec.size());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, ","});

    return 0;
}

