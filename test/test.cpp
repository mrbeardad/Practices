#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string_view>
#include <utility>
#include <utility>

using std::cin;
using std::cout;

namespace
{
    template <typename T>
    class Base
    {
    public:
        void func() const
        {
            std::cout << "hi" << std::endl;
        }
    private:
        int i_m;
    };

    template <typename T>
    class Derived: Base<T>
    {
    public:
        void test()
        {
            this->func();
        }
    private:
        
    };

    template <typename T>
    void func(T&& t)
    {
        std::cout << t << std::endl;
    }

    template <typename T, typename... Types>
    void func(T&& t, Types&&... args)
    {
        std::cout << t << std::endl;
        func(std::forward<Types>(args)...);
    }

} // namespace

template <template <typename, auto...> class INTS, typename T, T... I>
void test(INTS<T, I...>)
{
    ((std::cout << I), ... );
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto i = 2e24 + 1;
    std::cout << static_cast<float>(i);

    return 0;
}
