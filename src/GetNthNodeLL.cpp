#include <iostream>
#include <cassert>

#include "LinkedListHelper.h"

#define NaN 1000000000

using namespace std;

int getNthNode( struct nodeSingle* head, int N ) {
    if( N < 1 ) {
        return NaN;
    }
    if( !head ) {
        return NaN;
    }
    int count = 1;
    while( ( count != N ) && head ) {
        count++;
        head = head->next;
    }
    if( !head ) {
        return NaN;
    }
    return head->data;
}

int main() {
    struct nodeSingle* head;

    head = NULL;
    assert( getNthNode( head, 1 ) == NaN );

    head = newNode( 1 );
    assert( getNthNode( head, -1 ) == NaN );
    assert( getNthNode( head, 1 ) == 1 );
    assert( getNthNode( head, 2 ) == NaN );

    head->next = newNode( 2 );
    assert( getNthNode( head, -1 ) == NaN );
    assert( getNthNode( head, 1 ) == 1 );
    assert( getNthNode( head, 2 ) == 2 );
    assert( getNthNode( head, 3 ) == NaN );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;
    return 0;
}

