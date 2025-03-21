// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Class describing a node of tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int v)
    {
        this->data = v;
        this->left = this->right = NULL;
    }
};

// Inorder Traversal
void printInorder(Node *node)
{
    if (node == NULL)
        return;

    // Traverse left subtree
    printInorder(node->left);

    // Visit node
    cout << node->data << " ";

    // Traverse right subtree
    printInorder(node->right);
}

// Driver code
int main()
{
    // Build the tree
    Node *root = new Node(100);
    root->left = new Node(20);
    root->right = new Node(200);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(150);
    root->right->right = new Node(300);

    // Function call
    cout << "Inorder Traversal: ";
    printInorder(root);
    return 0;
}

///

// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Class describing a node of tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int v)
    {
        this->data = v;
        this->left = this->right = NULL;
    }
};

// Preorder Traversal
void printPreOrder(Node *node)
{
    if (node == NULL)
        return;

    // Visit Node
    cout << node->data << " ";

    // Traverse left subtree
    printPreOrder(node->left);

    // Traverse right subtree
    printPreOrder(node->right);
}

// Driver code
int main()
{
    // Build the tree
    Node *root = new Node(100);
    root->left = new Node(20);
    root->right = new Node(200);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(150);
    root->right->right = new Node(300);

    // Function call
    cout << "Preorder Traversal: ";
    printPreOrder(root);
    return 0;
}

///

// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Class to define structure of a node
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int v)
    {
        this->data = v;
        this->left = this->right = NULL;
    }
};

// PostOrder Traversal
void printPostOrder(Node *node)
{
    if (node == NULL)
        return;

    // Traverse left subtree
    printPostOrder(node->left);

    // Traverse right subtree
    printPostOrder(node->right);

    // Visit node
    cout << node->data << " ";
}

// Driver code
int main()
{
    Node *root = new Node(100);
    root->left = new Node(20);
    root->right = new Node(200);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(150);
    root->right->right = new Node(300);

    // Function call
    cout << "PostOrder Traversal: ";
    printPostOrder(root);
    cout << "\n";

    return 0;
}
