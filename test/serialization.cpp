#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <yas/serialize.hpp>
#include <yas/std_types.hpp>

#include <mine.hpp>

void test_mem()
{
    std::map<std::string, std::string> mapObj{{"A", "a"}, {"B", "b"}, {"C", "c"}};
    auto buf = yas::save<yas::mem | yas::json>(YAS_OBJECT("test_mem", mapObj));
    std::cout << buf.data.get() << std::endl;
}

void test_yas()
{
    std::map<int, int> map{{1, 1}, {2, 2}, {3, 3}};
    std::map<std::string, int> obj{{"a", 1}, {"b", 2}, {"c", 3}};
    std::remove("file");
    yas::save<yas::file | yas::json>("file", YAS_OBJECT("obj", map, obj));
    std::cout << std::ifstream{"file"}.rdbuf();

    v.clear();
    yas::load<yas::file | yas::json>("json", YAS_OBJECT_NVP("j", ("map", obj), ("vector", v)));
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>{std::cout, ", "});
}

int main(int argc, char* argv[])
{
    test_mem();
    test_mem();
    test_mem();
    test_mem();

    return 0;
}

