#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> stack;

    stack.push_back(10);
    stack.push_back(20);
    stack.push_back(30);

    cout << stack.back() << " popped from deque" << endl;
    stack.pop_back();
    cout << "Top element is: " << stack.back() << endl;
    return 0;
}
