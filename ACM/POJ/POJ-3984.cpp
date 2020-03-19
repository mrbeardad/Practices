#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

enum class PosCanBeGo
{
    up = 1 ,
    down = 2 ,
    left = 4 ,
    right = 8 ,
} ;

constexpr size_t Xlen{ 5 }, Ylen{ 5 } ; // 确定迷宫的长和宽
constexpr size_t END = Xlen * Ylen ;
bool Maze[Xlen][Ylen] ;
vector<size_t> VisitPath{ (size_t)-1, 0 } ; // 记录访问路径，避免回环

vector<size_t> shortest(vector<size_t>& thePath)
{
    auto originSize{ thePath.size() } ; // 用以复原路径
    size_t lastPos{ *----thePath.end() }, nowPos{ thePath.back() } ; // 好马不吃回头草
    vector<size_t> ret{ nowPos } ; // 返回最短路径
    vector<vector<size_t>> toFindShortest{ 4 } ; // 用以容纳4个方向递归返回的路径

    // 基准情况
    if ( nowPos == END-1 || find( thePath.begin(), --thePath.end(), nowPos ) != --thePath.end() ) {
        return ret ;
    }

    if ( size_t up{ nowPos - Xlen }; up < END && *(&Maze[0][0] + up) == 0 && up != lastPos ) {
        thePath.push_back(up) ;
        toFindShortest[0] = shortest(thePath) ;
        thePath.resize(originSize) ;
    }
    if ( size_t down{ nowPos + Xlen }; down < END && *(&Maze[0][0] + down) == 0 && down != lastPos ) {
        thePath.push_back(down) ;
        toFindShortest[1] = shortest(thePath) ;
        thePath.resize(originSize) ;
    }
    if ( size_t left{ nowPos - 1 }; nowPos % Xlen != 0 && *(&Maze[0][0] + left) == 0 && left != lastPos ) {
        thePath.push_back(left) ;
        toFindShortest[2] = shortest(thePath) ;
        thePath.resize(originSize) ;
    }
    if ( size_t right{ nowPos + 1 }; right % Xlen != 0 && *(&Maze[0][0] + right) == 0 && right != lastPos ) {
        thePath.push_back(right) ;
        toFindShortest[3] = shortest(thePath) ;
        thePath.resize(originSize) ;
    }
    auto filter = remove_if( toFindShortest.begin(), toFindShortest.end(), [](auto t){return t.size() == 0 || t.back() != END-1;} ) ;
    auto theShort{ min_element( toFindShortest.begin(), filter, [](auto a, auto b){return a.size() < b.size() ;} ) } ;
    ret.insert( ret.end(), make_move_iterator(theShort->begin()), make_move_iterator(theShort->end()) ) ;
    return ret ;
}

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    for ( bool *pos{&Maze[0][0]}, *end{pos + END}; pos < end; ++pos ) {
        cin >> *pos ;
    } // 注：若迷宫有太多连续的0方块则会显著降低运行效率，可以将输入进行处理，若存在0组成的九宫格方块则将中间的0换为1，可以证明此举不会影响程序正确性，且可以显著降低运行时间，特别是输入的迷宫全0的情况
    auto result{ shortest(VisitPath) } ;
    for ( auto pos{ result.begin() }, end{ result.end() }; pos != end; ++pos ) {
        cout << '(' << *pos / Xlen << ", " << *pos % Xlen << ")\n" ;
    }

    /*
    // 用红色标记出选取的最短路径
    for (size_t i{0}; i < Ylen; ++i) {
        for (size_t j{0}; j < Xlen; ++j) {
            if (size_t pos = Xlen * i + j; find(result.begin(), result.end(), pos) != result.end()) {
                cout << "\e[1;31m" ;
            }
            cout << Maze[i][j]  << "\e[m " ;
        }
        cout << '\n' ;
    }
    */

    return 0 ;
}
