#include <iostream>
using namespace std;

//Tree: data structure is a non-linear data structure in which a collection of elements known as nodes are connected to each other via edges such that there exists a path between any two nodes.

// implement node of binary tree.
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to print postorder traversal
void printPreOrder(struct Node *node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

// Function to print preOrder traversal
void printInOrder(struct Node *node)
{
    if (node == nullptr)
        return;
    printInOrder(node->left);
    cout << node->data << " ";
    printInOrder(node->right);
}

// Function to print postorder traversal
void printPostorder(struct Node* node)
{
    if (node == nullptr)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

int main()
{
    Node *firstNode = new Node(1);
    Node *second = new Node(2);
    Node *thrid = new Node(3);
    Node *forth = new Node(4);
    Node *fifth = new Node(5);

    // Connect binary tree
    firstNode->right = second;
    firstNode->left = thrid;
    second->right = forth;
    second->left = fifth;

    printPreOrder(firstNode);
    cout<<endl;
    printInOrder(firstNode);
    cout<<endl;
    printPostorder(firstNode);
    
    return 0;
}