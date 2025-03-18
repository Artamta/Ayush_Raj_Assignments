#include <iostream>
using namespace std;

bool IsSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    else
    {
        return arr[n - 1] >= arr[n - 2] || IsSorted(arr, n - 1);
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int size = 5;
    int b[] = {2, 1, 3, 2, 1};
    cout << IsSorted(a, size) << endl;
    return 0;
}