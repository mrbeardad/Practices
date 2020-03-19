#include <functional>
#include <type_traits>
#include <vector>

namespace my_header
{
    class MyHash
    {
    public:
        template <typename ...Types>
        size_t operator()(Types&&... args)
        {
            hashTool( args... ) ;
            size_t result = seed ;
            seed = 0 ;
            return result ;
        }

    private:
        template <typename T, typename ...RestTypes>
        void hashTool(T&& t, RestTypes&&... args)
        {
            using real_type = std::decay_t<T> ;
            seed ^= std::hash<real_type>{}((std::decay_t<real_type>)t) + 0x9e3779b9 + (seed << 6) + (seed >> 2) ;
            hashTool(args...) ;
        }

        template <typename T>
        void hashTool(T&& t)
        {
            using real_type = std::decay_t<T> ;
            seed ^= std::hash<real_type>{}(t) + 0x9e3779b9 + (seed << 6) + (seed >> 2) ;
        }

        size_t seed = 0 ;
    } ;

    class DisjointSet
    {
    public:
        DisjointSet(size_t num): ds(num, -1) {}

        int find(int thisIdx)
        {
            if ( thisIdx < 0 ) {
                return thisIdx ;
            }
            ds[thisIdx] = find(ds[thisIdx]) ;
            return ds[thisIdx] ;
        }

        bool merge(int formerIdx, int laterIdx)
        {
            int root1{ find(formerIdx) }, root2{ find(laterIdx) } ;
            bool ret{ root1 == root2 ? true : false } ;
            if ( ds[root1] <= ds[root2] ) {
                if ( ds[root1] == ds[root2] ) {
                    --ds[root1] ;
                }
                ds[root2] = root1 ;
            } else {
                ds[root1] == root2 ;
            }
            return ret ;
        }

    private:
        std::vector<int> ds ;
    } ;
}

