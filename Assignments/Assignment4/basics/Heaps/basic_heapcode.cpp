#include <iostream>
#include <vector>
#include <stdexcept> // for std::out_of_range
#include <cmath>     // for floor, log2, etc.

using namespace std;

/*
 * ================================================================
 *                      MAX HEAP IMPLEMENTATION
 * ================================================================
 */

class MaxHeap
{
private:
    vector<int> heap; // we'll use 1-based indexing for convenience

    // Helper method: maxHeapify (a.k.a. "heapify")
    // --------------------------------------------------------------
    // This function fixes a single violation of the max-heap property
    // at index i by comparing the node with its children and swapping
    // if needed, then recursing down.
    void maxHeapify(int i)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        // Check if left child is larger than current largest
        if (left <= getSize() && heap[left] > heap[largest])
        {
            largest = left;
        }
        // Check if right child is larger than current largest
        if (right <= getSize() && heap[right] > heap[largest])
        {
            largest = right;
        }
        // If the largest is not i, we need to swap and continue heapifying
        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    // Constructor 1: default, creates an empty heap
    MaxHeap()
    {
        // We can push a dummy value at index 0 to make indexing simpler
        heap.push_back(-1); // dummy
    }

    // Constructor 2: build a max-heap from an existing array
    // "arr" is 0-based from the user, so we convert to 1-based internally
    MaxHeap(const vector<int> &arr)
    {
        // push a dummy at index 0
        heap.push_back(-1);
        // push actual array elements
        for (int val : arr)
        {
            heap.push_back(val);
        }
        // Now build the heap
        buildHeap();
    }

    // buildHeap
    // --------------------------------------------------------------
    // Builds a max-heap from the current array in O(n) time
    void buildHeap()
    {
        int n = getSize();
        // We'll call maxHeapify starting from n/2 down to 1
        for (int i = n / 2; i >= 1; i--)
        {
            maxHeapify(i);
        }
    }

    // getSize
    // --------------------------------------------------------------
    // Returns the number of elements in the heap
    int getSize() const
    {
        return (int)heap.size() - 1; // minus the dummy
    }

    // isEmpty
    // --------------------------------------------------------------
    // Returns true if no real elements are in the heap
    bool isEmpty() const
    {
        return getSize() == 0;
    }

    // getMax
    // --------------------------------------------------------------
    // Returns the maximum element (root) without removing it
    // Throws an exception if the heap is empty
    int getMax() const
    {
        if (isEmpty())
        {
            throw out_of_range("MaxHeap is empty. No maximum element.");
        }
        return heap[1]; // root is at index 1
    }

    // extractMax
    // --------------------------------------------------------------
    // Removes and returns the maximum element from the heap
    // Then re-heapifies to maintain the max-heap property
    int extractMax()
    {
        if (isEmpty())
        {
            throw out_of_range("MaxHeap is empty. Cannot extract.");
        }
        int maxElem = heap[1];
        // Move the last element to the root
        heap[1] = heap[getSize()];
        // Remove the last element
        heap.pop_back();
        // Re-heapify
        if (!isEmpty())
        {
            maxHeapify(1);
        }
        return maxElem;
    }

    // insert
    // --------------------------------------------------------------
    // Inserts a new key into the heap, maintaining the heap property
    void insert(int key)
    {
        // First add the new key at the end
        heap.push_back(key);
        int i = getSize();
        // "Bubble up" or "sift up" to restore heap property
        // while parent is smaller than the current node
        while (i > 1 && heap[i / 2] < heap[i])
        {
            swap(heap[i], heap[i / 2]);
            i = i / 2; // move up to the parent
        }
    }

    // increaseKey
    // --------------------------------------------------------------
    // In a max-heap, we can increase the key of an element at index i
    // to newKey (which must be >= current key).
    // Then bubble it up if needed.
    void increaseKey(int i, int newKey)
    {
        if (i < 1 || i > getSize())
        {
            throw out_of_range("Index out of range for increaseKey.");
        }
        if (newKey < heap[i])
        {
            throw invalid_argument("newKey is smaller than current key.");
        }
        // Set the new key
        heap[i] = newKey;
        // Bubble up
        while (i > 1 && heap[i / 2] < heap[i])
        {
            swap(heap[i], heap[i / 2]);
            i = i / 2;
        }
    }

    // printHeap (for debugging)
    // --------------------------------------------------------------
    // Prints the heap array (1-based) for demonstration
    void printHeap() const
    {
        cout << "MaxHeap array (1-based): ";
        for (int i = 1; i <= getSize(); i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

/*
 * ================================================================
 *                      MIN HEAP IMPLEMENTATION
 * ================================================================
 */

class MinHeap
{
private:
    vector<int> heap; // 1-based indexing

    // Helper method: minHeapify
    // --------------------------------------------------------------
    // Fixes a single violation of the min-heap property at index i
    void minHeapify(int i)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;

        // Check if left child is smaller
        if (left <= getSize() && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        // Check if right child is smaller
        if (right <= getSize() && heap[right] < heap[smallest])
        {
            smallest = right;
        }
        // If the smallest is not i, we swap and continue
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }

public:
    // Constructor 1: empty
    MinHeap()
    {
        // dummy at index 0
        heap.push_back(-1);
    }

    // Constructor 2: build a min-heap from existing array
    MinHeap(const vector<int> &arr)
    {
        // dummy
        heap.push_back(-1);
        // copy elements
        for (int val : arr)
        {
            heap.push_back(val);
        }
        // build the min-heap
        buildHeap();
    }

    // buildHeap
    // --------------------------------------------------------------
    // Build a min-heap from the current array in O(n) time
    void buildHeap()
    {
        int n = getSize();
        for (int i = n / 2; i >= 1; i--)
        {
            minHeapify(i);
        }
    }

    // getSize
    int getSize() const
    {
        return (int)heap.size() - 1;
    }

    // isEmpty
    bool isEmpty() const
    {
        return getSize() == 0;
    }

    // getMin
    int getMin() const
    {
        if (isEmpty())
        {
            throw out_of_range("MinHeap is empty. No minimum element.");
        }
        return heap[1];
    }

    // extractMin
    int extractMin()
    {
        if (isEmpty())
        {
            throw out_of_range("MinHeap is empty. Cannot extract.");
        }
        int minElem = heap[1];
        heap[1] = heap[getSize()];
        heap.pop_back();
        if (!isEmpty())
        {
            minHeapify(1);
        }
        return minElem;
    }

    // insert
    void insert(int key)
    {
        heap.push_back(key);
        int i = getSize();
        // bubble up
        while (i > 1 && heap[i / 2] > heap[i])
        {
            swap(heap[i], heap[i / 2]);
            i = i / 2;
        }
    }

    // decreaseKey
    // --------------------------------------------------------------
    // For a min-heap, decrease the key of element at index i to newKey
    // which must be <= current key, then bubble up if needed.
    void decreaseKey(int i, int newKey)
    {
        if (i < 1 || i > getSize())
        {
            throw out_of_range("Index out of range for decreaseKey.");
        }
        if (newKey > heap[i])
        {
            throw invalid_argument("newKey is larger than current key.");
        }
        heap[i] = newKey;
        // bubble up
        while (i > 1 && heap[i / 2] > heap[i])
        {
            swap(heap[i], heap[i / 2]);
            i = i / 2;
        }
    }

    // printHeap
    void printHeap() const
    {
        cout << "MinHeap array (1-based): ";
        for (int i = 1; i <= getSize(); i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // ------------------------------------------------------------
    // DEMONSTRATION: MAX HEAP
    // ------------------------------------------------------------
    cout << "=== Demonstration of MaxHeap ===\n";
    vector<int> arrMax = {4, 10, 3, 5, 1};
    MaxHeap maxH(arrMax);
    cout << "Initial MaxHeap built from [4, 10, 3, 5, 1]:\n";
    maxH.printHeap();

    cout << "Max element: " << maxH.getMax() << endl;

    cout << "Insert 20 into MaxHeap...\n";
    maxH.insert(20);
    maxH.printHeap();

    cout << "Extract Max: " << maxH.extractMax() << endl;
    maxH.printHeap();

    cout << "Increase key of index 2 to 15...\n";
    // We must be careful about indexes (1-based):
    // let's see what's at index 2 now:
    if (!maxH.isEmpty() && maxH.getSize() >= 2)
    {
        maxH.increaseKey(2, 15);
        maxH.printHeap();
    }

    // ------------------------------------------------------------
    // DEMONSTRATION: MIN HEAP
    // ------------------------------------------------------------
    cout << "\n=== Demonstration of MinHeap ===\n";
    vector<int> arrMin = {4, 10, 3, 5, 1};
    MinHeap minH(arrMin);
    cout << "Initial MinHeap built from [4, 10, 3, 5, 1]:\n";
    minH.printHeap();

    cout << "Min element: " << minH.getMin() << endl;

    cout << "Insert 2 into MinHeap...\n";
    minH.insert(2);
    minH.printHeap();

    cout << "Extract Min: " << minH.extractMin() << endl;
    minH.printHeap();

    cout << "Decrease key of index 2 to 1...\n";
    // again, careful with 1-based indexing
    if (!minH.isEmpty() && minH.getSize() >= 2)
    {
        minH.decreaseKey(2, 1);
        minH.printHeap();
    }

    return 0;
}
