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

// Example for Creating a Binary Tree
// Here’s an example of creating a Binary Tree with four nodes (2, 3, 4, 5)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

int main()
{
    // Initilize and allocate memory for tree nodes
    Node *firstNode = new Node(2);
    Node *secondNode = new Node(3);
    Node *thirdNode = new Node(4);
    Node *fourthNode = new Node(5);

    // Connect binary tree nodes
    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourthNode;
    return 0;
}
