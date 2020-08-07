#include <filesystem>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::filesystem::directory_entry file{"/tmp/fs.cpp"};
    std::cout << std::boolalpha << file.exists() << std::endl;
    std::cout << file.hard_link_count() << std::endl;

    return 0;
}

