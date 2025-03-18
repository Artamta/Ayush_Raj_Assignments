#include <iostream>
using namespace std;

void PrintNum(int n)
{
    if (n == 1)
    {
        cout << " 1 " << endl;
    };
    else
    {

        cout << n << " ";
    };
}

int main()
{
    PrintNum(100);

    return 0;
}