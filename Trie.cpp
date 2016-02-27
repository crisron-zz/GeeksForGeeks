#include <cassert>
#include <iostream>

#define MAX_CHARS 256

using namespace std;

struct trieNode {
    bool flag;
    trieNode* children[ MAX_CHARS ];
};

struct trie {
    trieNode* root;
};

trieNode* newNode() {
    trieNode* tmp = new trieNode();
    tmp->flag = 0;

    for( int i = 0; i < MAX_CHARS; ++i ) {
        tmp->children[ i ] = NULL;
    }
    return tmp;
}

void insert( trie* tr, string str ) {
    trieNode* root = tr->root;
    for( int i = 0; i < str.length(); ++i ) {
        if( !root->children[ str[ i ] ] ) {
            root->children[ str[ i ] ] = newNode();
        }
        root = root->children[ str[ i ] ];
    }
    root->flag = 1;
}

bool search( trie* tr, string test ) {
    trieNode* root = tr->root;
    for( int i = 0; i < test.length(); ++i ) {
        if( root->children[ test[ i ] ] ) {
            root = root->children[ test[ i ] ];
        } else {
            return 0;
        }
    }
    return ( root->flag );
}

int main() {
    trie tr;
    tr.root = newNode();

    string keys[ 5 ] = { "the", "a", "their", "answer", "any" };
    for( int i = 0; i < 5; ++i ) {
        insert( &tr, keys[ i ] );
    }

    string test1 = "any";
    string test2 = "an";
    string test3 = "there";
    string test4 = "the";
    string test5 = "Answer";
    string test6 = "thaw";

    assert( search( &tr, test1 ) == 1 );
    assert( search( &tr, test2 ) == 0 );
    assert( search( &tr, test3 ) == 0 );
    assert( search( &tr, test4 ) == 1 );
    assert( search( &tr, test5 ) == 0 );
    assert( search( &tr, test6 ) == 0 );

    cout << "All tests passed" << endl;
    return 0;
}
