// This array will store integer type element
int arr[5];

// This array will store char type element
char arr[10];

// This array will store float type element
float arr[20];

int arr[] = {1, 2, 3, 4, 5};
char arr[5] = {'a', 'b', 'c', 'd', 'e'};
float arr[10] = {1.4, 2.0, 24, 5.0, 0.0};
// Method 1 to create a fixed sized array.
// Here the memory is allocated at compile time.
int arr[5];
// Another way (creation and initialization both)
int arr2[5] = {1, 2, 3, 4, 5};

// Method 2 to create a fixed sized array
// Here memory is allocated at run time (Also
// known as dynamically allocated arrays)
int *arr = new int[5];
#include <vector>

// Dynamic Integer Array
vector<int> v;

#include <iostream>
#include <vector>
using namespace std;

// Prints all subarrays in arr[0..n-1]
void subArray(vector<int> &arr)
{
    int n = arr.size();

    // Pick starting point
    for (int i = 0; i < n; i++)
    {
        // Pick ending poin
        for (int j = i; j < n; j++)
        {
            // Print subarray between current starting
            // and ending points
            for (int k = i; k <= j; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout << "All Non-empty Subarrays\n";
    subArray(arr);
    return 0;
}

// C++ code to print all possible subarrays for given array
// using recursion
#include <iostream>
#include <vector>
using namespace std;

// Recursive function to print all possible subarrays for given array
void printSubArrays(vector<int> &arr, int start, int end)
{

    // Stop if we have reached the end of the array
    if (end == arr.size())
        return;

    // Increment the end point and reset the start to 0
    else if (start > end)
        printSubArrays(arr, 0, end + 1);

    // Print the subarray and increment the starting point
    else
    {
        for (int i = start; i <= end; i++)
            cout << arr[i] << " ";
        cout << endl;
        printSubArrays(arr, start + 1, end);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    printSubArrays(arr, 0, 0);
    return 0;
}
