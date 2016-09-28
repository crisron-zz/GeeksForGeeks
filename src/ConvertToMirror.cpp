#include <iostream>
#include <cassert>

#include "TreeHelper.h"

using namespace std;

void convertToMirror( struct node* root, struct node*& mirrorRoot ) {
    if( !root ) {
        return;
    }
    mirrorRoot = newNode( root->data );
    convertToMirror( root->left, mirrorRoot->right );
    convertToMirror( root->right, mirrorRoot->left );
}

int main() {
    struct node* root, *mirrorRoot = NULL;

    root = NULL;
    convertToMirror( root, mirrorRoot );
    assert( isMirror( mirrorRoot, root ) );

    mirrorRoot = NULL;
    root = newNode( 1 );
    convertToMirror( root, mirrorRoot );
    assert( isMirror( mirrorRoot, root ) );

    mirrorRoot = NULL;
    root = newNode( 1 );
    root->left = newNode( 2 );
    convertToMirror( root, mirrorRoot );
    assert( isMirror( mirrorRoot, root ) );

    mirrorRoot = NULL;
    root = newNode( 1 );
    root->right = newNode( 2 );
    convertToMirror( root, mirrorRoot );
    assert( isMirror( mirrorRoot, root ) );

    mirrorRoot = NULL;
    root = newNode( 1 );
    root->left = newNode( 2 );
    root->right = newNode( 3 );
    convertToMirror( root, mirrorRoot );
    assert( isMirror( mirrorRoot, root ) );

    mirrorRoot = NULL;
    root = newNode( 1 );
    root->left = newNode( 2 );
    root->right = newNode( 3 );
    root->right->left = newNode( 4 );
    root->right->right = newNode( 5 );
    convertToMirror( root, mirrorRoot );
    assert( isMirror( mirrorRoot, root ) );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;
    return 0;
}
