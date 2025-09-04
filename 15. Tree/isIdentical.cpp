#include <bits/stdc++.h>
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

// bool isIdentical(Node *t1, Node *t2)
// {
//     if (t1 == nullptr && t2 == nullptr)
//         return true;
//     if (t1 == nullptr || t2 == nullptr)
//         return false;
//     return (t1->data == t2->data) &&
//            isIdentical(t1->left, t2->left) &&
//            isIdentical(t1->right, t2->right);
// }

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == nullptr && r2 == nullptr)
        return true;

    if (r1 == nullptr || r2 == nullptr)
        return false;

    // using two queue for level order traversal
    queue<Node *> q1, q2;
    q1.push(r1);
    q2.push(r2);

    while (!q1.empty() && !q2.empty())
    {
        Node *node1 = q1.front();
        Node *node2 = q2.front();
        q1.pop();
        q2.pop();

        if (node1->data != node2->data)
            return false;

        // Check the left
        if (node1->left && node2->left)
        {
            q1.push(node1->left);
            q2.push(node2->left);
        }
        else if (node1->left || node2->left)
            return false;

        // check the right
        if (node1->right && node2->right)
        {
            q1.push(node1->right);
            q2.push(node2->right);
        }
        else if (node1->right || node2->right)
            return false;
    }
    return q1.empty() && q2.empty();
}

int main()
{

    Node *r1 = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(3);
    r1->left->left = new Node(4);

    Node *r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);
    r2->left->left = new Node(4);

    if (isIdentical(r1, r2))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}