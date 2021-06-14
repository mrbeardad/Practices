#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include <mine.hpp>


namespace
{
    void do_entry(std::stringstream& entry);
} // namespace


int main(int argc, char* argv[])
{
    if ( argc != 2 ) {
        std::cout << argv[0] << ": need one argument!" << std::endl;
        exit(1);
    }

    constexpr auto BEGIN_LINE = 1965, END_LINE = 2016;
    std::regex entryBegin{R"(<!-- entry begin:.*-->)"}, entryEnd{R"(<!-- entry end -->)"};
    std::fstream cheat{argv[1], io::in | io::out};
    std::istreambuf_iterator<char> itr2Begin{cheat}, itr2FinalEnd{};
    std::stringstream entry{};
    std::string oneLine{};

    for ( int lineNo{}; lineNo < BEGIN_LINE - 1 && itr2Begin != itr2FinalEnd; ++itr2Begin ) {
        if ( *itr2Begin == '\n' ) ++lineNo;
    }
    auto isInEntry = false;
    for ( auto lineNo = BEGIN_LINE; lineNo <= END_LINE && std::getline(cheat, oneLine); ++lineNo ) {
        if ( !isInEntry && std::regex_match(oneLine, entryBegin) ) {
            isInEntry = true;
            entry << oneLine << '\n';
        } else if ( isInEntry ) {
            entry << oneLine << '\n';
            if ( std::regex_match(oneLine, entryEnd) ) {
                isInEntry = false;
                do_entry(entry); // flush entry
                entry.clear();
                entry.str("");
            }
        } else if ( !isInEntry ) {
            std::cout << oneLine << std::endl;
        }
    }

    return 0;
}


namespace
{
    void do_entry(std::stringstream& entry)
    {
        constexpr auto INS_DIX = 18UL;
        std::string entryKeys{}, oneLine{};
        std::regex funcName{R"(\S+\s*(\w+)\(.*\).*)"};

        std::getline(entry, entryKeys);
        // std::cout << "=======================================================================" << std::endl;
        // std::cout << entryKeys << std::endl;
        // std::cout << "=======================================================================" << std::endl;

        while ( std::getline(entry, oneLine) ) {
            entryKeys.insert(INS_DIX, std::regex_replace(oneLine, funcName, "$1 ", std::regex_constants::format_no_copy));
        }

        std::cout << entryKeys << std::endl;
        auto strmbuf = entry.str();
        strmbuf.erase(0, strmbuf.find('\n')+1);
        std::cout << strmbuf << std::flush;
    }
} // namespace

