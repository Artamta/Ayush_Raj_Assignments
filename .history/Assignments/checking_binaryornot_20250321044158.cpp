#include <iostream>
using namespace std;

bool IsBstUtil(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
    {
        return true;
    }

    else if (root->data < minVakue && root->data > maxValue && IsBstUtil(root->left, minValue, root->data) && IsBstUtil(root->right, riit->data, maxValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    return 0;
}
