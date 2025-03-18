#include <iostream>
using namespace std;

int Factorial(int n)
{
    int b = Factorial(n - 1);
    n = n * b;
    Factorial(n - 1);
    return n;
}
int main()
{
    Factorial(5);
    return 0;
}