#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <limits>
#include <algorithm>
#include <stdexcept>
using namespace std;

//=========================================================
// SORTING ALGORITHMS
//=========================================================

/// Bubble Sort (Array-based concept using vector)
/// Time Complexity: O(n^2)
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place.
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

/// Selection Sort
/// Time Complexity: O(n^2)
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

/// Insertion Sort
/// Time Complexity: O(n^2) worst-case, O(n) best-case
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/// Merge Sort (Divide & Conquer)
/// Time Complexity: O(n log n)
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/// Quick Sort
/// Average Time Complexity: O(n log n); Worst-case: O(n^2)
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = low - 1;       // index of smaller element
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//=========================================================
// SEARCHING ALGORITHMS
//=========================================================

/// Linear Search
/// Time Complexity: O(n)
int linearSearch(const vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

/// Binary Search (requires sorted array)
/// Time Complexity: O(log n)
int binarySearch(const vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

//=========================================================
// DATA STRUCTURES
//=========================================================

//------------------------------
// Singly Linked List (Pointer-based)
//------------------------------
struct SLLNode
{
    int data;
    SLLNode *next;
    SLLNode(int d) : data(d), next(nullptr) {}
};

class SinglyLinkedList
{
public:
    SLLNode *head;
    SinglyLinkedList() : head(nullptr) {}

    // Insert at beginning: O(1)
    void insertAtHead(int data)
    {
        SLLNode *newNode = new SLLNode(data);
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail: O(n)
    void insertAtTail(int data)
    {
        SLLNode *newNode = new SLLNode(data);
        if (!head)
        {
            head = newNode;
            return;
        }
        SLLNode *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Delete first occurrence: O(n)
    void deleteValue(int data)
    {
        if (!head)
            return;
        if (head->data == data)
        {
            SLLNode *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        SLLNode *current = head;
        while (current->next && current->next->data != data)
            current = current->next;
        if (current->next)
        {
            SLLNode *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // Print list: O(n)
    void printList()
    {
        SLLNode *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

//------------------------------
// Doubly Linked List (Pointer-based)
//------------------------------
struct DLLNode
{
    int data;
    DLLNode *prev;
    DLLNode *next;
    DLLNode(int d) : data(d), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
public:
    DLLNode *head;
    DoublyLinkedList() : head(nullptr) {}

    // Insert at beginning: O(1)
    void insertAtHead(int data)
    {
        DLLNode *newNode = new DLLNode(data);
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
    }

    // Insert at tail: O(n)
    void insertAtTail(int data)
    {
        DLLNode *newNode = new DLLNode(data);
        if (!head)
        {
            head = newNode;
            return;
        }
        DLLNode *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete a node: O(n)
    void deleteValue(int data)
    {
        DLLNode *temp = head;
        while (temp && temp->data != data)
            temp = temp->next;
        if (!temp)
            return;
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; // deleting head
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
    }

    // Print list forward: O(n)
    void printList()
    {
        DLLNode *temp = head;
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

//------------------------------
// STACK IMPLEMENTATIONS
//------------------------------

/// 3.1. Array-based Stack (Using vector as dynamic array)
class ArrayStack
{
private:
    vector<int> arr;

public:
    // Push: O(1) average
    void push(int x)
    {
        arr.push_back(x);
    }
    // Pop: O(1)
    void pop()
    {
        if (arr.empty())
            throw runtime_error("Stack is empty");
        arr.pop_back();
    }
    // Top element: O(1)
    int top()
    {
        if (arr.empty())
            throw runtime_error("Stack is empty");
        return arr.back();
    }
    bool isEmpty()
    {
        return arr.empty();
    }
};

/// 3.2. Linked List-based Stack
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int d) : data(d), next(nullptr) {}
};

class LinkedListStack
{
private:
    StackNode *topNode;

public:
    LinkedListStack() : topNode(nullptr) {}
    void push(int x)
    {
        StackNode *newNode = new StackNode(x);
        newNode->next = topNode;
        topNode = newNode;
    }
    void pop()
    {
        if (!topNode)
            throw runtime_error("Stack is empty");
        StackNode *temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    int top()
    {
        if (!topNode)
            throw runtime_error("Stack is empty");
        return topNode->data;
    }
    bool isEmpty()
    {
        return topNode == nullptr;
    }
};

//------------------------------
// QUEUE IMPLEMENTATIONS
//------------------------------

/// 4.1. Array-based Queue (Circular Queue using vector)
class ArrayQueue
{
private:
    vector<int> arr;
    int front, rear, size, capacity;

public:
    ArrayQueue(int cap) : front(0), rear(-1), size(0), capacity(cap)
    {
        arr.resize(capacity);
    }
    // Enqueue: O(1)
    void enqueue(int x)
    {
        if (size == capacity)
            throw runtime_error("Queue is full");
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }
    // Dequeue: O(1)
    void dequeue()
    {
        if (size == 0)
            throw runtime_error("Queue is empty");
        front = (front + 1) % capacity;
        size--;
    }
    int frontElement()
    {
        if (size == 0)
            throw runtime_error("Queue is empty");
        return arr[front];
    }
    bool isEmpty()
    {
        return size == 0;
    }
};

/// 4.2. Linked List-based Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int d) : data(d), next(nullptr) {}
};

class LinkedListQueue
{
private:
    QueueNode *front;
    QueueNode *rear;

public:
    LinkedListQueue() : front(nullptr), rear(nullptr) {}
    // Enqueue: O(1)
    void enqueue(int x)
    {
        QueueNode *newNode = new QueueNode(x);
        if (!rear)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    // Dequeue: O(1)
    void dequeue()
    {
        if (!front)
            throw runtime_error("Queue is empty");
        QueueNode *temp = front;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete temp;
    }
    int frontElement()
    {
        if (!front)
            throw runtime_error("Queue is empty");
        return front->data;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
};

/// 4.3. Queue using Two Stacks (Amortized O(1) per operation)
class QueueUsingStacks
{
private:
    stack<int> stack1, stack2;
    void transfer()
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    void enqueue(int x)
    {
        stack1.push(x);
    }
    void dequeue()
    {
        if (stack2.empty())
        {
            if (stack1.empty())
                throw runtime_error("Queue is empty");
            transfer();
        }
        stack2.pop();
    }
    int front()
    {
        if (stack2.empty())
        {
            if (stack1.empty())
                throw runtime_error("Queue is empty");
            transfer();
        }
        return stack2.top();
    }
    bool isEmpty()
    {
        return stack1.empty() && stack2.empty();
    }
};

//=========================================================
// TREE IMPLEMENTATIONS
//=========================================================

//------------------------------
// 5.1 Binary Search Tree (BST)
//------------------------------
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
    BSTNode *root;
    BSTNode *insert(BSTNode *node, int data)
    {
        if (!node)
            return new BSTNode(data);
        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        return node;
    }
    BSTNode *search(BSTNode *node, int data)
    {
        if (!node || node->data == data)
            return node;
        if (data < node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }
    BSTNode *findMin(BSTNode *node)
    {
        while (node && node->left)
            node = node->left;
        return node;
    }
    BSTNode *remove(BSTNode *node, int data)
    {
        if (!node)
            return node;
        if (data < node->data)
            node->left = remove(node->left, data);
        else if (data > node->data)
            node->right = remove(node->right, data);
        else
        {
            // node with one or no child
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
            // two children: get inorder successor
            BSTNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }
    void inorder(BSTNode *node)
    {
        if (node)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}
    void insert(int data)
    {
        root = insert(root, data);
    }
    bool search(int data)
    {
        return search(root, data) != nullptr;
    }
    void remove(int data)
    {
        root = remove(root, data);
    }
    void inorder()
    {
        inorder(root);
        cout << "\n";
    }
};

//------------------------------
// 5.2 AVL Tree (Self-Balancing BST)
//------------------------------
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
    AVLNode *root;

    int height(AVLNode *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode *node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Right rotate
    AVLNode *rightRotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;
        // Perform rotation
        x->right = y;
        y->left = T2;
        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    // Left rotate
    AVLNode *leftRotate(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;
        // Perform rotation
        y->left = x;
        x->right = T2;
        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    AVLNode *insert(AVLNode *node, int data)
    {
        if (!node)
            return new AVLNode(data);
        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else // Duplicate keys not allowed
            return node;

        // Update height of ancestor
        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(AVLNode *node)
    {
        if (node)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}
    void insert(int data)
    {
        root = insert(root, data);
    }
    void inorder()
    {
        inorder(root);
        cout << "\n";
    }
    // Search can be implemented similarly to BST search.
};

//=========================================================
// HASH TABLE IMPLEMENTATION (Separate Chaining)
//=========================================================
class HashTable
{
private:
    vector<list<int>> table; // vector of lists for separate chaining
    int capacity;            // size of the hash table

    // Simple hash function for demonstration (modulo)
    int hashFunction(int key)
    {
        return key % capacity;
    }

public:
    HashTable(int cap) : capacity(cap)
    {
        table.resize(capacity);
    }
    // Insert key: Average O(1), Worst-case O(n)
    void insert(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    // Search key: Average O(1), Worst-case O(n)
    bool search(int key)
    {
        int index = hashFunction(key);
        for (int item : table[index])
            if (item == key)
                return true;
        return false;
    }
    // Remove key: Average O(1), Worst-case O(n)
    void remove(int key)
    {
        int index = hashFunction(key);
        table[index].remove(key);
    }
    // Print table contents
    void printTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << i << ": ";
            for (int key : table[i])
                cout << key << " -> ";
            cout << "NULL\n";
        }
    }
};

//=========================================================
// GRAPH (Undirected) USING ADJACENCY LIST
//=========================================================
class Graph
{
private:
    int V;                 // number of vertices
    vector<list<int>> adj; // adjacency list
public:
    Graph(int V) : V(V), adj(V) {}

    // Add edge (undirected): O(1)
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // DFS: Depth-First Search (recursive)
    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";
        for (auto i : adj[v])
        {
            if (!visited[i])
                DFSUtil(i, visited);
        }
    }
    void DFS(int start)
    {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
        cout << "\n";
    }

    // BFS: Breadth-First Search using queue
    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " ";
            for (auto i : adj[v])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << "\n";
    }
};

//=========================================================
// MAIN FUNCTION: DEMONSTRATING USAGE
//=========================================================
int main()
{
    cout << "===== Sorting Algorithms Demo =====\n";
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    vector<int> arr1 = arr;
    bubbleSort(arr1);
    cout << "Bubble Sorted: ";
    for (int a : arr1)
        cout << a << " ";
    cout << "\n";

    vector<int> arr2 = arr;
    selectionSort(arr2);
    cout << "Selection Sorted: ";
    for (int a : arr2)
        cout << a << " ";
    cout << "\n";

    vector<int> arr3 = arr;
    insertionSort(arr3);
    cout << "Insertion Sorted: ";
    for (int a : arr3)
        cout << a << " ";
    cout << "\n";

    vector<int> arr4 = arr;
    mergeSort(arr4, 0, arr4.size() - 1);
    cout << "Merge Sorted: ";
    for (int a : arr4)
        cout << a << " ";
    cout << "\n";

    vector<int> arr5 = arr;
    quickSort(arr5, 0, arr5.size() - 1);
    cout << "Quick Sorted: ";
    for (int a : arr5)
        cout << a << " ";
    cout << "\n";

    cout << "\n===== Searching Algorithms Demo =====\n";
    int target = 22;
    int idx = linearSearch(arr, target);
    cout << "Linear Search: Element " << target << (idx != -1 ? " found at index " : " not found ") << idx << "\n";
    idx = binarySearch(arr4, target);
    cout << "Binary Search: Element " << target << (idx != -1 ? " found at index " : " not found ") << idx << "\n";

    cout << "\n===== Singly Linked List Demo =====\n";
    SinglyLinkedList sll;
    sll.insertAtTail(10);
    sll.insertAtTail(20);
    sll.insertAtHead(5);
    sll.insertAtTail(30);
    sll.printList();
    sll.deleteValue(20);
    cout << "After deleting 20:\n";
    sll.printList();

    cout << "\n===== Doubly Linked List Demo =====\n";
    DoublyLinkedList dll;
    dll.insertAtHead(15);
    dll.insertAtTail(25);
    dll.insertAtHead(5);
    dll.insertAtTail(35);
    dll.printList();
    dll.deleteValue(25);
    cout << "After deleting 25:\n";
    dll.printList();

    cout << "\n===== Stack Demo =====\n";
    ArrayStack astack;
    astack.push(100);
    astack.push(200);
    cout << "ArrayStack Top: " << astack.top() << "\n";
    astack.pop();
    cout << "After pop, ArrayStack Top: " << astack.top() << "\n";

    LinkedListStack lstack;
    lstack.push(300);
    lstack.push(400);
    cout << "LinkedListStack Top: " << lstack.top() << "\n";
    lstack.pop();
    cout << "After pop, LinkedListStack Top: " << lstack.top() << "\n";

    cout << "\n===== Queue Demo =====\n";
    ArrayQueue aqueue(5);
    aqueue.enqueue(10);
    aqueue.enqueue(20);
    aqueue.enqueue(30);
    cout << "ArrayQueue Front: " << aqueue.frontElement() << "\n";
    aqueue.dequeue();
    cout << "After dequeue, ArrayQueue Front: " << aqueue.frontElement() << "\n";

    LinkedListQueue lqueue;
    lqueue.enqueue(40);
    lqueue.enqueue(50);
    cout << "LinkedListQueue Front: " << lqueue.frontElement() << "\n";
    lqueue.dequeue();
    cout << "After dequeue, LinkedListQueue Front: " << lqueue.frontElement() << "\n";

    QueueUsingStacks qus;
    qus.enqueue(60);
    qus.enqueue(70);
    cout << "QueueUsingStacks Front: " << qus.front() << "\n";
    qus.dequeue();
    cout << "After dequeue, QueueUsingStacks Front: " << qus.front() << "\n";

    cout << "\n===== Binary Search Tree (BST) Demo =====\n";
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    cout << "BST Inorder (should be sorted): ";
    tree.inorder();
    cout << "Searching for 60 in BST: " << (tree.search(60) ? "Found" : "Not Found") << "\n";
    tree.remove(70);
    cout << "After removing 70, BST Inorder: ";
    tree.inorder();

    cout << "\n===== AVL Tree Demo =====\n";
    AVLTree avl;
    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(10);
    avl.insert(25);
    avl.insert(35);
    avl.insert(50);
    cout << "AVL Inorder (should be balanced): ";
    avl.inorder();

    cout << "\n===== Hash Table Demo =====\n";
    HashTable ht(7); // using a small capacity for demo purposes
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(28);
    cout << "Hash Table Contents:\n";
    ht.printTable();
    cout << "Searching for key 15: " << (ht.search(15) ? "Found" : "Not Found") << "\n";
    ht.remove(15);
    cout << "After removing key 15:\n";
    ht.printTable();

    cout << "\n===== Graph Demo =====\n";
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    cout << "DFS starting from vertex 0: ";
    g.DFS(0);
    cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    cout << "\n===== End of Demo =====\n";
    return 0;
}
