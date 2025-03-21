#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

// Function to delete a node from the binary tree
Node *deleteNode(Node *root, int val)
{
    if (root == nullptr)
        return nullptr;
    // Use a queue to perform BFS
    queue<Node *> q;
    q.push(root);
    Node *target = nullptr;

    // Find the target node
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // Check for current node is the target node to delete
        if (curr->data == val)
        {
            target = curr;
            break;
        }
        // Add children to the queue
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    // If target node is not found, return the original tree
    if (target == nullptr)
        return root;

    // Find the deepest rightmost node and its parent
    pair<Node *, Node *> last = {nullptr, nullptr};
    queue<pair<Node *, Node *>> q1;
    q1.push({root, nullptr});

    while (!q1.empty())
    {
        auto curr = q1.front();
        q1.pop();

        // Update the last
        last = curr;

        if (curr.first->left)
            q1.push({curr.first->left, curr.first});
        if (curr.first->right)
            q1.push({curr.first->right, curr.first});
    }

    Node *lastNode = last.first;
    Node *lastParent = last.second;

    // Replace target's value with the last node's value
    target->data = lastNode->data;

    // Remove the last node
    if (lastParent)
    {
        if (lastParent->left == lastNode)
            lastParent->left = nullptr;
        else
            lastParent->right = nullptr;
        delete lastNode;
    }
    else
    {
        // If the last node was the root
        delete lastNode;
        return nullptr;
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    // Creating a simple binary tree
    Node *root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    cout << "Original tree (in-order): ";
    inOrder(root);

    int valToDel = 3;
    root = deleteNode(root, valToDel);

    cout << "\nTree after deleting " << valToDel << " (in-order): ";
    inOrder(root);
    cout << endl;

    return 0;
}
