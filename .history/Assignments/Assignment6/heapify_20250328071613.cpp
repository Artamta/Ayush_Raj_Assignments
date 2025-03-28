#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

//----------------------------
// HEAPIFY ALGORITHM
//----------------------------

// Heapify for a MAX-HEAP:
// Given an array 'arr', size 'n', and an index 'i',
// this function ensures that the subtree rooted at 'i' satisfies the max-heap property.
// That is, arr[i] is greater than or equal to its children.
void heapifyMax(vector<int> &arr, int n, int i)
{
    int largest = i;       // Assume current index i holds the largest element.
    int left = 2 * i + 1;  // Left child index.
    int right = 2 * i + 2; // Right child index.

    // If left child exists and is greater than arr[largest], update largest.
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child exists and is greater than arr[largest], update largest.
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest element is not the parent, swap and recursively heapify the affected subtree.
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

// Build a MAX-HEAP from an unsorted array by calling heapify on each non-leaf node.
void buildMaxHeap(vector<int> &arr)
{
    int n = arr.size();
    // Start from the last non-leaf node (at index n/2 - 1) and heapify each node.
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMax(arr, n, i);
    }
}

// Heapify for a MIN-HEAP:
// Similar to max-heap but ensures that the parent is less than or equal to its children.
void heapifyMin(vector<int> &arr, int n, int i)
{
    int smallest = i;      // Assume current index i holds the smallest element.
    int left = 2 * i + 1;  // Left child index.
    int right = 2 * i + 2; // Right child index.

    // If left child exists and is smaller than arr[smallest], update smallest.
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child exists and is smaller than arr[smallest], update smallest.
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If the smallest element is not the parent, swap and recursively heapify the affected subtree.
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

// Build a MIN-HEAP from an unsorted array.
void buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1;
