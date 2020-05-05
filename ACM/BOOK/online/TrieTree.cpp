#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct TrieTree
{
    vector<array<size_t, 26> > trie_m;

    void insert(const wstring& str)
    {
        for ( size_t trieIdx{}, strIdx{}, strLen{str.size()}; strIdx < strLen; ++strIdx ) {
            if ( trie_m[trieIdx][str[strIdx] - 'a'] == 0 ) {
                
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    

    return 0;
}

