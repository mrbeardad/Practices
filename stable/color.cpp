#include <iostream>
#include <string_view>
#include <string>
#include <array>
#include <codecvt>
#include <locale>
#include <utility>

using namespace std ;

class NextColor
{
    public:
        NextColor(): secondBegin_m{ 1 }, nowColor_m{ -1 } {}

        pair<size_t, size_t> operator()()
        {
            secondBegin_m = (secondBegin_m + 2) % 4 ;
            nowColor_m = secondBegin_m == 3 ? nowColor_m + 1 : nowColor_m ;
            return pair{nowColor_m, secondBegin_m} ;
        }

        const char*
        operator[](size_t idx)
        {
            return Colors[idx] ;
        }

private:
    int secondBegin_m ;
    int nowColor_m ;

    static inline array<const char*, 16> Colors{
                                                 "\e[m\e[1;31m",
                                                 "\e[m\e[1;34m",
                                                 "\e[m\e[1;35m",
                                                 "\e[m\e[1;33m",
                                                 "\e[m\e[1;32m",
                                                 "\e[m\e[1;36m",
                                                 "\e[m\e[1;37m",
                                                 "\e[m\e[1;36m",
                                                 "\e[m\e[1;32m",
                                                 "\e[m\e[1;33m",
                                                 "\e[m\e[1;35m",
                                                 "\e[m\e[1;34m",
                                                 "\e[m\e[1;31m",
                                                 "\e[m\e[1;34m",
                                                 "\e[m\e[1;35m",
                                                 "\e[m\e[1;33m",
                                               } ;
} ;

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    string oneLine ;
    wstring wOneLine ;
    NextColor nc ;
    std::wstring_convert<codecvt_utf8<wchar_t>> convertor ; // 编码转换器不支持wstring_view

    while ( getline( cin, oneLine ) ) {
        wOneLine = convertor.from_bytes(oneLine) ;
        auto nextStep{ nc() } ;
        size_t firstColor{ nextStep.first } ;
        size_t secondBegin{ nextStep.second } ;

        cout << nc[firstColor % 16] << convertor.to_bytes(wOneLine.substr( 0, secondBegin )) ; // 第一个块的宽度不定，需要单独输出
        size_t end{ wOneLine.size() } ;
        while ( secondBegin + 2 < end ) {
            cout << nc[++firstColor % 16] << convertor.to_bytes(wOneLine.substr( secondBegin, 3 )) ;
            secondBegin += 3 ;
        }
        if ( secondBegin < end ) {
            cout << nc[++firstColor % 16] << convertor.to_bytes(wOneLine.substr(secondBegin)) ;
        }
        cout << '\n' ;
    }

    return 0 ;
}

