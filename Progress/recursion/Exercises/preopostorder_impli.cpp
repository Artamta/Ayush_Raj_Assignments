#include <iostream>
#include <unordered_map>
using namespace std;

// Definition of a Tree Node
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

// Function to build the tree recursively
TreeNode *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
                          vector<int> &inorder, int inStart, int inEnd,
                          unordered_map<int, int> &inMap)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }

    // The first element in preorder is the root
    int rootVal = preorder[preStart];
    TreeNode *root = new TreeNode(rootVal);

    // Find the root in inorder to divide left and right subtrees
    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart;

    // Recursively build the left and right subtrees
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inMap);

    return root;
}

// Main function to build the tree
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inMap;

    // Map each value to its index in inorder traversal
    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, 0, preorder.size() - 1,
                           inorder, 0, inorder.size() - 1, inMap);
}

// Function to print the tree in postorder (for verification)
void printPostorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main()
{
    // Example input
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Build the tree
    TreeNode *root = buildTree(preorder, inorder);

    // Print the tree in postorder to verify
    cout << "Postorder traversal of the constructed tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}