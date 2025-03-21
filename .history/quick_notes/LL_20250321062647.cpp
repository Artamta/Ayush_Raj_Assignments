// Definition of a Node in a singly linked list
struct Node
{

    // Data part of the node
    int data;

    // Pointer to the next node in the list
    Node *next;

    // Constructor to initialize the node with data
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

/////////////////////////////////////////////////////////   /   /   /   /   /
// Normal Doubly LL
struct Node
{

    // To store the Value or data.
    int data;

    // Pointer to point the Previous Element
    Node *prev;

    // Pointer to point the Next Element
    Node *next;

    // Constructor
    Node(int d)
    {
        data = d;
        prev = next = nullptr;
    }
};
