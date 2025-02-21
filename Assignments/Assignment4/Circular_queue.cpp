#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int size, front, rear;

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
    { // changes for circular qeue(I am using mod)
        return (rear + 1) % size == front;
    }

    void push(int x)
    {
        if (IsFull())
        {
            cout << "queue_overflow\n";
            return;
        }
        if (IsEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = x;
        cout << "pushed: " << arr[rear] << " in queue" << endl;
    }
    void pop()
    {
        cout << " removed :" << arr[front] << endl;
        front = (front + 1) % size;
    }
};

int main()
{
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.pop();
    q.pop();
    q.push(60);
    q.pop();
    q.push(60);
    return 0;
}