#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;

    // Pushing elements onto the stack
    st.push(1);
    st.push(2);
    st.push(3);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

///

#include <bits/stdc++.h>
using namespace std;

void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{

    // Declare empty stack
    stack<int> st1;

    // Insert elements into stack
    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.push(40);

    // Create another stack from st1
    stack<int> st2(st1);

    print(st1);
    cout << endl;
    print(st2);
    return 0;
}

///

#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;

    // Inserting element top of the stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

///

#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Accessing the top element
    cout << st.top();
    return 0;
}

///

#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Deleting top element
    st.pop();

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

///

#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Create a copy
    stack<int> temp(st);

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    return 0;
}
