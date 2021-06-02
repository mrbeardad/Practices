#include <iostream>
#include <unordered_map>

struct Position
{
    int x_;
    int y_;
};

bool operator!=(const Position& lhs, const Position& rhs)
{
    return (lhs.x_ ^ rhs.x_) | (lhs.y_ ^ rhs.y_);
}

bool operator==(const Position& lhs, const Position& rhs)
{
    return !(lhs != rhs);
}

namespace std
{
    template<>
    struct hash<Position>
    {
        size_t operator()(const Position& d) const noexcept
        {
            hash<int> h{};
            return h(d.x_) + h(d.y_);
        }
    };
}


// 默认0则迷宫无此格，1则迷宫有此格，2则此格被染色
int dfs(std::unordered_map<Position, int>& maze, Position cur, Position tag)
{
    auto p2CurPos = maze.find(cur);
    if ( p2CurPos == maze.end() || p2CurPos->second == 2 )
        return std::numeric_limits<int>::max();
    if ( cur == tag )
        return 0;
    p2CurPos->second = 2;
    int pathLen{std::numeric_limits<int>::max()};
    ++cur.x_;
    pathLen = std::min(pathLen, dfs(maze, cur, tag));
    --cur.x_;
    --cur.x_;
    pathLen = std::min(pathLen, dfs(maze, cur, tag));
    ++cur.x_;
    ++cur.y_;
    pathLen = std::min(pathLen, dfs(maze, cur, tag));
    --cur.y_;
    --cur.y_;
    pathLen = std::min(pathLen, dfs(maze, cur, tag));
    ++cur.y_;
    if ( pathLen != std::numeric_limits<int>::max() )
        ++pathLen;
    p2CurPos->second = 1;
    return pathLen;
}

int main()
{
    int steps{};
    std::cin >> steps;
    // 每组数据
    for ( ; std::cin >> steps; ) {
        std::unordered_map<Position, int> maze{};
        // 每次移动，建立迷宫
        Position pos{0, 0};
        maze.emplace(pos, 1);
        for ( ; steps > 0; --steps ) {
            int dir{}, isMoved{};
            std::cin >> dir >> isMoved;
            if ( isMoved == 1 ) {
                switch ( dir ) {
                    case 0:
                        --pos.x_;
                        break;
                    case 1:
                        ++pos.x_;
                        break;
                    case 2:
                        --pos.y_;
                        break;
                    case 3:
                        ++pos.y_;
                        break;
                }
                maze.emplace(pos, 1);
            }
        }
        std::cout << dfs(maze, Position{0, 0}, pos) << std::endl;
        // std::cout << abs(pos.x_) + abs(pos.y_) << std::endl;
    }

    return 0;
}

