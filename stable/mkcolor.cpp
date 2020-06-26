#include <array>
#include <codecvt>
#include <cstddef>
#include <iostream>
#include <istream>
#include <locale>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

constexpr int DIFF_COLOR_GAP{2};

class Color
{
public:
    Color(): curColorIdx_m{}, fstColorIdx_m{}, status_m{} {}

    size_t status() const
    {
        return status_m;
    }

    const wchar_t* color()
    {
        size_t orgIdx{curColorIdx_m};
        curColorIdx_m = (curColorIdx_m + 1) % Colors_m.size();
        return Colors_m[orgIdx];
    }

    Color& operator++()
    {
        if ( status_m == 0 ) {
            fstColorIdx_m = (fstColorIdx_m - 1 + Colors_m.size()) % Colors_m.size();
        }
        curColorIdx_m = fstColorIdx_m;
        status_m = (status_m + 1) % DIFF_COLOR_GAP;
        return *this;
    }

private:
    size_t curColorIdx_m;
    size_t fstColorIdx_m;
    int status_m;
    static inline array Colors_m{
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
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    wbuffer_convert<codecvt_utf8<wchar_t> > utf8ToW{cin.rdbuf()};
    wistream wInput{&utf8ToW};
#ifdef WBUF
    wbuffer_convert<codecvt_utf8<wchar_t> > W2Utf8{cout.rdbuf()};
    wostream finalOut{&W2Utf8}; // ~~为啥用该组件，输出的时候结尾处老是少几个字符~~，原因是因为最后会有字符留在缓冲区为冲刷。。。什么玩意儿，为啥给我剩几个，玛德
#else
    wostringstream finalOut;
#endif
    wstring oneLine;
    Color curColor;
    while ( getline(wInput, oneLine) ) {
        // once
        size_t wstrLen{oneLine.length()}, wstrIdx{curColor.status()};
        if ( wstrIdx != 0 ) {
            finalOut << curColor.color();
            for ( size_t idx{}; idx < wstrLen && idx < wstrIdx; ++idx ) {
                finalOut.put(oneLine[idx]);
            }
        }

        // 循环
        while ( wstrIdx + DIFF_COLOR_GAP <= wstrLen ) {
            finalOut << curColor.color();
            finalOut.write(&oneLine[wstrIdx], DIFF_COLOR_GAP);
            wstrIdx += DIFF_COLOR_GAP;
        }

        // 尾后处理
        finalOut << curColor.color();
        while ( wstrIdx < wstrLen ) {
            finalOut.put(oneLine[wstrIdx++]);
        }
        finalOut << '\n';

        // 换行，更新status_m与curColorIdx_m
        ++curColor;
    }
#ifndef WBUF
    wstring_convert<codecvt_utf8<wchar_t> > cvt;
    cout << cvt.to_bytes(finalOut.str());
#else
    finalOut << endl;
#endif

    return 0;
}

