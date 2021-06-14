#include <iostream>
#include <limits>

class TestCopy
{
    std::string s_;
public:
    TestCopy() =default;

    TestCopy(const TestCopy& other) : s_{other.s_} {
        std::cout << "copy" << std::endl;
    }

    TestCopy(TestCopy&& other) : s_{std::move(other.s_)} {
        std::cout << "move" << std::endl;
    }
};

int main() {
    TestCopy t{};
    std::cout << "===========" << std::endl;
    auto t1 = TestCopy{};
    TestCopy t2{t1};

    return 0;
}
