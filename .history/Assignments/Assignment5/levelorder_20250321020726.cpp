#include <iostream>
#include <queue>
using namespace std;

// Definition of the Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    // while there is at least one discovered node
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";
        Q.pop();
        if (current->left != NULL)
        {
            Q.push(current->left);
        }
        if (current->right != NULL)
        {
            Q.push(current->right);
        }
    }
}

int main()
{

    return 0;
}