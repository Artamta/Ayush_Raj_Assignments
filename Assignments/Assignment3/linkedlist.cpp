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

void insertATtail(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAthead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
};

int main()
{
    Node *head = NULL;
    insertATtail(head, 1);
    insertATtail(head, 2);
    insertATtail(head, 100);
    insertATtail(head, 12);
    insertAthead(head, 30);
    insertAthead(head, 4000);
    display(head);

    return 0;
}