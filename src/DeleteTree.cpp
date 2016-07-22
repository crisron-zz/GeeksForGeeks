#include <iostream>
#include <cassert>
#include <exception>

#define SUCCESS 1
#define FAILURE 0

using namespace std;

// TODO: Push this into a common header file
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// TODO: Push this into a common header file
struct node* newNode( int data ) {
    struct node* root = new node;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

bool isLeaf( struct node* root ) {
    return ( !root->left && !root->right );
}

bool deleteTree( struct node* root ) {
    if( !root ) {
        return SUCCESS;
    }

    if( isLeaf( root ) ) {
        try {
            delete root;
        } catch( exception& e ) {
            cout << "\033[1;31m========Caught Exception: " << e.what() <<
                    " ========\033[0m" << endl;
            return FAILURE;
        }
        return SUCCESS;
    }

    bool l = deleteTree( root->left );
    if( l == FAILURE ) {
        return l;
    }

    bool r = deleteTree( root->right );
    if( r == FAILURE ) {
        return r;
    }

    try {
        delete root;
    } catch( exception& e ) {
        cout << "\033[1;31m========Caught Exception: " << e.what() <<
                " ========\033[0m" << endl;
        return FAILURE;
    }

    return SUCCESS;
}

int main() {
    struct node* root;

    root = NULL;
    assert( deleteTree( root ) );

    root = newNode( 1 );
    assert( deleteTree( root ) );

    root = newNode( 1 );
    root->left = newNode( 2 );
    assert( deleteTree( root ) );

    root = newNode( 1 );
    root->left = newNode( 2 );
    root->right = newNode( 3 );
    root->left->left = newNode( 4 );
    root->right->left = newNode( 5 );
    assert( deleteTree( root ) );

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;
    return 0;
}
