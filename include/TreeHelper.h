// Data structure for representing binary trees
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// TODO: Put the implementation in a shared library
// Keep only the declaration here
// Create a new tree node
struct node* newNode( int data ) {
    struct node *root = new node;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

// TODO: Put the implementation in a shared library
bool isLeaf( struct node* root ) {
    return ( !root->left && !root->right );
}

