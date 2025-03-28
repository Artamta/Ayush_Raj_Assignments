#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

//=========================================================
// Custom Dynamic Array Class (without using STL vector)
//=========================================================
class DynamicArray
{
private:
    int *arr;     // Pointer to the underlying array
    int capacity; // Total capacity of the array
    int size;     // Current number of elements stored

    // Resizes the array to newCapacity and copies existing elements.
    void resize(int newCapacity)
    {
        // Allocate a new array with the new capacity.
        int *newArr = new int[newCapacity];
        // Copy old elements into the new array.
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        // Free the old array's memory.
        delete[] arr;
        // Update the pointer and capacity.
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // Constructor: initializes array with a default capacity.
    DynamicArray() : capacity(10), size(0)
    {
        arr = new int[capacity];
    }

    // Destructor: cleans up the allocated memory.
    ~DynamicArray()
    {
        delete[] arr;
    }

    // Adds an element at the end of the array.
    // Time Complexity: Amortized O(1)
    void push_back(int value)
    {
        // If the array is full, double its capacity.
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        arr[size++] = value;
    }

    // Inserts an element at a specified index.
    // Shifts subsequent elements to the right.
    // Time Complexity: O(n) in the worst case.
    void insert(int index, int value)
    {
        if (index < 0 || index > size)
            throw out_of_range("Index out of range");
        // Resize if the array is full.
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        // Shift elements right starting from the end.
        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        // Place the new element.
        arr[index] = value;
        size++;
    }

    // Deletes an element at a specified index.
    // Shifts subsequent elements to the left.
    // Time Complexity: O(n) in the worst case.
    void remove(int index)
    {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range");
        // Shift elements left to fill the gap.
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        // (Optional) You can add code to reduce capacity if size is much smaller than capacity.
    }

    // Searches for a value in the array.
    // Returns the index if found, otherwise returns -1.
    // Time Complexity: O(n)
    int search(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
                return i;
        }
        return -1; // Not found.
    }

    // Prints the contents of the array.
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Returns the current number of elements.
    int getSize()
    {
        return size;
    }
};

//=========================================================
// MAIN FUNCTION: Demonstration of the Custom Array and STL vector
//=========================================================
int main()
{
    cout << "===== Custom Dynamic Array Implementation =====\n";

    // Create an instance of our DynamicArray.
    DynamicArray myArray;

    // Insertion operations (push_back)
    myArray.push_back(10);
    myArray.push_back(20);
    myArray.push_back(30);
    myArray.push_back(40);
    cout << "After push_back operations: ";
    myArray.print(); // Expected: 10 20 30 40

    // Inserting an element at a specific index.
    // Insert 25 at index 2: Expected array becomes 10 20 25 30 40
    myArray.insert(2, 25);
    cout << "After inserting 25 at index 2: ";
    myArray.print();

    // Deleting an element at a specific index.
    // Remove element at index 3: Expected array becomes 10 20 25 40
    myArray.remove(3);
    cout << "After deleting element at index 3: ";
    myArray.print();

    // Searching for an element.
    int index = myArray.search(30);
    if (index != -1)
        cout << "Element 30 found at index: " << index << "\n";
    else
        cout << "Element 30 not found.\n";

    //=========================================================
    // STL Vector Implementation for Comparison
    //=========================================================
    cout << "\n===== STL Vector Implementation =====\n";

    // Create an STL vector.
    vector<int> vec;
    // Insertion using push_back.
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    cout << "After push_back operations: ";
    for (int v : vec)
        cout << v << " ";
    cout << "\n";

    // Insertion at a specific position using insert.
    // Insert 25 at position 2 (index 2).
    vec.insert(vec.begin() + 2, 25);
    cout << "After inserting 25 at index 2: ";
    for (int v : vec)
        cout << v << " ";
    cout << "\n";

    // Deletion at a specific position using erase.
    // Erase element at index 3.
    vec.erase(vec.begin() + 3);
    cout << "After deleting element at index 3: ";
    for (int v : vec)
        cout << v << " ";
    cout << "\n";

    return 0;
}
