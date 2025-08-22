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

// Function to insert a new node at the end of the list
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

// Delete the head node and return the new head
Node *deleteHead(Node *head)
{
    if (head == nullptr)
        return nullptr;

    // Store the current head in the temporary variable
    Node *temp = head;

    // Move the next pointer to the next node
    head = head->next;

    // free the memory of the old node
    delete temp;
    return head;
}

// Function to remove the last node of the linked list
Node *deleteLastNode(Node *head)
{
    if (head == nullptr)
        return nullptr;

    // check if the list is One node
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    // Find the last node
    Node *second_last = head;
    while (second_last->next->next != nullptr)
    {
        second_last = second_last->next;
    }

    // Deleted the last node
    delete second_last->next;

    // Change next of second last
    second_last->next = nullptr;

    return head;
}

// Function to delete a node at a given position
Node *deleteNodePos(Node *head, int position)
{
    Node *prev;
    Node *temp = head;

    if (temp == NULL)
        return head;

    if (position == 1)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    // Node to be deleted is in middle Traverse till given position
    for (int i = 1; i != position; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the position is fond then delete node
    if (temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }
    // If given position is not present
    else
    {
        cout << "Data not present\n";
    }

    return head;
}

// Given the head of a list, reverse the list and return the head of reversed list
Node *reverseList(Node *head)
{
    // Initialize three pointer curr, prev and next
    Node *curr = head, *prev = nullptr, *next;

    // Traverse all the node of linked list
    while (curr != nullptr)
    {
        // Store next
        next = curr->next;

        //Reverse current node's next pointer
        curr->next = prev;

        // Move pointer one position ahead
        prev = curr;
        curr = next;
    }

    //return the head of the current linked list 
    return prev;
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
    int position = 3;

    cout << "Original list: " << endl;
    traverseList(head);

    // cout << "Seachin key: " << searchKey(head, key);
    // head = insertAtFront(head, insVal);
    // head = insertAtEnd(head, insVal);
    // insertPos(head, position, key);
    // head = deleteHead(head);
    // head = deleteLastNode(head);
    // head = deleteNodePos(head, position);
    head = reverseList(head);

    cout << "List after modify: " << endl;
    traverseList(head);

    return 0;
}