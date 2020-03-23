#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>

using namespace std ;

struct Node ;

struct NodePtr
{
    Node* ptr ;

    Node* operator->() const
    {
        return ptr ;
    }
} ;

struct Node
{
    int freq_m ;
    string char_m ;
    NodePtr left_m ;
    NodePtr right_m ;
} ;

bool operator<(NodePtr ptr1, NodePtr ptr2)
{
    return ptr1->freq_m > ptr2->freq_m ;
}

vector<int> Stack ;

void printCode(NodePtr thisNode)
{
    if ( !thisNode->char_m.empty() ) {
        cout << thisNode->char_m << ' ' ;
        for ( int code : Stack ) {
            cout << code ;
        }
        cout << endl ;
    } else {
        Stack.push_back( 0 ) ;
        printCode( thisNode->left_m ) ;
        Stack.pop_back() ;

        Stack.push_back( 1 ) ;
        printCode( thisNode->right_m ) ;
        Stack.pop_back() ;
    }
}

int main()
{
    ios::sync_with_stdio(false) ;
    std::cin.tie(nullptr) ;

    priority_queue<NodePtr> mergeMin2 ;
    string tmp4char ;
    int tmp4freq ;
    while ( cin >> tmp4char >> tmp4freq ) {
        mergeMin2.push( NodePtr{ new Node{ tmp4freq, tmp4char, {}, {} } } ) ;
    }

    while ( mergeMin2.size() != 1 ) {
        NodePtr thisMin1{ mergeMin2.top() } ;
        mergeMin2.pop() ;
        NodePtr thisMin2{ mergeMin2.top() } ;
        mergeMin2.pop() ;
        NodePtr thisMerge{ new Node{ thisMin1->freq_m + thisMin2->freq_m, {}, thisMin1, thisMin2 } } ;
        mergeMin2.push( thisMerge ) ;
    }

    printCode( mergeMin2.top() ) ;

    return 0 ;
}
