#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    array<int, 100> numInFriendCircle ;
    unordered_multimap<int, pair<size_t, bool>> friendCircle{ 100 } ; // Umap<FriendID, <idx, isAlreadyFinded>>

    int numCircle ;
    cin >> numCircle ;
    for ( size_t arrIdx{}; numCircle; ++arrIdx, --numCircle ) {
        int numFriend ;
        cin >> numFriend ;
        numInFriendCircle[arrIdx] = numFriend ;

        while ( numFriend-- ) {
            int tmp4friend ;
            cin >> tmp4friend ;
            friendCircle.insert( { tmp4friend, { arrIdx, false } } ) ;
        }
    }

    unordered_set<int> noFriend ;
    stringstream output ;
    int needFind ;
    cin >> needFind ;
    while ( cin >> needFind ) {
        auto iterPair{ friendCircle.equal_range( needFind ) } ;
        if ( iterPair.first == iterPair.second ) {
            if ( noFriend.find( needFind ) == noFriend.end() ) {
                output << needFind << ' ' ;
                noFriend.insert( needFind ) ;
            }
            continue ;
        }
        if ( (*iterPair.first).second.second ) {
            continue ;
        }

        bool isHandsome{ true } ;
        for ( auto pos{ iterPair.first }, end{ iterPair.second }; pos != end; ++pos ) {
            if ( numInFriendCircle[(*pos).second.first] > 1 ) {
                isHandsome = false ;
                break ;
            }
        }
        if ( isHandsome ) {
            output << needFind << ' ' ;
        }
    }
    auto ret{ output.str() } ;
    if ( ret.empty() ) {
        cout << "No one is handsome" ;
        return 0 ;
    }
    ret.erase( ret.size() - 1 ) ;
    cout << ret ;

    return 0 ;
}

