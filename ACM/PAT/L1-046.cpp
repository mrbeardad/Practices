#include <iostream>
#include <string>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    int need1Int, need1Last ;
    cin >> need1Int ;
    need1Last = need1Int % 10 ;

    int guangGun[10000]{}, result[10000], guangGunLen{}, idx2proc{} ;
    while ( true ) {
        // 获取使guangGun[i] == 1 的 result[i]
        int thisNumInResult{} ;
        for ( int thisNumInGuangGun{ guangGun[idx2proc] }; (need1Last * thisNumInResult + thisNumInGuangGun) % 10 != 1; ++thisNumInResult ) {}
        result[idx2proc] = thisNumInResult ;

        // 获取guangGun中从idx2proc开始的int值
        int intInGuangGun{} ;
        for ( int idx{ idx2proc }, weight{ 1 }; idx < guangGunLen; ++idx, weight *= 10 ) {
            intInGuangGun += guangGun[idx] * weight ;
        }

        // 计算目前的need1Int * result的结果，并准备插入到guangGun中
        int needInsert{ need1Int * thisNumInResult + intInGuangGun } ;

        // 插入当前乘法结果，如果全1则找到结果直接退出
        bool allOne{ true } ;
        int idx{ idx2proc } ;
        for ( int chuShu{ 1 }, thisByte{ needInsert / chuShu }; thisByte; ++idx ) {
            thisByte %= 10 ;
            if ( thisByte != 1 ) {
                allOne = false ;
            }
            guangGun[idx] = thisByte ;
            chuShu *= 10 ;
            thisByte =  needInsert / chuShu ;
        }
        guangGunLen = idx ; // 更新guangGunLen
        if ( allOne ) {
            break ;
        }
        ++idx2proc ;
    }

    // 输出result和numOfOne
    while ( idx2proc >= 0 ) {
        cout << result[idx2proc--] ;
    }
    cout << ' ' << guangGunLen ;

    return 0 ;
}

