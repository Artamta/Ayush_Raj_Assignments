#include <iostream>
using namespace std;
struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

int FindMin(BstNode *root)
{
    if (root == NULL)
    {
        cout << "Error: NO ROOT" << endl;
    }
    else
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
    }
    return root->data;
}
int FindMinRecursively(BstNode *root)
{
    if (root == NULL)
    {
        cout << "Error: NO ROOT" << endl;
    }
    else if (root->left = NULL)
    {
        return root->data;
    }
    // SEARCH IN LEFT SUBTREE
    return FindMinRecursively(root->left);
}

int main()
{

    return 0;
}