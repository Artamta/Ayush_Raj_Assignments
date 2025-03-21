#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MaxPriorityQueue
{
private:
    vector<int> heap; // 1-based indexing

    void maxHeapify(int i)
    {
        int n = size();
        while (true)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= n && heap[left] > heap[largest])
                largest = left;
            if (right <= n && heap[right] > heap[largest])
                largest = right;
            if (largest == i)
                break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    MaxPriorityQueue()
    {
        heap.push_back(-1); // dummy
    }

    int size() const
    {
        return (int)heap.size() - 1;
    }

    bool empty() const
    {
        return size() == 0;
    }

    void push(int key)
    {
        // Insert at end
        heap.push_back(key);
        // bubble up
        int i = size();
        while (i > 1 && heap[i / 2] < heap[i])
        {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

    int top()
    {
        if (empty())
            throw out_of_range("Priority Queue empty");
        return heap[1]; // root is max
    }

    void pop()
    {
        if (empty())
            throw out_of_range("Priority Queue empty");
        heap[1] = heap[size()];
        heap.pop_back();
        if (!empty())
        {
            maxHeapify(1);
        }
    }
};

int main()
{
    MaxPriorityQueue pq;
    pq.push(5);
    pq.push(10);
    pq.push(3);
    cout << "Top (max) is: " << pq.top() << endl; // 10
    pq.pop();
    cout << "After pop, top is: " << pq.top() << endl; // 5
    return 0;
}
