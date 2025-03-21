#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MaxHeap
{
private:
    vector<int> heap; // We'll use 1-based indexing; index 0 is dummy.

    // Non-recursive maxHeapify (iterative approach).
    void maxHeapify(int i)
    {
        int n = getSize();
        while (true)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            // Check left child
            if (left <= n && heap[left] > heap[largest])
            {
                largest = left;
            }
            // Check right child
            if (right <= n && heap[right] > heap[largest])
            {
                largest = right;
            }
            // If no change, we are done
            if (largest == i)
            {
                break;
            }
            // Swap with the larger child
            swap(heap[i], heap[largest]);
            i = largest; // Continue down the tree
        }
    }

public:
    MaxHeap()
    {
        heap.push_back(-1); // dummy index 0
    }

    // Build a max-heap from an existing array
    MaxHeap(const vector<int> &arr)
    {
        heap.push_back(-1); // dummy
        for (int val : arr)
        {
            heap.push_back(val);
        }
        buildHeap();
    }

    int getSize() const
    {
        return (int)heap.size() - 1;
    }

    // Build the heap in O(n) by calling maxHeapify from bottom up
    void buildHeap()
    {
        int n = getSize();
        for (int i = n / 2; i >= 1; i--)
        {
            maxHeapify(i);
        }
    }

    // Insert a key (usual method: add to end, then bubble up)
    void insert(int key)
    {
        heap.push_back(key);
        int i = getSize();
        // bubble up
        while (i > 1 && heap[i / 2] < heap[i])
        {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

    // Extract the maximum
    int extractMax()
    {
        if (getSize() < 1)
            throw out_of_range("Heap empty.");
        int maxVal = heap[1];
        heap[1] = heap[getSize()];
        heap.pop_back();
        if (getSize() >= 1)
        {
            maxHeapify(1);
        }
        return maxVal;
    }

    // Print for demo
    void printHeap() const
    {
        for (int i = 1; i <= getSize(); i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {4, 10, 3, 5, 1};
    MaxHeap mh(arr);
    cout << "Built max-heap (iterative heapify): ";
    mh.printHeap();

    mh.insert(20);
    cout << "After inserting 20: ";
    mh.printHeap();

    cout << "Extract max: " << mh.extractMax() << endl;
    mh.printHeap();

    return 0;
}
