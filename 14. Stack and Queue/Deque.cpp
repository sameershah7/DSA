#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // Deque can act as both Stack and Queue
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Pop from front and back
    dq.pop_front();
    // dq.pop_back();

    for (int x : dq)
        cout << x << " ";

    return 0;
}