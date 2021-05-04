#include <iostream>


class Singleton
{
public:
    static Singleton& instance()
    {
        static Singleton instance{};
        std::cout << "contruct" << std::endl;
        return instance;
    }
private:
    Singleton() =default;
    ~Singleton()
    {
        std::cout << "destroy" << std::endl;
    }
};

int main()
{
    auto& i = Singleton::instance();

    return 0;
}

