#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class BubbleSort {
public:
    int* bubbleSort(int* A, int n) {
        // write code here
        for ( int right{n}; right >= 0; --right ) {
            for ( size_t idx{}; idx + 1 < right; ++idx ) {
                if ( A[idx] > A[idx + 1] )
                    std::swap(A[idx], A[idx + 1]);
            }
        }
        return A;
    }
};

int main()
{
    std::vector<int> vec{std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{}};
    BubbleSort{}.bubbleSort(vec.data(), vec.size());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, ","});

    return 0;
}
