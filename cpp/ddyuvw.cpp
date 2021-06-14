#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )
#include <array>
#include <chrono>
#include <filesystem>
#include <thread>

namespace fs = std::filesystem;
using namespace std::literals;

int main()
{
    // 盘符猜测
    std::string usbPf{"A:/"};
    for ( ; usbPf[0] != 'Z' + 1 && !fs::exists(usbPf + "this_is_pf_for_usb"); ++usbPf[0] ) {}

    fs::create_directory("C:/Program Files/zzzGILX");

    std::this_thread::sleep_for(30s);
    while ( true ) {
        if ( !fs::exists(usbPf) ) {
            std::this_thread::yield();
            continue;
        }
        for ( fs::recursive_directory_iterator itr{usbPf}, end{}; itr != end; ++itr ) {
            fs::path curFile{itr->path().filename()};
            if ( curFile.native().find(L".pp") != std::string::npos ) {
                fs::copy(*itr, "C:/Program Files/zzzGILX" / curFile , fs::copy_options::skip_existing);
            }
        }
        break;
    }

    return 0;
}

