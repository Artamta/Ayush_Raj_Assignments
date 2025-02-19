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
void Insertattail(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void Inserathead(Node *&head, int val)
{
    Node *temp = head;
    Node *n = new Node(val);
    n->next = head;
    head = n;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteNode(Node *&head, int val)
{
    Node *temp = head;
    if (temp->data == val)
    {
        Node *todelete = temp;
        temp = temp->next;
        head = temp;
        delete todelete;
    }

    else if (temp == NULL)
    {
        return;
    }
    else if (temp->next == NULL)
    {
        Node *todelete = temp;
        delete todelete;
        cout << "now LL is empety";
    }

    else
    {
        while (temp->next->data != val)
        {
            temp = temp->next;
        }
        Node *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }
}

void reverse()
{
}
bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main()
{

    Node *head = NULL;
    Insertattail(head, 10);
    Insertattail(head, 30);
    Insertattail(head, 20);
    Insertattail(head, 60);
    Inserathead(head, 11);
    Inserathead(head, 15);
    Inserathead(head, 61);
    display(head);
    reverse(head);
    display(head);
    // deleteNode(head, 61);
    // display(head);
    // cout << search(head, 61) << endl;
    return 0;
}