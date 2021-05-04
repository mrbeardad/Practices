#include <algorithm>
#include <functional>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int dfs(const std::vector<std::vector<int> >& rectangle, std::vector<std::vector<bool> >& visited,
        size_t row, size_t col, std::function<bool(int)> check)
{
    if ( row >= rectangle.size() || col >= rectangle[row].size() )
        return 0;
    if ( !check(rectangle[row][col]) || visited[row][col] )
        return 0;
    visited[row][col] = true;
    return 1 + dfs(rectangle, visited, row - 1, col, check)
        + dfs(rectangle, visited, row + 1, col, check)
        + dfs(rectangle, visited, row, col - 1, check)
        + dfs(rectangle, visited, row, col + 1, check);
}

int robot_path(const std::vector<std::vector<int> >& rectangle, unsigned int k)
{
    auto check = [k] (int num) {
        int sum{};
        for ( ; num; num /= 10 )
            sum += num % 10;
        return sum <= k;
    };

    std::vector<std::vector<bool> > visited(rectangle.size(), std::vector<bool>(rectangle.front().size()));
    return dfs(rectangle, visited, 0, 0, check);
}

TEST(TestSuit, TestCase)
{
    std::vector<std::vector<int> > rectangle{{1,2,3},{2,3,4},{4,5,6}};

    EXPECT_EQ(robot_path(rectangle, 6), 9);
    EXPECT_EQ(robot_path(rectangle, 5), 8);
    EXPECT_EQ(robot_path(rectangle, 1), 1);
    EXPECT_EQ(robot_path(rectangle, 0), 0);
    EXPECT_EQ(robot_path(rectangle, -1), 9);
}
