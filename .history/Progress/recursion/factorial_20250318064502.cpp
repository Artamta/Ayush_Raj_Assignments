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
        int b = Factorial(n - 1);
        n = n * b;
        Factorial(n);
        return n;
    }
}
int main()
{
    Factorial(5);
    return 0;
}