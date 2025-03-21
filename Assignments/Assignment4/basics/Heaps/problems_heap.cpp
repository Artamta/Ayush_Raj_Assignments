#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
  -------------------------------------------------------------
  1) What are the minimum and maximum number of elements in
     a heap of height h?

     - Definition of height (for a binary heap):
       The height h is the number of edges on the longest path
       from the root to a leaf. So a heap with height h has
       levels 0, 1, 2, ..., h (total of h+1 levels).

     - Minimum number of elements:
       To have height h, the tree must at least have one node
       in level h.
       The complete binary tree is filled up to level (h-1)
       (which has 2^h - 1 nodes in total up to that level), and
       then we add exactly 1 node on level h.
       Hence, minimum number of elements = 2^h.

     - Maximum number of elements:
       If all levels 0 through h are completely filled, then
       the total number of elements is:
         2^(h+1) - 1.

     Therefore:
       Minimum = 2^h
       Maximum = 2^(h+1) - 1

  -------------------------------------------------------------
  2) Show that an n-element heap has height floor(log n).

     - A binary heap is a complete binary tree.
       In a complete binary tree with n nodes, the height is
       O(log n), more precisely floor(log2(n)).

     - Reasoning:
       If the height is h, then the minimum number of nodes
       is 2^h, and the maximum number of nodes is 2^(h+1)-1.
       So if n is the number of nodes:
         2^h <= n <= 2^(h+1) - 1.
       Taking log base 2:
         h <= log2(n) < h+1
       Thus h = floor(log2(n)).

  -------------------------------------------------------------
  3) Where in a max-heap might the smallest element reside,
     assuming all elements are distinct?

     - In a max-heap, every parent is larger than (or equal to)
       its children. Therefore, the smallest element cannot
       be near the top; it has no upper bound that forces it
       to be higher. The smallest element must appear in one
       of the leaves (the bottom level or near the bottom if
       the last level is not completely full).
     - Conclusion: The smallest element is among the leaves.

  -------------------------------------------------------------
  4) Is a sorted array a min-heap?

     - If the array is sorted in ascending order, say
       A[1] <= A[2] <= ... <= A[n],
       then for any index i, the parent index is floor(i/2).
       Because the array is sorted ascending, we have:
         A[floor(i/2)] <= A[i].
       This satisfies the min-heap property that a node is
       never smaller than its parent.
     - Conclusion: Yes, an array sorted in ascending order
       (smallest to largest) is indeed a min-heap.

  -------------------------------------------------------------
  5) Is the array [23, 17, 14, 6, 13, 10, 15, 7, 12] a max-heap?

     - Let's label these as A[1..9]:
       A[1] = 23
       A[2] = 17
       A[3] = 14
       A[4] = 6
       A[5] = 13
       A[6] = 10
       A[7] = 15
       A[8] = 7
       A[9] = 12

       Check the max-heap property: A[i] >= A[2i] and A[i] >= A[2i+1],
       if those children exist.

       - i = 1: A[1] = 23, children are A[2] = 17, A[3] = 14
                23 >= 17 (OK), 23 >= 14 (OK)
       - i = 2: A[2] = 17, children are A[4] = 6, A[5] = 13
                17 >= 6 (OK), 17 >= 13 (OK)
       - i = 3: A[3] = 14, children are A[6] = 10, A[7] = 15
                14 >= 10 (OK), but 14 >= 15? (NO, 14 < 15) => FAIL

       Because 14 < 15 for the child, the max-heap property
       is violated.
       Conclusion: This array is NOT a max-heap.

  -------------------------------------------------------------
  6) Show that with the array representation for storing an
     n-element heap, the leaves are the nodes indexed by
     floor(n/2)+1, ..., n.

     - In a 1-based index heap, the children of node i are
       indices 2i and 2i+1 (if they are <= n).
       The last node that can have a child is i = floor(n/2),
       because 2*floor(n/2) is at most n.
     - Therefore, any index i > floor(n/2) cannot have children,
       so these nodes must be leaves.
       Hence, the leaves are precisely the indices:
         floor(n/2) + 1, floor(n/2) + 2, ..., n.
  -------------------------------------------------------------
*/

/*
 * Function: isMaxHeap
 * -------------------
 *  Checks if the given array (1-based indexing) is a max-heap.
 *
 *  Parameters:
 *    arr: the array (1-based indexing) storing the heap
 *    n:   number of elements in arr
 *
 *  Returns: true if arr is a valid max-heap, false otherwise.
 */
bool isMaxHeap(const vector<int> &arr, int n)
{
    // We only need to check the internal nodes: 1..floor(n/2)
    for (int i = 1; i <= n / 2; i++)
    {
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;

        // If left child exists, check max-heap property
        if (leftChild <= n && arr[i] < arr[leftChild])
        {
            return false;
        }
        // If right child exists, check max-heap property
        if (rightChild <= n && arr[i] < arr[rightChild])
        {
            return false;
        }
    }
    return true;
}

/*
 * Function: isMinHeap
 * -------------------
 *  Checks if the given array (1-based indexing) is a min-heap.
 *
 *  Parameters:
 *    arr: the array (1-based indexing)
 *    n:   number of elements
 *
 *  Returns: true if arr is a valid min-heap, false otherwise.
 */
bool isMinHeap(const vector<int> &arr, int n)
{
    for (int i = 1; i <= n / 2; i++)
    {
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;

        // If left child exists, check min-heap property
        if (leftChild <= n && arr[i] > arr[leftChild])
        {
            return false;
        }
        // If right child exists, check min-heap property
        if (rightChild <= n && arr[i] > arr[rightChild])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    // 1) Minimum and maximum number of elements in a heap of height h
    //    Let's pick an example h=3 just to illustrate in code:
    int h = 3;
    int minElements = (int)pow(2, h);         // 2^h
    int maxElements = (int)pow(2, h + 1) - 1; // 2^(h+1) - 1

    cout << "1) For a heap of height h = " << h << ":\n";
    cout << "   Minimum number of elements = 2^h = " << minElements << endl;
    cout << "   Maximum number of elements = 2^(h+1) - 1 = " << maxElements << endl;
    cout << endl;

    // 2) Show that an n-element heap has height floor(log2(n)).
    //    We'll pick an n and demonstrate:
    int n = 20; // example
    // height ~ floor(log2(n))
    int heapHeight = (int)floor(log2(n));
    cout << "2) For n = " << n << ", floor(log2(n)) = " << heapHeight << "." << endl;
    cout << "   This illustrates that a complete binary tree with "
         << n << " nodes has height " << heapHeight << "." << endl;
    cout << endl;

    // 3) Where might the smallest element reside in a max-heap (distinct elements)?
    cout << "3) In a max-heap with distinct elements, the smallest element\n";
    cout << "   must be among the leaves (bottom level) of the heap.\n";
    cout << endl;

    // 4) Is a sorted array a min-heap?
    //    Let's demonstrate with a small sorted array in ascending order:
    vector<int> sortedArr = {0, 1, 2, 3, 4, 5};
    // We will treat this as 1-based by ignoring index 0 or adjusting:
    // So let's shift to truly 1-based for clarity:
    // Our 'sortedArr' has size = 6, but index 0 is a dummy here.
    // Actually let's keep it as is, but remember to pass 'n=5' to isMinHeap.
    bool checkMin = isMinHeap(sortedArr, 5); // ignoring the 0th index as dummy
    cout << "4) Checking if array [1, 2, 3, 4, 5] is a min-heap: "
         << (checkMin ? "Yes" : "No") << endl;
    cout << "   Indeed, a sorted ascending array is always a valid min-heap.\n";
    cout << endl;

    // 5) Is array [23, 17, 14, 6, 13, 10, 15, 7, 12] a max-heap?
    //    We'll store it 1-based:
    vector<int> arrCheck = {0, 23, 17, 14, 6, 13, 10, 15, 7, 12};
    // size is 10, but the 0th is dummy, so real n = 9
    bool checkMax = isMaxHeap(arrCheck, 9);
    cout << "5) Checking if array [23, 17, 14, 6, 13, 10, 15, 7, 12] is a max-heap: "
         << (checkMax ? "Yes" : "No") << endl;
    cout << "   We find that it fails because A[3] = 14 < A[7] = 15.\n";
    cout << "   So it is NOT a valid max-heap.\n";
    cout << endl;

    // 6) Leaves in array representation are the nodes indexed by floor(n/2)+1 to n.
    //    Let's illustrate with n=9:
    int exampleN = 9;
    int firstLeafIndex = exampleN / 2 + 1; // floor(n/2) + 1
    cout << "6) For n = " << exampleN << ", the leaves start at index = "
         << firstLeafIndex << " through index = " << exampleN << ".\n";
    cout << "   That is, indices: 5, 6, 7, 8, 9 (in 1-based indexing).\n";
    cout << "   None of these can have children because 2*i would exceed n.\n";
    cout << endl;

    cout << "End of all explanations and demonstrations.\n";
    return 0;
}
