// Stack is a linear data structure that follows LIFO (Last In First Out) Principle, the last element inserted is the first to be popped out. It means both insertion and deletion operations happen at one end only.
#include <bits/stdc++.h>
using namespace std;

// Implementation using Fixed Sized Array
class Stack
{
    int top, cap;
    int *a;

public:
    Stack(int cap)
    {
        this->cap = cap;
        top = -1;
        a = new int[cap];
    }

    ~Stack()
    {
        delete[] a;
    }

    bool push(int x)
    {
        if (top >= cap - 1)
        {
            cout << "Stack Overflow\n";
            return false;
        }
        a[++top] = x;
        return true;
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow\n";
            return 0;
        }
        return a[top--];
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is Empty\n";
            return 0;
        }
        return a[top];
    }

    bool isEmpty()
    {
        return top < 0;
    }
};

int main()
{
    // Stack s(5);
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // cout << s.pop() << " popped from stack\n";
    // cout << "Top element is: " << s.peek() << endl;

    // cout << "Elements present in stack: ";
    // while (!s.isEmpty()) {
    //     cout << s.peek() << " ";
    //     s.pop();
    // }

    // Implementation using Dynamic Sized Array
    vector<int> s;
    // Push elements
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);

    // Pop and print the top element
    cout << s.back() << " popped from stack\n";
    s.pop_back();

    // Peek at the top element
    cout << "Top element is: " << s.back() << endl;

    // Present element in stack
    while (!s.empty())
    {
        cout << s.back() << " ";
        s.pop_back();
    }

    return 0;
}