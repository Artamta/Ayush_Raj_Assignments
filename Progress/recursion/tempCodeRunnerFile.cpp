#include <iostream>
using namespace std;

bool Sorted(int n[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (n[i] < n[i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {4, 3, 5, 6, 1};
    // Sorted(a, 5);
    Sorted(a, 5);
    return 0;
}    if (Sorted(a, 5))
    {
        cout << "Array a is sorted" << endl;
    }
    else
    {
        cout << "Array a is not sorted" << endl;
    }

    if (Sorted(b, 5))
    {
        cout << "Array b is sorted" << endl;
    }
    else
    {
        cout << "Array b is not sorted" << endl;
    }
