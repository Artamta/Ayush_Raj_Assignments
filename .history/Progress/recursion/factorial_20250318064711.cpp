#include <iostream>
using namespace std;

int Factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * n - 1;
    }
}
int main()
{
    cout << Factorial(1) << endl;
    return 0;
}