#include <iostream>
#include <unordered_set>

using namespace std ;

int main()
{
    ios::sync_with_stdio( false ) ;
    std::cin.tie( nullptr ) ;

    unordered_set<string> notHandsomePeople ;
    int numOfFriCirc ;
    cin >> numOfFriCirc ;
    while ( numOfFriCirc-- ) {
        int numOfFriends ;
        cin >> numOfFriends ;
        if ( numOfFriends > 1 ) {
            string tmp4notHandsome ;
            while ( numOfFriends-- ) {
                cin >> tmp4notHandsome ;
                notHandsomePeople.insert( tmp4notHandsome ) ;
            }
        } else {
            int tmp4notHandsome ;
            cin >> tmp4notHandsome ;
        }
    }

    bool anyHandsome{ false }, coutSpace{ false } ;
    unordered_set<string> alreadyFind ;
    string needFind ;
    cin >> needFind ; // iostream::operator bool
    while ( cin >> needFind ) {
        if ( alreadyFind.find( needFind ) == alreadyFind.end() && notHandsomePeople.find( needFind ) == notHandsomePeople.end() ) {
            if ( coutSpace ) {
                cout << ' ' ;
            } else {
                coutSpace = true ;
            }
            cout << needFind ;
            alreadyFind.insert( needFind ) ;
            anyHandsome = true ;
        }
    }

    if ( !anyHandsome ) {
        cout << "No one is handsome" ;
    }

    return 0 ;
}

