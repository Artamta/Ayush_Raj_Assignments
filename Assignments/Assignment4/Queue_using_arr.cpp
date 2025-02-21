#include <iostream>
using namespace std;
//  implementation of Queue using arrays
class Queue
{
    int *arr;
    int front, rear, size;

public:
    Queue(int n)
    {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    bool IsEmpty()
    {
        return front == -1;
    }
    bool IsFull()
    {
        return rear == size - 1;
    }
    void push(int x)
    {
        // empty
        if (IsEmpty())
        {
            front = rear = 0;
            cout << "pushed " << x << endl;
            arr[0] = x;
            return;
        }

        else if (IsFull())
        {
            cout << "queue overflow \n"
                 << endl;
            return;
        }
        else
        {
            rear = rear + 1;
            arr[rear] = x;
            cout << "pushed " << x << endl;
        }
    }
    void pop()
    {
        if (IsEmpty())
        {
            cout << "queue underflow\n";
            return;
        }
        else
        {
            if (front == rear)
            {
                cout << "removed" << arr[front] << "from queue\n";
                front = rear = -1;
            }
            else
            {
                cout << "removed" << arr[front] << "from queue\n";
                front++;
            }
        }
    }
    void peek()
    {
        if (IsEmpty())
        {
            cout << "stack if empty";
        }
        else
        {

            cout << "first in qeue is :" << arr[front] << endl;
        }
    }
};

int main()
{
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.peek();
    q.pop();
    q.peek();
    q.pop();
    q.push(5);
    return 0;
}