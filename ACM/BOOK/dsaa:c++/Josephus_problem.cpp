/*
 * 定时炸弹游戏，N个人围成圈，每此炸弹传递M次，炸死一个后炸弹由下一位接手继续，直到某人吃鸡成功。
 */

#include <iostream>
#include <list>

using namespace std ;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int personNum{atoi(argv[1])}, transNum{atoi(argv[2])} ;
    list<int> restPerson ;
    for (int i = 1; i <= personNum; ++i) {
        restPerson.push_back(i) ;
    }

    auto cur{restPerson.begin()} ;
    while (restPerson.size() != 1) {
        for (int i{0}; i != transNum; ++i) {
            ++cur ;
            if (cur == restPerson.end()) {
                cur = restPerson.begin() ;
            }
        }
        auto curErase{cur++} ;
        restPerson.erase(curErase) ;
        if (cur == restPerson.end()) { // Line 20 will case segment fault if cur equal to .end() at first.
            cur = restPerson.begin() ;
        }
    }
    cout << restPerson.front() << endl ;
    cout << restPerson.size() << endl ;

    return 0 ;
}
