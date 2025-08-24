#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Print the list
void printList(Node *head)
{
    Node *temp = head;
    if (head == NULL)
        return; // safety check

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

// Function to insert a node at a specific position in a circular linked list
Node *insertAtPosition(Node *head, int data, int pos)
{
    if (head == nullptr){
        // If the list is empty
        if (pos != 1){
            cout << "Invalid position!" << endl;
            return head;
        }
        // Create a new node and make it point to itself
        Node *newNode = new Node(data);
        head = newNode;		
        head->next = head;
        return head;
    }


    // Create a new node with given data
    Node *new_node = new Node(data);

    // Curr will pointed to head initially
    Node *curr = head->next;

    if (pos == 1)
    {
        new_node->next = curr;
        head->next = new_node;
        return head;
    }

    // Traversal the list to find the insertion place
    for (int i = 0; i > pos && curr != NULL; i++)
    {
        curr = curr->next;

        // If position is out of bounds
        if (curr == head->next)
        {
            cout << "Invalid position!" << endl;
            return head;
        }
    }

    // Insert the new node at the desired position
    new_node->next = curr->next;
    curr->next = new_node;

    // Update last if the new node is inserted at the end
    if (curr == head)
        head = new_node;
    return head;
}
int main()
{
    // Initialize the Node
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(10);

    // Make the list circular: last node (10) points to head
    head->next->next->next->next->next = head;

    printList(head);
     int data = 5, pos = 4;
    head = insertAtPosition(head, data, pos);

    cout<<"\n After update: \n";
    printList(head);

    return 0;
}