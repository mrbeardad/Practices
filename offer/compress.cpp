#include <iostream>
#include <string>

using std::string;

string compress(string str)
{
    string stack{};
    for ( auto thisChar : str ) {
        if ( thisChar == ']' ) {
            auto posLeftB = stack.rfind('[');
            // 无法解析
            if ( posLeftB == string::npos ) {
                stack += thisChar;
                continue;
            }
            auto expr = stack.substr(posLeftB + 1);
            char* endPos{};
            auto num = strtol(expr.data(), &endPos, 10);
            // 数值不符合
            if ( num < 1 || num > 100 ) {
                stack += thisChar;
                continue;
            }
            // 语法不符合
            if ( *endPos != '|' ) {
                stack += thisChar;
                continue;
            }
            ++endPos;
            // 若正常解析则弹出[|]并压入解压字符
            stack.erase(posLeftB, stack.size() - posLeftB);
            for ( ; num > 0; --num ) {
                stack += endPos;
            }
        } else {
            stack += thisChar;
        }
    }
    return stack;
}

int main()
{
    string i{};
    std::cin  >> std::noskipws >> i;
    std::cout << compress(i) << std::endl;

    return 0;
}
