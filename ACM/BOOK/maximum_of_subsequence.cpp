/*
 * 子序列的最大值
 * 条件：最大值为负数则算作0
 * 输入：整数序列
 * 输出：拥有最大值对子序列的相关数据
 */
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std ;

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    vector<int> allSeq ;
    for ( int tmp{}; cin >> tmp; ) {
        allSeq.push_back(tmp) ;
    }

    using answer_type = tuple<size_t, size_t, int> ; // <begin, end, val>
    auto ld{ [](const answer_type& former, const answer_type& later){return get<2>(former) < get<2>(later);} } ; // lambda用于比较大小
    priority_queue<answer_type, vector<answer_type>, decltype(ld)> maxSeq{ ld } ; // 用于找出最大的子序列

    size_t thisBegin{}, thisEnd{} ;
    int nowMax{} ;
    int thisSum{} ;
    size_t pos{} ; // 需要在循环外访问
    for ( auto end{ allSeq.size() }; pos < end; ) {
        thisSum += allSeq[pos] ;
        if ( thisSum  < 0 ) {
            maxSeq.push( tuple{ thisBegin, thisEnd, nowMax } ) ;
            while ( allSeq[++pos] < 0 && pos < end ) ;
            thisBegin = pos ; // 更新操作变量
            nowMax = 0 ;
            thisSum = 0 ;
            continue ;
        }
        if ( thisSum > nowMax ) {
            nowMax = thisSum ;
            thisEnd = pos ;
        }
        ++pos ;
    }
    if ( thisBegin != pos ) {
        maxSeq.push( tuple{ thisBegin, thisEnd, nowMax } ) ;
    }

    if ( auto result{ maxSeq.top() }; get<2>(result) < 0 ) {
        cout << "All subsequences are negative!" ;
    } else {
        cout << "The max subsequence is begin at " << get<0>(result) << " and end at " << get<1>(result) << " with value " << get<2>(result) ;
    }

    return 0 ;
}
