#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> s1, s2;
    void enqueue(int x)
    {
        // move all element s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // push items to s1
        s1.push(x);

        // Push every things to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // dequeue item from stack
    int dequeue()
    {
        if (s1.empty())
            return -1;

        // Return the top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';

    return 0;
}
