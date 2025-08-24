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

// Function to get the middle of the linked list
int getMiddle(Node *head)
{

    // Initialize the slow and the fast pointer to head of linked list
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        // Move the slow pointer by one
        slow_ptr = slow_ptr->next;

        // Move the fast pointer by two node
        fast_ptr = fast_ptr->next->next;
    }
    // Return the slow pointer which is currently pointing to the middle node of the linked list
    return slow_ptr->data;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    cout << getMiddle(head) << endl;

    return 0;
}