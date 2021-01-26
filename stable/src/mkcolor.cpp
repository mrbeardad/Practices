/************************************************
 * mkcolor.cpp -- A program to colour text from stdin
 * Copyright (c) 2020 Heachen Bear
 * Author: Heachen Bear < mrbeardad@qq.com >
 * License: Apache
 ************************************************/

#include <algorithm>
#include <codecvt>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <istream>
#include <locale>
#include <nlohmann/json.hpp>
#include <ostream>
#include <sstream>
#include <string>
#include <tuple>
#include <unistd.h>
#include <unordered_map>
#include <vector>

#define int int32_t
#define long int64_t

namespace
{
    class Color
    {
    public:
        Color();
        Color(int block, int shift, const std::string& json);

        std::wstring color_oneline(const std::wstring& oneline);
        void color_all(std::wostream& output, std::wistream& input);

        static inline std::unordered_map<std::string, const wchar_t*> AnsiColors{
            {"black",   L"\033[30m"},
            {"magenta", L"\033[31m"},
            {"green",   L"\033[32m"},
            {"yellow",  L"\033[33m"},
            {"blue",    L"\033[34m"},
            {"purple",  L"\033[35m"},
            {"cyan",    L"\033[36m"},
            {"white",   L"\033[37m"},
            {"none",    L"\033[m"}
        };

    private:
        int fstColor_m;     // 第一个色块的颜色
        int fstEnd_m;       // 第一个色块尾后索引
        int colorBlock_m;   // 色块宽度
        int colorShift_m;   // 下行色块位移大小
        std::vector<std::wstring> colors_m;
    };


    Color::Color() = default;


    Color::Color(int block, int shift, const std::string& json): fstColor_m{}, fstEnd_m{}, colorBlock_m{block}, colorShift_m{shift}
    {
        if ( json.empty() ) {
            colors_m = {
            L"\033[31m",
            L"\033[34m",
            L"\033[35m",
            L"\033[33m",
            L"\033[32m",
            L"\033[36m",
            L"\033[37m",
            L"\033[36m",
            L"\033[32m",
            L"\033[33m",
            L"\033[35m",
            L"\033[34m",
        };
            return;
        }

        // 解析json，获取用户指定颜色
        std::vector<std::string> tmpColors{};
        std::ifstream jsonStrm{json, std::ios_base::in};
        if ( !jsonStrm ) {
            std::cout << "\033[31mError:\033[m no such file - " << json << std::endl;
            std::exit(EXIT_FAILURE);
        }
        nlohmann::json jsonColor{};
        jsonStrm >> jsonColor;
        try {
            jsonColor.get_to(tmpColors);
        } catch ( nlohmann::detail::type_error& excpt ) {
            std::cout << "\033[31mError:\033[m " << excpt.what() << " in file " << json << std::endl;
        }

        std::wstring_convert<std::codecvt_utf8<wchar_t> > cvtor{};
        for ( auto& thisColor : tmpColors ) {
            try {
                if ( thisColor[0] == '#' ) {
                    colors_m.emplace_back(cvtor.from_bytes(
                        "\033[38;2;"
                        + std::to_string(std::stoi(thisColor.substr(1, 2), nullptr, 16)) + ';'
                        + std::to_string(std::stoi(thisColor.substr(3, 2), nullptr, 16)) + ';'
                        + std::to_string(std::stoi(thisColor.substr(5, 2), nullptr, 16)) + 'm'
                    ));
                } else {
                    colors_m.emplace_back(AnsiColors.at(thisColor));
                }
            } catch (...) {
                std::cout << "\033[31mError:\033[m invalid color - " << thisColor << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }


    std::tuple<int, int, std::string> parse_cmdline(int argc, char* argv[]) noexcept
    {
        int block{2}, shift{1}; // 默认参数
        std::string json{};
        while ( true )
        {
            auto choice = getopt(argc, argv, "hb:n:f:");
            if ( choice == -1 ) {
                break;
            }
            switch ( choice ) {
                case 'h':
                    std::cout << "\033[32mUsage:\033[m cat need_to_colour_file | mkcolr [-b2] [-n1] [-fcolor.json]\n" << std::endl;
                    std::cout << "  -b      :specify color block size." << std::endl;
                    std::cout << "  -s      :specify color shift size.\n" << std::endl;
                    std::cout << "Json file example:" << std::endl;
                    std::cout << R"([ "black", "magenta", "green", "yellow", "blue", "purple", "cyan", "white", "#d7dfff", "none" ])" << std::endl;
                    std::exit(EXIT_SUCCESS);
                    break;
                case 'b':
                    char* ptr4err;
                    block = std::strtol(optarg, &ptr4err, 10);
                    if ( ptr4err == optarg ) {
                        std::cout << "\033[31mError:\033[m parameter of option `-b` must greater than 0!" << std::endl;
                        std::exit(EXIT_FAILURE);
                    }
                    break;
                case 's':
                    shift = std::strtol(optarg, &ptr4err, 10);
                    if ( ptr4err == optarg ) {
                        std::cout << "\033[31mError:\033[m parameter of option `-s` must greater than 0!" << std::endl;
                        std::exit(EXIT_FAILURE);
                    }
                    break;
                case 'f':
                    json = optarg;
                    break;
                case '?':
                    std::cout << "\033[31mError:\033[m Syntax Error!\nuse option `-h` for help messages." << std::endl;
                    std::exit(EXIT_FAILURE);
                    break;
            }
        }
        return {block, shift, std::move(json)};
    }


    std::wstring Color::color_oneline(const std::wstring& oneline)
    {
        std::wstring retStr{colors_m[fstColor_m] + oneline.substr(0, fstEnd_m)};
        int colorNum(colors_m.size());
        auto colorIdx = (fstColor_m + 1) % colorNum;

        for ( int blockIdx{fstEnd_m}, blockNum(oneline.size()); blockIdx < blockNum; blockIdx += colorBlock_m ) {
            retStr += colors_m[colorIdx] + oneline.substr(blockIdx, colorBlock_m);
            colorIdx = (colorIdx + 1) % colorNum;
        }

        return retStr;
    }


    void Color::color_all(std::wostream& output, std::wistream& input)
    {
        std::wstring oneline{};
        int colorNum(colors_m.size());

        while ( std::getline(input, oneline) ) {
            output << color_oneline(oneline) << L'\n';
            fstEnd_m += colorShift_m;
            if ( fstEnd_m > colorBlock_m ) {
                fstColor_m = (fstColor_m - fstEnd_m / colorBlock_m + colorNum) % colorNum;
                fstEnd_m %= colorBlock_m;
            }
        }
        output << AnsiColors["none"] << std::flush;
    }
} // namespace


int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 宽字符转换器
    std::wbuffer_convert<std::codecvt_utf8<wchar_t> > utf8ToW{std::cin.rdbuf()};
    std::wistream input{&utf8ToW};
    std::wbuffer_convert<std::codecvt_utf8<wchar_t> > W2Utf8{std::cout.rdbuf()};
    std::wostream output{&W2Utf8};

    auto [block, shift, json] = parse_cmdline(argc, argv);
    Color color{block,  shift, json};
    color.color_all(output, input);

    return 0;
}

