#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node *root)
{
    if (root == nullptr)
        return -1;

    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

int main()
{

    Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    cout << height(root);

    return 0;
}

#include <iostream>
using namespace std;

