#include <iostream>
using namespace std;

bool IsBstUtil(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
    {
        return true;
    }

    else if (root->data < minVakue && root->data > maxValue && IsBstUtil(root->left, minValue, root->data) && IsBstUtil(root->right, root->data, maxValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsBinarySearchTree(Node *root)
{
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

int main()
{

    return 0;
}
