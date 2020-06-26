#include <array>
#include <c++/9.3.0/x86_64-pc-linux-gnu/bits/c++config.h>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Vertex
{
    array<size_t, 26> next_m;
    bool isEnd_m;
};

struct Trie
{
    vector<Vertex> tree_m;

    explicit Trie(): tree_m{Vertex{}} {}

    void insert(const string& insetStr)
    {
        int trieIdx{};
        for ( char thisChar : insetStr ) {
            size_t& nextIdx{tree_m[trieIdx].next_m[thisChar - 'a']};
            if ( nextIdx == 0 ) {
                trieIdx = nextIdx = tree_m.size();
                tree_m.push_back({});
            } else {
                trieIdx = nextIdx;
            }
        }
        tree_m[trieIdx].isEnd_m = true;
    }

    bool match(const string& matchStr)
    {
        int strIdx{}, strEnd = matchStr.size(), trieIdx{};
        int nextIdx{};
        while ( strIdx < strEnd && (nextIdx = tree_m[trieIdx].next_m[matchStr[strIdx] - 'a']) != 0 ) {
            ++strIdx; 
            trieIdx = nextIdx;
        }
        return strIdx == nextIdx && tree_m[trieIdx].isEnd_m;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Trie t;
    t.insert("hello");
    t.insert("hi");
    t.insert("how");
    t.insert("fuck");
    cout << t.match("hello") << endl;  

    return 0;
}

