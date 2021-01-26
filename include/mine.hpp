/*
 * mine.hpp -- My personal header file for C++
 * Copyright (c) 2020 Heachen Bear
 * Author: Heachen Bear
 * Email: mrbeardad@qq.com
 * License: MIT
*/

#ifndef MRBEARDAD_MINE_HPP
#define MRBEARDAD_MINE_HPP 1


#if defined(_GLIBCXX_IOSTREAM) || defined(_IOSTREAM_)
struct CloseSyncWithStdio
{
    CloseSyncWithStdio()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
};
inline CloseSyncWithStdio closeSyncWithStdio{};
#endif // defined(_GLIBCXX_IOSTREAM) || defined(_IOSTREAM_)


#if defined(_GLIBCXX_FILESYSTEM) || defined(_FILESYSTEM_)
namespace fs = std::filesystem;
#endif // defined(_GLIBCXX_FILESYSTEM) || defined(_FILESYSTEM_)


#if defined(_IOS_BASE_H) || defined(_XIOSBASE_)
using io = std::ios_base;
#endif // defined(_IOS_BASE_H) || defined(_XIOSBASE_)


#if defined(_GLIBCXX_THREAD) || defined(_THREAD_)
namespace th = std::this_thread;
#endif // defined(_GLIBCXX_THREAD) || defined(_THREAD_)


#if defined(_GLIBCXX_CHRONO) || defined(_CHRONO_)
namespace ch = std::chrono;
#   if __cplusplus >= 201402
using std::literals::operator""h;
using std::literals::operator""min;
using std::literals::operator""s;
using std::literals::operator""ms;
using std::literals::operator""us;
using std::literals::operator""ns;
#   endif // __cplusplus >= 201402
#endif // defined(_GLIBCXX_CHRONO) || defined(_CHRONO_)


#if defined(_GLIBCXX_STRING) || defined(_STRING_)
#   if __cplusplus >= 201402
using std::literals::operator""s;
#   endif // __cplusplus >= 201402
#endif // defined(_GLIBCXX_STRING) || defined(_STRING_)


#if defined(_GLIBCXX_STRING_VIEW) || defined(_STRING_VIEW_)
#   if __cplusplus >= 201703
using std::literals::operator""sv;
#   endif // __cplusplus >= 201703
#endif // defined(_GLIBCXX_STRING_VIEW) || defined(_STRING_VIEW_)


#if defined(_GLIBCXX_REGEX) || defined(_REGEX_)
inline
std::regex operator""_rgx(const char* str, size_t len)
{
    return std::regex{str, len};
}
inline
std::wregex operator""_rgx(const wchar_t* str, size_t len)
{
    return std::wregex{str, len};
}
#endif // defined(_GLIBCXX_REGEX) || defined(_REGEX_)


#if defined(_GLIBCXX_FUNCTIONAL) || defined(_FUNCTIONAL_)
using namespace std::placeholders;
#endif // defined(_GLIBCXX_FUNCTIONAL) || defined(_FUNCTIONAL_)

#ifdef ASIO_HPP
namespace ip = asio::ip;
using asio::ip::tcp;
using asio::ip::udp;
using asio::ip::icmp;
#endif // ASIO_HPP

#ifdef ASIO_SSL_HPP
namespace ssl = asio::ssl;
#endif // ASIO_SSL_HPP

#ifdef ASIO_HAS_LOCAL_SOCKETS
using unix_stream = asio::local::stream_protocol;
using unix_dgram  = asio::local::datagram_protocol;
#endif // ASIO_HAS_LOCAL_SOCKETS

#include <functional>
#include <type_traits>

namespace mine
{
    template <typename Functor>
    struct YCombinator
    {
        Functor func_;

        template <typename... Args>
        decltype(auto) operator()(Args&&... args)
        {
            return func_(*this, std::forward<Args>(args)...);
        }
    };


    template <typename Functor>
    YCombinator<std::decay_t<Functor> > make_y_conbinator(Functor&& f)
    {
        return {std::forward<Functor>(f)};
    }


#ifdef _STRING_H
template <typename T>
T handle(T sysCallRet)
{
    if ( sysCallRet < 0 ) {
        printf("\033[34m%s\033[m|line %d|%s():\033[33m %s\033[m",
                __FILE__, __LINE__, __func__, strerror(errno));
        exit(1);
    } else {
        return sysCallRet;
    }
}

template <typename T>
T* handle(T* sysCallRet)
{
    if ( sysCallRet == nullptr ) {
        printf("\033[34m%s\033[m|line %d|%s():\033[33m %s\033[m",
                __FILE__, __LINE__, __func__, strerror(errno));
        exit(1);
    } else {
        return sysCallRet;
    }
}
#endif // _STDIO_H

} // namespace mine


#endif  // MRBEARDAD_MINE_HPP

