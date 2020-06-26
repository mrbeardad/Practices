#include <functional>
#include <iostream>
#include <deque>

using namespace std;

template <typename T, typename CMP = less<T> >
struct MonoStack
{
    deque<T> stk_m;
    CMP cmp_m;

    void push(const T& val)
    {
        while ( !stk_m.empty() && cmp_m(val, stk_m.back()) ) {
            cout << stk_m.back() << ": " << val << endl;
            stk_m.pop_back();
        }
        stk_m.push_back(val);
    }

    void pop()
    {
        stk_m.pop_back();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    MonoStack<int> monoStk;
    for ( int tmp4stk{}; cin >> tmp4stk; ++tmp4stk ) {
        monoStk.push(tmp4stk);
    }

    return 0;
}

