#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//===============================================
// 1. Binary Tree (General)
//===============================================

/*
Theory:
A binary tree is a tree data structure in which each node has at most two children,
commonly referred to as the left and right child. Basic traversals include:
- Preorder (Root, Left, Right)
- Inorder (Left, Root, Right)
- Postorder (Left, Right, Root)
- Level Order (Breadth-First Traversal using a queue)
*/

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    BinaryTreeNode *root;

    BinaryTree() : root(nullptr) {}

    // Preorder Traversal: Visit root, then left subtree, then right subtree.
    void preorder(BinaryTreeNode *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Inorder Traversal: Visit left subtree, then root, then right subtree.
    void inorder(BinaryTreeNode *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Postorder Traversal: Visit left subtree, then right subtree, then root.
    void postorder(BinaryTreeNode *node)
    {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Level Order Traversal using a queue (Breadth-first)
    void levelOrder()
    {
        if (!root)
            return;
        queue<BinaryTreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            BinaryTreeNode *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
};

//===============================================
// 2. Binary Search Tree (BST)
//===============================================

/*
Theory:
A Binary Search Tree (BST) is a binary tree with the additional property that for any node:
- All elements in the left subtree are less than the node's key.
- All elements in the right subtree are greater than the node's key.
BSTs support operations like insertion, search, and deletion with average-case time complexity O(log n).
*/

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    // Recursive function to insert a new value in BST.
    BSTNode *insert(BSTNode *node, int value)
    {
        if (!node)
            return new BSTNode(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        // Duplicates are not inserted.
        return node;
    }

    // Find the node with the minimum value in BST (used for deletion).
    BSTNode *findMin(BSTNode *node)
    {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // Recursive function to remove a value from BST.
    BSTNode *remove(BSTNode *node, int value)
    {
        if (!node)
            return node;
        if (value < node->data)
            node->left = remove(node->left, value);
        else if (value > node->data)
            node->right = remove(node->right, value);
        else
        {
            // Node with only one child or no child.
            if (!node->left)
            {
                BSTNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                BSTNode *temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children: Get the inorder successor.
            BSTNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // Recursive search for a value in BST.
    bool search(BSTNode *node, int value)
    {
        if (!node)
            return false;
        if (node->data == value)
            return true;
        if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    // Inorder traversal (will output the BST in sorted order).
    void inorder(BSTNode *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BSTNode *root;
    BST() : root(nullptr) {}

    void insert(int value)
    {
        root = insert(root, value);
    }

    void remove(int value)
    {
        root = remove(root, value);
    }

    bool search(int value)
    {
        return search(root, value);
    }

    void inorder()
    {
        inorder(root);
        cout << "\n";
    }
};

//===============================================
// 3. AVL Tree (Self-Balancing BST)
//===============================================

/*
Theory:
An AVL tree is a self-balancing Binary Search Tree where the difference in heights
of left and right subtrees (the balance factor) for any node is at most 1. AVL trees
perform rotations to rebalance the tree after insertions (or deletions), ensuring
that the height remains O(log n) and operations remain efficient.
*/

struct AVLNode
{
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;
    AVLNode(int d) : data(d), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
private:
    // Returns the height of the node.
    int height(AVLNode *node)
    {
        return node ? node->height : 0;
    }

    // Returns the balance factor of the node.
    int getBalance(AVLNode *node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Right rotation to rebalance the tree.
    AVLNode *rightRotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;
        // Rotate
        x->right = y;
        y->left = T2;
        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    // Left rotation to rebalance the tree.
    AVLNode *leftRotate(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;
        // Rotate
        y->left = x;
        x->right = T2;
        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    // Insert a new value into the AVL tree and rebalance if necessary.
    AVLNode *insert(AVLNode *node, int value)
    {
        if (!node)
            return new AVLNode(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else // Duplicate keys not allowed.
            return node;

        // Update the height of the current node.
        node->height = 1 + max(height(node->left), height(node->right));

        // Check balance factor.
        int balance = getBalance(node);

        // Left Left Case.
        if (balance > 1 && value < node->left->data)
            return rightRotate(node);

        // Right Right Case.
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        // Left Right Case.
        if (balance > 1 && value > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case.
        if (balance < -1 && value < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Inorder traversal: outputs the values in sorted order.
    void inorder(AVLNode *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    AVLNode *root;
    AVLTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insert(root, value);
    }

    void inorder()
    {
        inorder(root);
        cout << "\n";
    }
};

//===============================================
// 4. Trie (Prefix Tree)
//===============================================

/*
Theory:
A Trie (or prefix tree) is a specialized tree used to store associative data structures.
It is especially efficient for searching words in a dictionary or performing prefix-based queries.
Each node represents a character and has up to 26 children (for lowercase English letters).
*/

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    bool isEndOfWord;                  // True if the node represents the end of a word.
    TrieNode *children[ALPHABET_SIZE]; // Pointers to child nodes.

    TrieNode() : isEndOfWord(false)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // Insert a word into the trie.
    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int index = ch - 'a'; // Assume input is lowercase.
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the trie.
    bool search(const string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    // Recursively deallocate nodes.
    void clear(TrieNode *node)
    {
        if (!node)
            return;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (node->children[i])
                clear(node->children[i]);
        }
        delete node;
    }

    ~Trie()
    {
        clear(root);
    }
};

//===============================================
// MAIN FUNCTION: Demonstration of Tree ADTs
//===============================================

int main()
{
    //----- Binary Tree Demonstration -----
    cout << "======== Binary Tree (General) ========\n";
    BinaryTree bt;
    // Construct a simple binary tree manually:
    //         1
    //       /   \
    //      2     3
    //     / \   /
    //    4   5 6
    bt.root = new BinaryTreeNode(1);
    bt.root->left = new BinaryTreeNode(2);
    bt.root->right = new BinaryTreeNode(3);
    bt.root->left->left = new BinaryTreeNode(4);
    bt.root->left->right = new BinaryTreeNode(5);
    bt.root->right->left = new BinaryTreeNode(6);

    cout << "Preorder: ";
    bt.preorder(bt.root);
    cout << "\nInorder: ";
    bt.inorder(bt.root);
    cout << "\nPostorder: ";
    bt.postorder(bt.root);
    cout << "\nLevel Order: ";
    bt.levelOrder();
    cout << "\n\n";

    //----- Binary Search Tree (BST) Demonstration -----
    cout << "======== Binary Search Tree (BST) ========\n";
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    cout << "BST Inorder (sorted order): ";
    bst.inorder();
    cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << "\n";
    bst.remove(30); // Removing a node with two children.
    cout << "After removing 30, BST Inorder: ";
    bst.inorder();
    cout << "\n";

    //----- AVL Tree Demonstration -----
    cout << "======== AVL Tree ========\n";
    AVLTree avl;
    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(10);
    avl.insert(25);
    avl.insert(35);
    avl.insert(50);
    cout << "AVL Tree Inorder (balanced): ";
    avl.inorder();
    cout << "\n";

    //----- Trie Demonstration -----
    cout << "======== Trie (Prefix Tree) ========\n";
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    trie.insert("hi");
    trie.insert("her");
    cout << "Search for 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << "\n";
    cout << "Search for 'hero': " << (trie.search("hero") ? "Found" : "Not Found") << "\n";

    return 0;
}
