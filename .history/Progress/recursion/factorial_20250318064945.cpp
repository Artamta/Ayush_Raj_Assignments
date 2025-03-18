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
    int number;
    cout << " enter your number " << " --> ";
    cin >> number;
    cout << Factorial(number) << endl;
    return 0;
}