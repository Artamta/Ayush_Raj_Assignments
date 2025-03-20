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
bool Search(BstNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data < root->data)
    {
        return Search(root->left, data);
    }
    else
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
    cout << Search(root, 15) << endl;
    // Insert(root,15);
    // Insert(root,15);
    // Insert(root,15);

    return 0;
}