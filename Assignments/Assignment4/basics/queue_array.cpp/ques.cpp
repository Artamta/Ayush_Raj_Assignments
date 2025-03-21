void queueEnqueue(int data)
{
    // Check queue is full or not
    if (capacity == rear)
    {
        printf("\nQueue is full\n");
        return;
    }

    // Insert element at the rear
    else
    {
        queue[rear] = data;
        rear++;
    }
    return;
}

///

void queueDequeue()
{
    // If queue is empty
    if (front == rear)
    {
        printf("\nQueue is empty\n");
        return;
    }

    // Shift all the elements from index 2
    // till rear to the left by one
    else
    {
        for (int i = 0; i < rear - 1; i++)
        {
            queue[i] = queue[i + 1];
        }

        // decrement rear
        rear--;
    }
    return;
}

///

// Function to get front of queue
int front(Queue *queue)
{
    if (isempty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}

///

// Function to get rear of queue
int rear(Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}

//

// This function will check whether
// the queue is empty or not:
bool isEmpty()
{
    if (front == -1)
        return true;
    else
        return false;
}

//

// This function will check
// whether the queue is full or not.
bool isFull()
{
    if (front == 0 && rear == MAX_SIZE - 1)
    {
        return true;
    }
    return false;
}

//

// CPP program to illustrate
// Implementation of size() function
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int sum = 0;
    queue<int> myqueue;
    myqueue.push(1);
    myqueue.push(8);
    myqueue.push(3);
    myqueue.push(6);
    myqueue.push(2);

    // Queue becomes 1, 8, 3, 6, 2

    cout << myqueue.size();

    return 0;
}

// stl

#include <iostream>
#include <queue>
using namespace std;

int main()
{

    // Creating a queue of integers
    queue<int> q;

    // Pushing elements into the queue
    q.push(3);
    q.push(4);
    q.push(5);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

///

#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Declare empty queue
    queue<int> q1;

    // Insert some elements into queue
    q1.push(3);
    q1.push(4);
    q1.push(5);

    // Create another queue from q1
    queue<int> q2(q1);

    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }
    return 0;
}

////

#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;

    // Pushing elements into the queue
    q.push(3);
    q.push(4);
    q.push(5);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

///

#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);

    // Accessing the front and back elements
    cout << q.front() << endl;
    cout << q.back();
    return 0;
}

///

#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);

    // Deleting elements from front side
    // of the queue
    q.pop();

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

///
