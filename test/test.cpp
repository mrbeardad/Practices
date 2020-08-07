#include <cmath>
#include <iostream>
#include <regex>
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

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cout << std::regex_replace("thisisatest.", std::regex{R"(((is)\2))"}, "$``\e[36m$&\e[m$''");

    return 0;
}
