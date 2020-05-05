#include <iostream>
#include <array>
#include <vector>
#include <queue>

using namespace std;

constexpr int WORDS{26};

struct Vertex
{
    array<size_t, WORDS> children_m;
    int fail_m;
    bool isEnd_m;
};

struct Trie
{
    vector<Vertex> trie_m;

    void insert(const string& str)
    {
        size_t trieIdx{};
        for ( size_t strIdx{}, strLen{str.size()}; strIdx < strLen; ++strIdx ) { // 循环：插入每个字符直到全部插完。迭代：strIdx，trieId
            auto& nextIdx{trie_m[trieIdx].children_m[str[strIdx] - 'a']}; // 附：子节点的索引
            if ( nextIdx == 0 ) { // 如果不存在该子节点，则添加并更新该节点
                nextIdx = trie_m.size();
                trieIdx = nextIdx; // 附：在push_back()前赋值，因为在之后的话容器重新分配导致nextIdx失效
                trie_m.push_back({});
            } else {
                trieIdx = nextIdx;
            }
        }
        trie_m[trieIdx].isEnd_m = true; // 设置该节点为字符串尾部
    }

    template<typename ...T>
    void build(const T&... strs)
    {
        // 初始化根节点，并插入所有模式串
        trie_m.push_back({});
        (insert(strs), ...);

        // 将第一层节点入队，它们的fail_m都指向根节点，代表最长公共前后缀为0
        queue<size_t> bfsQue;
        for ( size_t childIdx : trie_m[0].children_m ) {
            if ( childIdx != 0 ) {
                bfsQue.push(childIdx);
            }
        }

        while ( !bfsQue.empty() ) {
            auto& parent{trie_m[bfsQue.front()]};
            bfsQue.pop();
            for ( size_t idx{}; idx < WORDS; ++idx ) { // 循环：为所有子节点设置fail_m。迭代：idx
                size_t& childIdx{parent.children_m[idx]};
                if ( childIdx == 0 ) { // 若不存在，为避免匹配时递归跳转fail_m，提前将该点设置为fail_m跳转的终点
                    childIdx = trie_m[parent.fail_m].children_m[idx];
                } else {               // 如果存在该子节点，则将它的fail_m指向其父节点的fail_m节点的相同子节点
                    trie_m[childIdx].fail_m = trie_m[parent.fail_m].children_m[idx];
                    bfsQue.push(childIdx);
                }
            }
        }
    }

    int find(const string& str)
    {
        size_t matchCnt{};
        vector<bool> isOnce(trie_m.size(), true);
        for ( size_t trieIdx{}, strIdx{}, strLen{str.size()}; strIdx < strLen; ) { // 匹配字符串的每个位置
            auto& childIdx{trie_m[trieIdx].children_m[str[strIdx] - 'a']};
            if ( childIdx != 0 ) { // 如果当前位置代表的子串匹配，则计算所有其自身与其所有后缀是否为字符串结尾
                for ( size_t needCntIdx{childIdx}; needCntIdx != 0 && trie_m[needCntIdx].isEnd_m && isOnce[needCntIdx]; needCntIdx = trie_m[needCntIdx].fail_m ) {
                    matchCnt += 1;
                    isOnce[needCntIdx] = false; // 该子串可能是多个长串的尾缀，避免重复计算
                }
                trieIdx = childIdx;
                ++strIdx;
            } else if ( trieIdx != 0 ) { // 如果不匹配，则跳转到一个最长公共前后缀
                trieIdx = trie_m[trieIdx].fail_m;
            } else {
                ++strIdx;
            }
        }
        return matchCnt;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Trie trie;
    trie.build("ab", "bc", "aaa");
    cout << trie.find("abcd");

    return 0;
}

