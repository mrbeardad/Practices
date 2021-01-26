cmake_minimum_required(VERSION 3.10)

project(SeeCheatSheet VERSION 1.0)

add_executable(see src/see.cpp)

set(CMAKE_CXX_STANDARD 20)

#include <unicode/display_width>
message(STATUS 'Downloading p-ranav/unicode_display_width ...')
file(DOWNLOAD
    https://github.com/p-ranav/unicode_display_width/raw/master/include/unicode/display_width.hpp
    include/unicode/display_width.hpp
)
add_library(unicod_display_width INTERFACE)
target_include_directories(unicod_display_width
    PUBLIC
        include/unicode/display_width.hpp
)
target_link_libraries(see
    PRIVATE
        unicod_display_width
)

#include <boost/locale.hpp>
find_package(Boost 1.75
    REQUIRED
    locale
)
target_link_libraries(see
    PRIVATE
        Boost_locale
)

#include <srchilite/sourcehighlight.h>
