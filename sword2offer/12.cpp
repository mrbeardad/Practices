#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

bool dfs(const std::vector<std::vector<int> >& matrix, std::vector<std::vector<bool> >& visited,
        size_t row, size_t col,
        const std::vector<int>& tagPath, size_t pathIdx)
{
    if ( row >= matrix.size() || col >= matrix[row].size() )
        return false;
    if ( pathIdx >= tagPath.size() )
        return true;
    if ( matrix[row][col] != tagPath[pathIdx] || visited[row][col] )
        return false;
    visited[row][col] = true;
    bool ans{dfs(matrix, visited, row - 1, col, tagPath, pathIdx + 1)
        || dfs(matrix, visited, row + 1, col, tagPath, pathIdx + 1)
        || dfs(matrix, visited, row, col - 1, tagPath, pathIdx + 1)
        || dfs(matrix, visited, row, col + 1, tagPath, pathIdx + 1)};
    visited[row][col] = false;
    return ans;
}

bool has_path(const std::vector<std::vector<int> >& matrix, const std::vector<int>& tagPath)
{
    if ( tagPath.empty() )
        return true;

    std::vector<std::vector<bool> > visited(matrix.size(), std::vector<bool>(matrix.front().size()));
    for ( size_t row{}; row < matrix.size(); ++row ) {
        for ( size_t col{}; col < matrix[row].size(); ++col ) {
            if ( tagPath.front() != matrix[row][col] )
                continue;
            if ( dfs(matrix, visited, row, col, tagPath, 0) )
                return true;
        }
    }
    return false;
}

TEST(TestSuit, TestCase)
{
    std::vector<std::vector<int> > matrix{{1,2,3,4},{5,6,7,8},{9,0,1,2}};

    std::vector<int> path{1,5,9,0};
    EXPECT_EQ(has_path(matrix, path), true);
    path.assign({1,2,6,7,9});
    EXPECT_EQ(has_path(matrix, path), false);

    matrix.assign({{1,2,3,4}});
    path.assign({1,2,3,4});
    EXPECT_EQ(has_path(matrix, path), true);
    path.assign({1,2,4});
    EXPECT_EQ(has_path(matrix, path), false);

    matrix.assign({{1},{2},{3},{4}});
    path.assign({1,2,3,4});
    EXPECT_EQ(has_path(matrix, path), true);
    path.assign({1,2,4});
    EXPECT_EQ(has_path(matrix, path), false);
}
