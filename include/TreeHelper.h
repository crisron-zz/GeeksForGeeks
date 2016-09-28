// Data structure for representing binary trees
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new tree node
struct node* newNode( int data ) {
    struct node *root = new node;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

bool isLeaf( struct node* root ) {
    return ( !root->left && !root->right );
}

// Return true if mirrorRoot is a mirror of root
bool isMirror( struct node* mirrorRoot, struct node* root ) {
    if( !mirrorRoot && !root ) {
        return true;
    }
    if( ( !mirrorRoot && root ) || ( mirrorRoot && !root ) ) {
        return false;
    }
    if( mirrorRoot->data != root->data ) {
        return false;
    }
    return ( isMirror( mirrorRoot->left, root->right ) &&
             isMirror( mirrorRoot->right, root->left ) );
}

