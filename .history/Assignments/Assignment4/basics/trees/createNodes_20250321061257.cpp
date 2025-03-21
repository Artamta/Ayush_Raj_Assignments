// Use any below method to implement Nodes of binary tree

// 1: Using struct
struct Node
{
    int data;
    Node *left, *right;

    Node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

// 2: Using class
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};
