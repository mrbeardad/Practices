#include <iostream>

struct Base
{
    virtual void test()
    {
        std::cout << "Base" << std::endl;
    }
};

struct Derive : public Base
{
    void test() override
    {
        std::cout << "Derive" << std::endl;
    }
};

struct DeriveDerive : public Derive
{
    void test() override
    {
        std::cout << "DeriveDerive" << std::endl;
    }
};

int main()
{
    Base* b = new DeriveDerive{};
    b->test();

    return 0;
}
