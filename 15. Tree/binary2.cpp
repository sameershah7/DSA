#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

// Function to deleted the deepest node with binary tree
void deleteDeepest(Node *root, Node *dNode)
{
    queue<Node *> q;
    q.push(root);

    Node *curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        
        // if the current node is the deepest node then delete it
        if (curr == dNode)
        {
            curr = nullptr;
            delete (dNode);
            return;
        }

        // check the right child first
        if (curr->right)
        {
            if (curr->right == dNode)
            {
                curr->right = nullptr;
                delete (dNode);
                return;
            }
            q.push(curr->right);
        }


        // then check the left child
        if (curr->left)
        {
            if (curr->left == dNode)
            {
                curr->left = nullptr;
                delete (dNode);
                return;
            }
            q.push(curr->left);
        }
    }
}

// Function to delete with the given key
Node *deletion(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;

    if (root->left == nullptr && root->right == nullptr)
    {
        if (root->data == key)
            return nullptr;
        else
            return root;
    }

    queue<Node *> q;
    q.push(root);

    Node *curr;
    Node *keyNode = nullptr;

    // Level order traversal find the deepest node and the key node
    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        // if the current node is the key
        if (curr->data == key)
            keyNode = curr;

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }

    // if key node is found, replay it's data with the deepest node
    if (keyNode != nullptr)
    {
        int x = curr->data;

        // Replace key node data with the deepest node data
        keyNode->data = x;
        deleteDeepest(root, curr);

    }

    return root;
}

// inorder Traversal
void inorder(Node *node)
{
    if (!node)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    int key = 10;
    root = deletion(root, key);

    inorder(root);
    return 0;
}