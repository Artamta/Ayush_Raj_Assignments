#include <iostream>
using namespace std;

void Sorted(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] < a[i] - 1)
        {
            break;
            cout << " Not sorted" << endl;
        }
        else
        {
            cout << "array is sorted" << endl;
        }
    }
}
int main()
{

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {4, 3, 5, 6, 4};
    // Sorted(a, 5);
    cout << Sorted(b[], 5) << endl;
    return 0;
}