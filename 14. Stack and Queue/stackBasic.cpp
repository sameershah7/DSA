#include <iostream>
using namespace std;

int MAXSIZE = 8;
int stack[8];
int top = -1;

// Check if the stack is full
int full()
{
    if (top == MAXSIZE)
    {
        return 1;
    }
    return 0;
}

// Check if the Stack is empty
int empty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

// Function to insert into stack
int push(int x)
{
    if (!full())
    {
        top++;
        stack[top] = x;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
    return 0;
}

// Function to delted from stack
int pop()
{
    int data;
    if (!empty())
    {
        data = stack[top];
        top--;
        return data;
    }
    else
    {
        cout << "The stack is empty " << endl;
    }
    return 0;
}

// Function to return peek element of the stack
int peek()
{
    if (!empty())
    {
        return stack[top];
    }

    return 0;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    pop();
    pop();

    if (empty())
        cout << "The Stack is empty:" << endl;

    if (full())
        cout << "The stack is full" << endl;

    if (peek())
        cout << "Peek element of the stack: " << peek() << endl;

    // Print stack data
    while (!empty())
    {
        int data = pop();
        cout << data << endl;
    }

    return 0;
}