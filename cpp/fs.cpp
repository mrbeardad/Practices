#include <asio.hpp>
#include <filesystem>
#include <iostream>

double readable_size_tool(double nbytes, int& times)
{
    if ( nbytes < 1024 ) {
        return nbytes;
    }
    return readable_size_tool(nbytes / 1024, ++times);
}

std::string readable_size(double nbytes)
{
    static char Unites[]{'B', 'K', 'M', 'G', 'T', 'P', 'E'};
    int times{};
    nbytes = readable_size_tool(nbytes, times);
    if ( times >= 7 ) {
        std::cout << "too large" << std::endl;
        exit(1);
    }
    return std::to_string(nbytes) + Unites[times];
}


int main()
{
    

    return 0;
}

int not_main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::initializer_list il{1,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,1};
    il.size();
    // for ( fs::recursive_directory_iterator itr{getenv("HOME")+"/.cheat"s}, end{}; itr != end; ++itr ) {
        // std::cout << itr->path() << ' ' << itr.depth() << std::endl;
        // if ( itr->path().filename() == "hooks" ) {
            // itr.disable_recursion_pending();
        // }
    // }
    // std::filesystem::path file{"/home/beardad/.cheat/README.md"};
    // std::cout << readable_size(fs::space(file).capacity) << std::endl;
    // std::cout << readable_size(fs::space(file).free) << std::endl;
    // std::cout << readable_size(fs::space(file).available) << std::endl;
    // std::cout << file.root_name() << std::endl;
    // std::cout << file.root_path() << std::endl;
    // std::cout << file.root_directory() << std::endl;
    // std::cout << file.relative_path() << std::endl;
    // std::cout << file.parent_path() << std::endl;
    // std::cout << file.filename() << std::endl;
    // std::cout << file.stem() << std::endl;
    // std::cout << file.extension() << std::endl;

    return 0;
}

