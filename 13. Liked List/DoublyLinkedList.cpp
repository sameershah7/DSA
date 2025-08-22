#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int value)
    {
        data = value;
        prev = next = nullptr;
    }
};

// Traversal forward to the doubly linked list
void forwardTraversal(Node *head)
{
    Node *curr = head;

    while (curr != nullptr)
    {
        cout << curr->data << " ";

        curr = curr->next;
    }
    cout << endl;
}

// Traversal backward double Linked list
void backwordTraversal(Node *tail)
{
    Node *curr = tail;

    while (curr != nullptr)
    {
        cout << curr->data << " ";

        curr = curr->prev;
    }
    cout << endl;
}

// Finding the size of doubly linked list uing recursion method
int findSize(Node *head)
{
    if (head == nullptr)
        return 0;
    return 1 + findSize(head->next);
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    // forwardTraversal(head);
    // backwordTraversal(head->next->next->next);
    // cout << "Size of linked list: " << findSize(head);

    return 0;
}