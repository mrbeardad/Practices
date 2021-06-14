#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>


class Solution {
    std::unordered_map<size_t, bool> visited_;
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for ( size_t row{}; row < board.size(); ++row ) {
            for ( size_t col{}; col < board[row].size(); ++ col ) {
                if ( find(board, row, col, word.data()) )
                    return true;
            }
        }
        return false;
    }

    bool find(std::vector<std::vector<char>>& matrix, size_t row, size_t col, const char* word)
    {
        size_t key{};
        if ( row >= matrix.size() || col >= matrix[row].size()
                || visited_[key = row * matrix[row].size() + col] || matrix[row][col] != *word )
            return false;

        if ( *++word == '\0' )
            return true;

        visited_[key] = true;
        bool hasPath{find(matrix, row - 1, col, word) || find(matrix, row + 1, col, word)
            || find(matrix, row, col - 1, word) || find(matrix, row, col + 1, word)};
        visited_[key] = false;
        return hasPath;
    }
};


TEST(TestSuit, TestCase)
{
    std::vector<std::vector<char> > matrix{{'a', 'b'}, {'c', 'd'}};
    EXPECT_EQ(Solution{}.exist(matrix, "abcd"), false);
}
