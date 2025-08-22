#include <bits/stdc++.h>

using namespace std;

// Definition of a Node in a singly linked list
struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to traverse and print the singly linked list
void traverseList(Node *head)
{
    while (head != nullptr)
    {
        // Printing data of the current node
        cout << head->data << " " << endl;

        // Move to the next node
        head = head->next;
    }
    cout << endl;
}

// Checks whether key is present in linked list
bool searchKey(Node *head, int key)
{
    Node *curr = head;
    if (curr == NULL)
        return false;
    if (curr->data == key)
        return true;
    return searchKey(curr->next, key);
}

// Function to insert a new node at the beginning of the list
Node *insertAtFront(Node *head, int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->next = head;
    return new_node;
}

Node *insertAtEnd(Node *head, int new_data)
{
    Node *new_node = new Node(new_data);

    if (head == nullptr)
        return new_node;

    Node *last = head;

    while (last->next != nullptr)
        last->next = last;

    last->next = new_node;

    return head;
}

// function to insert a Node at required position
Node *insertPos(Node *head, int pos, int new_data)
{
    if (pos < 1)
        return head;

    // head will change if pos=1
    if (pos == 1)
    {
        Node *newNode = new Node(new_data);
        newNode->next = head;
        return newNode;
    }

    Node *curr = head;

    for (int i = 1; i < pos - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == nullptr)
        return head;

    Node *newNode = new Node(new_data);

    // update the next pointers
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(14);
    head->next->next->next = new Node(16);
    head->next->next->next->next = new Node(18);

    int key = 11;
    int insVal = 12;

    // cout << "Seachin key: " << searchKey(head, key);
    // head = insertAtFront(head, insVal);
    // head = insertAtEnd(head, insVal);
    insertPos(head, 4, key);

    traverseList(head);

    return 0;
}