#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void mirror(Node *root)
{
    if (root == nullptr)
        return;

    mirror(root->left);
    mirror(root->right);

    swap(root->left, root->right);
}

void levelOrder(Node *root)
{
    if (root == nullptr)
    {
        cout << "N ";
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == nullptr)
        {
            cout << "N ";
            continue;
        }
        cout << (curr->data) << " ";
        q.push(curr->left);
        q.push(curr->right);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    mirror(root);
    levelOrder(root);
    return 0;
}