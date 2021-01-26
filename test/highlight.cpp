#include <highlight.hpp>
#define _HIGHLIGHT_

[[[[[[[[[]]]]]]]]]
{{{{{{{{{}}}}}}}}}
((((((((()))))))))
// Normal Comment NonText CursorLine CursorLineNr LineNr MatchParen Search

                                                            // Comment      -1

normal text: customized Type, Function, Identifier          // Normal       0

auto a; char c; int i; double d; string s; decay_t t;       // Type         1 i

extern static volatile const constexpr inline mutable       // StorageClass 2

std::filesystem std::chrono std::ios_base                   // namespace    3

static_cast<>()  decltype()  typeid()  static_assert()      // Operator     4
sizeof()  alignas()  alignof()  operator()()  == && ++ <<

find()  std::search()                                       // Function     5 b

class namespace struct enum union                           // Structure    5
template <typename T> 
template <template <typename> typename T>

cin cout cerr clog _1                                       // Identifier   6
this nullptr true false
is_same_v in out app

0xff, 1'330                                                 // Number       3 b

2.5e8 1e16                                                  // Float        4 b

"string\tis\x20italic\n"                                    // String       7 i

friend virtual public private protected                     // Statement    8
typedef using
explicit noexcept final override delete default
for while do switch case try catch return throw continue break new delete
if else

