#include <iostream>
#include <vector>

using namespace std;
class Queue
{
    vector<int> q;

public:
    bool is_Empty() { return q.empty(); }

    void enqueue(int x)
    {
        q.push_back(x);
    }

    void dequeue()
    {
        if (!is_Empty())
            q.erase(q.begin());
    }

    int getFront()
    {
        return is_Empty() ? -1 : q.front();
    }

    void display()
    {
        for (auto i : q)
            cout << i << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.dequeue();


    cout <<"Get Front: "<<  q.getFront() << endl;
    q.display();
}
