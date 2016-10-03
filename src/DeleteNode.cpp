// http://www.geeksforgeeks.org/given-only-a-pointer-to-a-node-to-be-deleted-in-a-singly-linked-list-how-do-you-delete-it/
#include <iostream>
#include <cassert>

#include "LinkedListHelper.h"

using namespace std;

void deleteNode( struct nodeSingle* &ptr ) {
    if( !ptr || !ptr->next ) {
        return;
    }
    struct nodeSingle* tmp = ptr->next;
    ptr->data = ptr->next->data;
    ptr->next = ptr->next->next;
    delete tmp;
}

int main() {
    struct nodeSingle *head;

    // Should not crash when head is NULL
    head = NULL;
    deleteNode( head );
    assert( !head );

    // Should be a No-op when the pointer to the last
    // node is given
    struct nodeSingle* tmp;
    head = newNode( 1 );
    tmp = head;
    deleteNode( head );
    assert( head == tmp );
    assert( head->data == 1 );
    assert( !head->next );

    head = newNode( 1 );
    head->next = newNode( 2 );
    tmp = head;
    deleteNode( head );
    assert( head == tmp );
    assert( head->data == 2 );
    assert( !head->next );

    struct nodeSingle* tmp1, *tmp2;
    head = newNode( 1 );
    head->next = newNode( 2 );
    head->next->next = newNode( 3 );
    tmp1 = head;
    tmp2 = head->next->next;
    deleteNode( head );
    assert( head == tmp1 );
    assert( head->data == 2 );
    assert( head->next == tmp2 );
    assert( head->next->data == 3 );
    assert( !head->next->next );

    head = newNode( 1 );
    head->next = newNode( 2 );
    head->next->next = newNode( 3 );
    tmp1 = head;
    tmp2 = head->next;
    deleteNode( head->next );
    assert( head == tmp1 );
    assert( head->data == 1 );
    assert( head->next == tmp2 );
    assert( head->next->data == 3 );
    assert( !head->next->next );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;
    return 0;
}

