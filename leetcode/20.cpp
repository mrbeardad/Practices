#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool isValid(string str) {
        string stack{};
        for ( char thisChar : str ) {
            if ( thisChar == '(' || thisChar == '[' || thisChar == '{' ) {
                stack.push_back(thisChar);
            } else {
                switch ( thisChar ) {
                    case ')':
                        if ( stack.size() && stack.back() == '(' ) {
                            stack.pop_back();
                        } else {
                            return false;
                        }
                        break;
                    case ']':
                        if ( stack.size() && stack.back() == '[' ) {
                            stack.pop_back();
                        } else {
                            return false;
                        }
                        break;
                    case '}':
                        if ( stack.size() && stack.back() == '{' ) {
                            stack.pop_back();
                        } else {
                            return false;
                        }
                }
            }
        }
        return stack.empty();
    }
};

TEST(TestSuit, TestCase)
{

}
