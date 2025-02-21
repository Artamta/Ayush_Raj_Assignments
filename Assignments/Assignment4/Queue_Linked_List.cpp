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
class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    bool IsEmpty()
    {
        return front == 0;
    }
    void push(int x)
    {
        if (IsEmpty())
        {
            Node *temp;
            front = rear = new Node(x);
            cout << "pushed " << x << endl;
            return;
        }
        else
        {
            rear->next = new Node(x);
            rear = rear->next;
            cout << "pushed " << x << endl;
        }
    }
    void pop()
    {
        if (IsEmpty())
        {
            cout << "Queue Underflow";
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void print()
    {
        Node *temp;
        temp = front;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main()
{
    Queue Q1;
    Q1.push(10);
    Q1.push(20);
    Q1.push(230);
    Q1.push(103);
    Q1.pop();
    Q1.print();
    return 0;
}