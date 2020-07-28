#pragma once

/*
 * Author: Heachen Bear
 * Email: mrbeardad@qq.com
*/

#include <functional>
#include <type_traits>
#include <vector>

namespace mine
{
    class HashGenerator
    {
    public:
        HashGenerator() = default;
        template <typename... Types>
        size_t operator()(Types&&... args);

    private:
        template <typename T, typename... RestTypes>
        void hashTool(T&& t, RestTypes&&... args)
        {
            seed ^= std::hash<std::decay_t<T> >{}(t) + MAGIC_NUM + (seed << 6) + (seed >> 2);
            hashTool(args...);
        }

        template <typename T>
        void hashTool(T&& t)
        {
            seed ^= std::hash<std::decay_t<T> >{}(t) + MAGIC_NUM + (seed << 6) + (seed >> 2);
        }

        static constexpr size_t MAGIC_NUM{0x9e3779b9};
        size_t seed;
    };

    template <typename... Types>
    size_t HashGenerator::operator()(Types&&... args)
    {
        hashTool(args...);
        size_t result = seed;
        seed = 0;
        return result;
    }

    class RCSupport
    {
    public:
        RCSupport() = default;

        int operator++()
        {
            return ++refCnt_m;
        }

        int operator++(int)
        {
            return refCnt_m++;
        }

        int operator--()
        {
            return --refCnt_m;
        }

        int operator--(int)
        {
            return refCnt_m--;
        }

        void increment()
        {
            ++refCnt_m;
        }

        void decrement()
        {
            --refCnt_m;
        }

        bool isShared() const
        {
            return refCnt_m > 1;
        }
    private:
        int refCnt_m;
    };

} // namespace mine

