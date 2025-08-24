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

// Function to remove every k-th node in linked list
Node *deleteK(Node *head, int k)
{
    // If the head id empty or key value is zero return head
    if (head == nullptr || k <= 0)
    {
        return head;
    }

    Node *curr = head;
    Node *prev = nullptr;

    // Initialize the counter to trace node position
    int count = 0;

    // Traverse the linked list
    while (curr != nullptr)
    {
        count++;
        // If the count is multiple of k, remove current node
        if (count % k == 0)
        {

            // Skip the current node
            if (prev != nullptr)
            {
                prev->next = curr->next;
            }
            else
            {

                head = curr->next;
            }
        }
        else
        {
            // Update the previous pointer only if we did not remove the node
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

void printList(Node *head)
{

    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(8);
    int k = 2;
    head = deleteK(head, k);
    printList(head);

    return 0;
}