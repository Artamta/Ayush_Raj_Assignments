#include <iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *GetNewNode(int data); // Function declaration

BstNode *Insert(BstNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

BstNode *GetNewNode(int data)
{
    NewNode->right = NULL; // Fixing duplicate assignment
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->left = NULL;
    return NewNode;
}

int main()
{

    BstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 5);
    // Insert(root,15);
    // Insert(root,15);
    // Insert(root,15);

    return 0;
}