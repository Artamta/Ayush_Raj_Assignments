#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//=========================================================
// BINARY TREE IMPLEMENTATION AND TRAVERSALS
//=========================================================

// Structure for a tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d) : val(d), left(nullptr), right(nullptr) {}
};

// Class for Binary Tree containing various traversals.
class BinaryTree
{
public:
    TreeNode *root;

    BinaryTree() : root(nullptr) {}

    // Helper function to insert nodes in BST fashion.
    TreeNode *insert(TreeNode *node, int value)
    {
        if (!node)
            return new TreeNode(value);
        if (value < node->val)
            node->left = insert(node->left, value);
        else if (value > node->val)
            node->right = insert(node->right, value);
        return node;
    }

    // Public insert method.
    void insert(int value)
    {
        root = insert(root, value);
    }

    // Level Order Traversal (using a queue)
    // Time Complexity: O(n)
    void levelOrderTraversal()
    {
        if (!root)
            return;
        queue<TreeNode *> q;
        q.push(root);
        cout << "Level Order Traversal: ";
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << "\n";
    }

    // Iterative Preorder Traversal using a stack (Root, Left, Right)
    // Time Complexity: O(n)
    void iterativePreorder()
    {
        if (!root)
            return;
        stack<TreeNode *> st;
        st.push(root);
        cout << "Iterative Preorder Traversal: ";
        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            cout << curr->val << " ";
            // Push right first so that left is processed first.
            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);
        }
        cout << "\n";
    }

    // Iterative Inorder Traversal using a stack (Left, Root, Right)
    // Time Complexity: O(n)
    void iterativeInorder()
    {
        stack<TreeNode *> st;
        TreeNode *curr = root;
        cout << "Iterative Inorder Traversal: ";
        while (curr != nullptr || !st.empty())
        {
            // Reach the leftmost node of the current node.
            while (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }
            // Current must be nullptr at this point.
            curr = st.top();
            st.pop();
            cout << curr->val << " ";
            // Visit the right subtree.
            curr = curr->right;
        }
        cout << "\n";
    }

    // Iterative Postorder Traversal using two stacks (Left, Right, Root)
    // Time Complexity: O(n)
    void iterativePostorder()
    {
        if (!root)
            return;
        stack<TreeNode *> st1, st2;
        st1.push(root);
        while (!st1.empty())
        {
            TreeNode *curr = st1.top();
            st1.pop();
            st2.push(curr);
            if (curr->left)
                st1.push(curr->left);
            if (curr->right)
                st1.push(curr->right);
        }
        cout << "Iterative Postorder Traversal: ";
        while (!st2.empty())
        {
            cout << st2.top()->val << " ";
            st2.pop();
        }
        cout << "\n";
    }
};

//=========================================================
// GRAPH IMPLEMENTATION AND TRAVERSALS
//=========================================================

// Graph represented using an adjacency list.
class Graph
{
private:
    int V; // number of vertices
    vector<list<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    // Add an edge (directed or undirected as needed)
    void addEdge(int u, int v, bool undirected = true)
    {
        adj[u].push_back(v);
        if (undirected)
            adj[v].push_back(u);
    }

    // Breadth-First Search (BFS) using a queue
    // Time Complexity: O(V + E)
    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS Traversal from vertex " << start << ": ";
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for (int neighbor : adj[curr])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "\n";
    }

    // Iterative Depth-First Search (DFS) using a stack
    // Time Complexity: O(V + E)
    void DFSIterative(int start)
    {
        vector<bool> visited(V, false);
        stack<int> st;
        st.push(start);
        cout << "Iterative DFS Traversal from vertex " << start << ": ";
        while (!st.empty())
        {
            int curr = st.top();
            st.pop();
            if (!visited[curr])
            {
                cout << curr << " ";
                visited[curr] = true;
            }
            // Push adjacent vertices (in reverse order if you want the same order as recursive DFS)
            for (auto it = adj[curr].rbegin(); it != adj[curr].rend(); ++it)
            {
                if (!visited[*it])
                    st.push(*it);
            }
        }
        cout << "\n";
    }

    // Recursive DFS for reference (not using stack explicitly)
    void DFSUtil(int curr, vector<bool> &visited)
    {
        visited[curr] = true;
        cout << curr << " ";
        for (int neighbor : adj[curr])
        {
            if (!visited[neighbor])
                DFSUtil(neighbor, visited);
        }
    }

    void DFSRecursive(int start)
    {
        vector<bool> visited(V, false);
        cout << "Recursive DFS Traversal from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << "\n";
    }
};

//=========================================================
// MAIN FUNCTION: DEMONSTRATION OF ADVANCED TRAVERSALS
//=========================================================
int main()
{
    // --------- Binary Tree Traversals ---------
    cout << "===== Binary Tree Traversals =====\n";
    BinaryTree bt;
    // Insert nodes to form a binary search tree.
    // Example tree:
    //         50
    //        /  \
    //      30    70
    //     /  \   /  \
    //   20   40 60   80
    bt.insert(50);
    bt.insert(30);
    bt.insert(70);
    bt.insert(20);
    bt.insert(40);
    bt.insert(60);
    bt.insert(80);

    // Demonstrate level order traversal using a queue.
    bt.levelOrderTraversal();

    // Iterative traversals using stacks.
    bt.iterativePreorder();
    bt.iterativeInorder();
    bt.iterativePostorder();

    // --------- Graph Traversals ---------
    cout << "\n===== Graph Traversals =====\n";
    // Create a graph with 6 vertices (0 to 5).
    Graph g(6);
    // Add edges (example undirected graph).
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // Perform Breadth-First Search.
    g.BFS(0);

    // Perform Iterative Depth-First Search using a stack.
    g.DFSIterative(0);

    // Perform Recursive Depth-First Search (for reference).
    g.DFSRecursive(0);

    return 0;
}
