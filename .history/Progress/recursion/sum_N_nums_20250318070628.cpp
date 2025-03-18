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

        return n + SumNum(n - 1);
    }
}
int main()
{
    cout << SumNum(3) << endl;

    return 0;
}