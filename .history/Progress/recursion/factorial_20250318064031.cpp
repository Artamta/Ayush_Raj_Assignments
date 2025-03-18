#include <iostream>
using namespace std;

void Factorial(int n)
{
    n *Factorial(n - 1);
    Factorial(n - 1);
}
int main()
{
    Factorial(5) return 0;
}