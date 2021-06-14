#include <boost/serialization/shared_ptr.hpp>
#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<std::string, int> umap{R"({ "one": 1, "two": 2})"_json.get<std::unordered_map<std::string,int> >()};
    std::for_each(umap.begin(), umap.end(), [](auto&& t){std::cout << t.first << " : " << t.second << std::endl;});

    return 0;
}

