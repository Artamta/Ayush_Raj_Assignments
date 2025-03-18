#include <iostream>
using namespace std;

int Sorted(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] > a[i] - 1)
        {
            return 1;
        }
        else
        {
            cout << "array is not sorted" << endl;
        }
    }
};
int main()
{

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {4, 3, 5, 6, 4};
    // Sorted(a, 5);
    Sorted(b, 5);
    return 0;
}