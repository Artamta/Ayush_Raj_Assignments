#include <iostream>
using namespace std;
class Stack
{
    int *arr;
    int size;
    int top;

public:
    // constructer;
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[s];
    }

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << " pushed value :" << arr[top] << "at index: " << top << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
        }
        else
            cout << arr[top] << "-> element is removed" << endl;
        top--;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        else
        {
            cout << " top element ";
            return arr[top];
        }
    }
    bool IsEmpety()
    {
        return top == -1;
    }
    int issize()
    {
        return top + 1;
    }
};

int main()
{
    Stack s(5);
    s.push(10);
    s.push(100);
    s.push(1000);
    s.push(10000);
    s.push(100000);
    s.push(1000000);
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    cout << s.peek() << endl;
    cout << s.issize() << endl;
    cout << s.IsEmpety() << endl;

    return 0;
}