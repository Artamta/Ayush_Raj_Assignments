#include <iostream>
using namespace std;

void Factorial(int n)
{
    int b = Factorial(n - 1);
    n = n * b;
    Factorial(n - 1);
}
int main()
{
    Factorial(5);
    return 0;
}