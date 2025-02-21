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

class Stack
{
    int size;
    Node *top;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }
    void push(int val)
    {
        Node *temp;
        temp = new Node(val);
        temp->next = top;
        top = temp;
        size++;
        cout << "Pushed :" << val << endl;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empety\n";
        }
        else
        {
            Node *temp = top;
            cout << "Removed :" << top->data << endl;
            top = top->next;
            delete temp;
            size--;
        }
    }
    int peek()
    {
        if (top == NULL)
        {
            cout << "stack is empty";
            return -1;
        }
        else
        {
            return top->data;
        }
    }
    bool IsEmpety()
    {
        return top == NULL;
    }

    int IsSize()
    {
        return size;
    }
};

int main()
{
    Stack s1;
    s1.push(0);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout << s1.IsSize() << endl;
    s1.pop();
    cout << s1.IsEmpety() << endl;
    cout << s1.IsSize() << endl;

    return 0;
}