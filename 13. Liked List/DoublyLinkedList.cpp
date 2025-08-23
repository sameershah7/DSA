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

// Function to insert a new node at the front of doubly linked list
Node *insertAtFront(Node *head, int new_data)
{
    // Create a new node
    Node *new_node = new Node(new_data);

    // Make next of new node as head
    new_node->next = head;

    // Change a prev of head node to new node
    if (head != NULL)
    {
        head->prev = new_node;
    }

    // Return the new node as the head of the double linked list
    return new_node;
}

// Function to insert a new node after a given node in doubly linked list
Node *insertAfter(Node *head, int key, int new_data)
{
    Node *curr = head;

    while (curr != nullptr)
    {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    // If the given key is not found
    if (curr == nullptr)
        return 0;

    // Create new node
    Node *new_node = new Node(new_data);

    // Set prev of new node to given node
    new_node->prev = curr;

    // Set next of new node to the given node
    new_node->next = curr->next;

    // Update next of given node to new node
    curr->next = new_node;

    // If the given node is not the last node of the linked list
    if (new_node->next != nullptr)
    {
        new_node->next->prev = new_node;
    }

    return head;
}

// Function to insert a new node before a give node in doubly linked list
Node *insertBefore(Node *head, int key, int new_data)
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    // If the key is not found
    if (curr == NULL)
        return 0;

    // Create a new node
    Node *new_node = new Node(new_data);

    // Set prev of new node to prev to the given node
    new_node->prev = curr->prev;

    // Set next of new node to the give node
    new_node->next = curr;

    // Update next of given node's prev to new node
    if (new_node->prev != NULL)
    {
        new_node->prev->next = new_node;
    }
    else
    {
        // if the current node is head, update the head
        head = new_node;
    }

    // Update prev given node to new node
    curr->prev = new_node;

    return head;
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

    int data = 10;
    int index = 2;

    // Print the original list
    forwardTraversal(head);

    // backwordTraversal(head->next->next->next);
    // cout << "Size of linked list: " << findSize(head);
    // head = insertAtFront(head, data);
    // head = insertAfter(head, index, data);
    head = insertBefore(head, index, data);

    // After update the linked list
    forwardTraversal(head);

    return 0;
}