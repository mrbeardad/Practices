#include <iomanip>
#include <iostream>
#include <mysql++/mysql++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    mysqlpp::Connection con{"test"};
    auto query = con.query("select * from person;");
    auto rlt = query.store();

    std::cout << con.client_version() << std::endl;
    std::cout << con.ipc_info() << std::endl;
    std::cout << con.protocol_version() << std::endl;
    std::cout << con.server_status() << std::endl;
    std::cout << std::left;
    std::cout << std::setw(20) << "name" << std::setw(20) << "phone" << "email\n";
    for ( auto pos{rlt.begin()}, end = rlt.end(); pos < end; ++pos ) {
        auto& curRow = *pos;
        std::cout << std::setw(20) << curRow["name"] << std::setw(20) << curRow["phone"] << std::setw(20) << curRow["email"] << '\n';
    }

    return 0;
}

