#include <algorithm>
#include <array>
#include <bitset>
#include <boost/locale.hpp>
#include <cfloat>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <execution>
#include <ext/stdio_filebuf.h>
#include <filesystem>
#include <fmt/core.h>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <mutex>
#include <random>
#include <regex>
#include <set>
#include <signal.h>
#include <sstream>
#include <string>
#include <string.h>
#include <string_view>
#include <sys/wait.h>
#include <thread>
#include <tuple>
#include <unicode/display_width.hpp>
#include <unistd.h>
#include <utility>
#include <variant>

#include "mine.hpp"

std::mutex M{};

void test_thread_stack()
{
    char buf[4096]{};
    std::this_thread::sleep_for(1s);
    std::lock_guard lg{M};
    std::cout << static_cast<void*>(buf) << std::endl;
}

struct A
{
    int     i_;
    double  d_;
    std::strong_ordering operator<=>(const A& a) const =default;
    struct T;
};

void test_gperftools()
{
    std::vector<double> v(1024000);
    std::iota(v.begin(), v.end(), 1.1);
    std::cout << std::accumulate(v.begin(), v.end(), 0) << std::endl;
    std::cout << std::inner_product(v.begin(), v.end(), v.begin(), 0) << std::endl;
}

void test_pipe_to_less()
{
    auto    pager = getenv("PAGER");
    int     fds[2]{};
    mine::handle(pipe(fds));
    if ( auto pid = mine::handle(fork()); pid == 0 ) {
        dup2(fds[0], STDIN_FILENO);
        close(fds[1]);
        // close(fds[0]);
        mine::handle(execlp(pager, pager, nullptr));
    } else {
        dup2(fds[1], STDOUT_FILENO);
        close(fds[1]);
        // close(fds[0]);
    }
    std::cout << "fuck" << std::endl;
    close(1);
    wait(nullptr);
}


void test_sstrm()
{
        std::stringstream   sstrm{"     > [fuck](http://fuck.you)"};
        std::string         quote{};
        char                c{};
        sstrm >> std::noskipws;
        quote.clear();
        // for ( std::string head{}, normal{}; sstrm >> quote; ) {
        //     std::cout << "fuck!" << head << std::endl;
        //     std::getline(sstrm, normal);
        //     quote += "\033[48;5;235m\033[38;5;240m" + head + "\033[m" + normal + "\n";
        // }
        sstrm >> c;
        std::cout << c << ":" << std::endl;
        sstrm >> quote;
        std::cout << quote << ":" << std::endl;
}

void test_smatch()
{
    std::cmatch headMatch{};
    std::regex_search(" * fuckyou", headMatch, R"(^([+*-]\s+))"_rgx);
    auto head   = headMatch.format("\033[36m$1\033[m");
    auto normal = headMatch.prefix().str();
    std::cout << head << std::endl;
    std::cout << normal << std::endl;
}


void test_ignore()
{
    std::stringstream sstrm{"fuck\nyou"};
    sstrm.ignore(512, '\n');
    char c{};
    sstrm.get(c);
    std::cout << c << std::endl;
}

#include <srchilite/sourcehighlight.h>
void test_sourcehighlight()
{
    srchilite::SourceHighlight  sh{"esc.outlang"};
    std::fstream                cpp{"test.cpp"};
    std::stringstream           sstrm{};
    sh.highlight(cpp, sstrm, "cpp.lang");
    std::cout << sstrm.str() << std::endl;
}

void test_regex()
{
    std::cout << std::regex_replace("<!--[fuck](http://fuckyou.com)-->", R"((<!--.*?-->))"_rgx, "\033[31m$1\033[m");
}

void test_display_width()
{
    std::cout << unicode::display_width("\033[36mfuckyou"s) << std::endl;
}


int main(int argc, char* argv[])
{
    test_display_width();

    return 0;
}
