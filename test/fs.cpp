#include <filesystem>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::filesystem::path file{"~/.cheat/notes"};
    std::cout << file.root_name() << std::endl;
    std::cout << file.root_path() << std::endl;
    std::cout << file.root_directory() << std::endl;
    std::cout << file.relative_path() << std::endl;
    std::cout << file.parent_path() << std::endl;
    std::cout << file.filename() << std::endl;
    std::cout << file.stem() << std::endl;
    std::cout << file.extension() << std::endl;

    return 0;
}

