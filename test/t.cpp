/**
 * Copyright (c) 2020-2021 Heachen Bear & Contributors
 * File              : t.cpp
 * License           : GPLv3
 * Author            : Heachen Bear <mrbeardad@qq.com>
 * Date              : 09.02.2021
 * Last Modified Date: 09.02.2021
 * Last Modified By  : Heachen Bear <mrbeardad@qq.com>
 */

#include <iostream>
#include <string>
#include <unistd.h>

int main()
{
#if defined(NDEBUG)
    std::cout << "hello" << std::endl;
#else
    std::string s{};
    std::cin >> s;
    std::cout << "fuck: " << s  << std::endl;
    system("zsh");
    pause();
#endif // defined(NDEBUG)

    return 0;
}

