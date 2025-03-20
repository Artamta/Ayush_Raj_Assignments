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
        cout << "NO ROOT" << endl;
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

int main()
{

    return 0;
}