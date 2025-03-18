#include <iostream>
using namespace std;

void Sorted(int n[], int size)
{
    for (int i = 1; i < size + 1; i++)
    {
        if (n[i] < n[i - 1])
        {
            break;
        }
        else
        {
            cout << "array is sorted" << endl;
        }
    }
    cout << " Not sorted" << endl;
}
int main()
{

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {4, 3, 5, 6, 1};
    // Sorted(a, 5);
    Sorted(a, 5);
    return 0;
}