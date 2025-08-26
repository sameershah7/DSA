#include <bits/stdc++.h>
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

// Return the count of node present in loop
int countNode (Node *node){
    int res = 1;
    Node * curr  = node;
    while (curr->next != node)
    {
        res++;
        curr = curr->next;
    }

    return res;
}

// This function detect and count loop node in the list
// if the loop is not here then return 0
int countNodesinLoop(Node *head)
{
    Node *slow = head, *fast = head;

    while (slow != nullptr && fast != nullptr)
    {
        slow  = slow->next;
        fast = fast->next->next;

        // If slow and the fast meet at some point then there is a loop 
        if(slow == fast ){
            return countNode(slow);
        }
    }

    // return 0 indicate there in no loop
    return 0;
}


int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Loop from 5 to 3
    head->next->next->next->next->next = head->next->next;
    cout << countNodesinLoop(head) << endl;

    return 0;
}