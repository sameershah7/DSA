#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

// Counts the no. of occurrences of a key in a linked list using  Recursion Method
int countRecMethod(Node *head, int key)
{
    if (head == nullptr)
        return 0;

    int ans = countRecMethod(head->next, key);

    if (head->data == key)
    {
        ans++;
    }
    return ans;
}

// Counts the no. of occurrences of a key in a linked list using traversal Method
int TraversalMethod(Node *head, int key)
{
    Node*curr = head;
    int count = 0;
    while (curr!= nullptr)
    {
        if(curr->data == key)
            count ++;
        curr = curr->next;
    }

    return count;
    
}

int main()
{
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(2);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(2);

    int key = 2;

    // cout << countRecMethod(head, key);
    cout << TraversalMethod(head, key);

    return 0;
}