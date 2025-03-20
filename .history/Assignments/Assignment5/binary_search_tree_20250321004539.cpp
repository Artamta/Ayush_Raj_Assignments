#include <iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *GetNewNode(int data)
{
    BstNode *NewNode = new BstNode();
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->left = NULL;
    return NewNode;
}

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
bool Search(Bst Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return Search(root->right, data);
    }
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