#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <unistd.h>
#include <vector>

int main()
{
    std::cout << requires(int i){i+i;} << std::endl;
    return 0;
}

