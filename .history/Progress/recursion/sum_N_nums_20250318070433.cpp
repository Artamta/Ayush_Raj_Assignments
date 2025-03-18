#include <iostream>
using namespace std;

int SumNum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        SumNum(n - 1);
        return n + n - 1;
        SumNum(n - 1)
    }
}
int main()
{
    cout << SumNum(4) << endl;

    return 0;
}