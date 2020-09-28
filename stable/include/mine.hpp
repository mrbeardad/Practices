#if defined(_GLIBCXX_FILESYSTEM) || defined(_FILESYSTEM_)
namespace fs = std::filesystem;
#endif

#if defined(_GLIBCXX_CHRONO) || defined(_CHRONO_)
namespace std_co = std::chrono;
using std::literals::operator""h;
using std::literals::operator""min;
using std::literals::operator""s;
using std::literals::operator""ms;
using std::literals::operator""us;
using std::literals::operator""ns;
#endif

#if defined(_GLIBCXX_STRING) || defined(_STRING_)
using std::literals::operator""s;
#endif

#if defined(_GLIBCXX_STRING_VIEW) || defined(_STRING_VIEW_)
using std::literals::operator""sv;
#endif

#if defined(_IOS_BASE_H) || defined(_XIOSBASE_)
using ios = std::ios_base;
#endif

#define int int32_t
#define long int64_t
