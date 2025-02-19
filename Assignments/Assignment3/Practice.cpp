#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node *CreateLL(int arr[], int index, int size)
{
    // base case
    if (index == size)
        return NULL;

    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLL(arr, index + 1, size);
    return temp;
}

int main()
{
    Node *head = NULL;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 7, 00, 8, 8, 8, 3, 7, 5, 5, 3, 3, 345};

    int size = sizeof(a) / sizeof(a[0]);
    CreateLL(a, 10, 10);
    Node *tail = NULL;
    Node *temp = NULL;

    // Initialize the loop variable i
    for (int i = 0; i < size; i++)
    {
        if (head == NULL)
        {
            // Initialize head and tail with the first node
            head = new Node(a[i]);
            tail = head;
        }
        else
        {
            tail->next = new Node(a[i]);
            tail = tail->next;
        }
    }

    // Traverse the linked list starting from head
    temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}