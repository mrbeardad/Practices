#include <iostream>
#include <memory>
#include <sstream>

#include "mine.hpp"

struct B
{
    int i_;
    std::shared_ptr<B> get_this()
    {
        return std::shared_ptr<B>(this);
    }
    virtual int get()
    {
        return i_;
    }
    virtual ~B() =default;
};

struct D : public B
{
    double d_;
    virtual int get() override
    {
        return d_;
    }

    ~D() {std::cout << "destory D" << std::endl;}
};

int main()
{
    std::stringstream strm{"fuck you"};
    std::string s{};
    strm >> s;
    std::cout << s << std::endl;
    std::cout << strm.rdbuf()->pubseekoff(-4, io::cur, io::in | io::out) << std::endl;
    // strm.rdbuf()->pubseekoff(-static_cast<int>(s.size()), io::cur);
    // std::cout << -static_cast<int>(s.size()) << std::endl;
    strm >> s;
    std::cout << s << std::endl;

    return 0;
}

