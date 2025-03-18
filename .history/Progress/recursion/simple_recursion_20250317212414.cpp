#include <iostream>
using namespace std;

void PrintNum(int n)
{
    if (n == 1)
    {
        cout << " 1 " << endl;
    };
    else if
    {

        cout << n << " ";
        PrintNum(n - 1);
    };
    else
    {
        cout << "nothing" << endl;
    }
}

int main()
{
    PrintNum(100);

    return 0;
}