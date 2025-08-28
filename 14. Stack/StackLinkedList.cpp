#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

// Stack using linked list
class Stack
{
    Node *head;

public:
    // Check if the stack is empty
    bool isEmpty()
    {
        return this->head == nullptr;
    }

    // Push element onto the stack
    void push(int new_data)
    {
        Node *new_node = new Node(new_data);
        new_node->next = head;
        head = new_node;
    }

    // Pop the top element
    void pop()
    {
        if (isEmpty())
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Return the top element
    int peek()
    {
        if (!isEmpty())
            return head->data;
        return INT_MIN;
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << st.peek() << endl;

    st.pop();
    st.pop();

    cout<<st.peek()<<endl;
}