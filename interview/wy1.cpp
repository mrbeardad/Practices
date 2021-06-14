#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param inString string字符串 待判断的字符串
     * @param inStringNum int整型 输入字符串长度
     * @return int整型
     */
    int getMatchBracketsNum(std::string inString, int inStringNum) {
        // write code here
        int num1{}, num2{}, num3{};
        std::string stk{};
        for ( char thisChar : inString ) {
            switch ( thisChar ) {
                case '(':
                    ++num1;
                    stk += '(';
                    break;
                case '[':
                    ++num2;
                    stk += '[';
                    break;
                case '{':
                    ++num3;
                    stk += '{';
                    break;
                case ')':
                    if ( stk.empty() || stk.back() != '(' )
                        return -1;
                    stk.pop_back();
                    break;
                case ']':
                    if ( stk.empty() || stk.back() != '[' )
                        return -1;
                    stk.pop_back();
                    break;
                case '}':
                    if ( stk.empty() || stk.back() != '{' )
                        return -1;
                    stk.pop_back();
                    break;
                default:
                    return -1;
            }
        }
        if ( stk.size() )
            return -1;
        return num1 + num2 * 2 + num3 * 3;
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Solution{}.getMatchBracketsNum("[({}[])]", 8), 8);
}
