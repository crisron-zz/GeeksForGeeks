#include <iostream>
#include <cassert>

#include "TreeHelper.h"

using namespace std;

bool isIdentical( struct node* root1, struct node* root2 ) {
    if( !root1 ) {
        return ( root2 == NULL );
    }

    if( !root2 ) {
        return ( root1 = NULL );
    }

    if( root1->data != root2->data ) {
        return 0;
    }

    return ( isIdentical( root1->left, root2->left ) &&
             isIdentical( root1->right, root2->right ) );
}

int main() {
    struct node* root1;
    struct node* root2;

    root1 = NULL;
    root2 = NULL;
    assert( isIdentical( root1, root2 ) );

    root1 = NULL;
    root2 = newNode( 1 );
    root2->left = newNode( 2 );
    assert( !isIdentical( root1, root2 ) );

    root1 = newNode( 1 );
    root2 = NULL;
    assert( !isIdentical( root1, root2 ) );

    root1 = newNode( 1 );
    root2 = newNode( 1 );
    assert( isIdentical( root1, root2 ) );

    root1 = newNode( 1 );
    root1->left = newNode( 2 );
    root1->right = newNode( 3 );
    root2 = newNode( 1 );
    root2->left = newNode( 3 );
    root2->right = newNode( 2 );
    assert( !isIdentical( root1, root2 ) );

    root1 = newNode( 1 );
    root1->left = newNode( 2 );
    root2 = newNode( 1 );
    root2->right = newNode( 2 );
    assert( !isIdentical( root1, root2 ) );

    root1 = newNode( 1 );
    root1->left = newNode( 2 );
    root1->right = newNode( 3 );
    root2 = newNode( 1 );
    root2->left = newNode( 2 );
    root2->right = newNode( 3 );
    assert( isIdentical( root1, root2 ) );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;
    return 0;
}
