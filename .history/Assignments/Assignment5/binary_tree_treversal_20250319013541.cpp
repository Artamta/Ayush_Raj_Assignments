#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct Node *root)
{

    if (root == NULL)
    {
        return;
    }
    cout << root->data << " " << endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root)
{
    preorder(root->left);
    cout << root->data << " " << endl;
    preorder(root->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    // preorder(root);
    inorder(root);
    return 0;
}