#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);

    // Print deque elements
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Pop from front and back
    dq.pop_front();
    dq.pop_back();

    // Print deque elements after pop
    for (int x : dq)
        cout << x << " ";

    return 0;
}
