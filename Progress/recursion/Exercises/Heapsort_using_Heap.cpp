#include <iostream>
#include <vector>
using namespace std;

// Non-recursive maxHeapify
void maxHeapify(vector<int> &arr, int i, int n)
{
    // n is the current "heap size"
    while (true)
    {
        int left = 2 * i + 1; // 0-based
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest == i)
            break;
        swap(arr[i], arr[largest]);
        i = largest;
    }
}

// Build max heap in O(n)
void buildMaxHeap(vector<int> &arr)
{
    int n = (int)arr.size();
    // Start from last non-leaf node down to root
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, i, n);
    }
}

void heapSort(vector<int> &arr)
{
    int n = (int)arr.size();
    // 1. Build a max-heap
    buildMaxHeap(arr);
    // 2. Repeatedly swap arr[0] with arr[n-1], reduce heap size, and heapify
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);  // put current max at the end
        maxHeapify(arr, 0, i); // restore heap property in the reduced heap
    }
}

int main()
{
    vector<int> arr = {4, 10, 3, 5, 1, 2};
    heapSort(arr);
    cout << "Heap-sorted array: ";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
