// Data structure for representing singly linked list
struct nodeSingle {
    int data;
    struct nodeSingle* next;
};

// Create a new linked list node
struct nodeSingle* newNode( int data ) {
    struct nodeSingle *head = new nodeSingle;
    head->data = data;
    head->next = NULL;
    return head;
}
