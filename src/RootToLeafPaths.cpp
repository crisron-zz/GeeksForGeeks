#include <iostream>
#include <vector>
#include <cassert>

#include "TreeHelper.h"

using namespace std;

void concatenateVectors( vector<int>& allPaths, const vector<int>& curPath ) {
    allPaths.insert( allPaths.end(), curPath.begin(), curPath.end() );
}

void _rootToLeafPaths( struct node* root, vector<int>& allPaths, vector<int>& curPath ) {
    if( !root ) {
        return;
    }

    curPath.push_back( root->data );

    if( isLeaf( root ) ) {
        concatenateVectors( allPaths, curPath );
    }

    if( root->left ) {
        _rootToLeafPaths( root->left, allPaths, curPath );
    }

    if( root->right ) {
        _rootToLeafPaths( root->right, allPaths, curPath );
    }
    
    curPath.pop_back();
}

void rootToLeafPaths( struct node* root, vector<int>& allPaths ) {
    vector<int> curPath;
    _rootToLeafPaths( root, allPaths, curPath );
}

int main() {
    struct node* root = NULL;
    vector<int> expectedAllPaths;
    vector<int> allPaths;
    
    rootToLeafPaths( root, allPaths );
    assert( expectedAllPaths.empty() );
    allPaths.clear();
    expectedAllPaths.clear();

    root = newNode( 1 );
    rootToLeafPaths( root, allPaths );
    expectedAllPaths.push_back( 1 );
    assert( expectedAllPaths == allPaths );
    allPaths.clear();
    expectedAllPaths.clear();

    root = newNode( 1 );
    root->left = newNode( 2 );
    rootToLeafPaths( root, allPaths );
    expectedAllPaths.push_back( 1 );
    expectedAllPaths.push_back( 2 );
    assert( expectedAllPaths == allPaths );
    allPaths.clear();
    expectedAllPaths.clear();

    root = newNode( 1 );
    root->right = newNode( 2 );
    rootToLeafPaths( root, allPaths );
    expectedAllPaths.push_back( 1 );
    expectedAllPaths.push_back( 2 );
    assert( expectedAllPaths == allPaths );
    allPaths.clear();
    expectedAllPaths.clear();

    root = newNode( 1 );
    root->left = newNode( 2 );
    root->right = newNode( 3 );
    rootToLeafPaths( root, allPaths );
    expectedAllPaths.push_back( 1 );
    expectedAllPaths.push_back( 2 );
    expectedAllPaths.push_back( 1 );
    expectedAllPaths.push_back( 3 );
    assert( expectedAllPaths == allPaths );
    allPaths.clear();
    expectedAllPaths.clear();

    root = newNode( 1 );
    root->left = newNode( 2 );
    root->right = newNode( 3 );
    root->left->left = newNode( 4 );
    root->right->left = newNode( 5 );
    root->right->right = newNode( 6 );
    rootToLeafPaths( root, allPaths );
    expectedAllPaths.push_back( 1 );
    expectedAllPaths.push_back( 2 );
    expectedAllPaths.push_back( 4 );
    expectedAllPaths.push_back( 1 );
    expectedAllPaths.push_back( 3 );
    expectedAllPaths.push_back( 5 );
    expectedAllPaths.push_back( 1 );
    expectedAllPaths.push_back( 3 );
    expectedAllPaths.push_back( 6 );
    assert( expectedAllPaths == allPaths );
    allPaths.clear();
    expectedAllPaths.clear();

    root = newNode( 1 );
    root->left = newNode( 2 );
    root->right = newNode( 3 );
    root->left->left = newNode( 4 );
    root->left->right = newNode( 5 );
    rootToLeafPaths( root, allPaths );
    expectedAllPaths.push_back( 1 );
    expectedAllPaths.push_back( 2 );
    expectedAllPaths.push_back( 4 );
    expectedAllPaths.push_back( 1 );
    expectedAllPaths.push_back( 2 );
    expectedAllPaths.push_back( 5 );
    expectedAllPaths.push_back( 1 );
    expectedAllPaths.push_back( 3 );
    assert( expectedAllPaths == allPaths );
    allPaths.clear();
    expectedAllPaths.clear();

    cout << "\033[1;32m==========ALL TESTS PASSED==========\033[0m" << endl;
    return 0;
}

