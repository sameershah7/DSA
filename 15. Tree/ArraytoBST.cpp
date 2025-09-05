#include <iostream>
#include <vector>
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
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node *sortedArrayToBSTRecur(vector<int> &arr, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    Node *root = new Node(arr[mid]);

    // Create left subtree
    root->left = sortedArrayToBSTRecur(arr, start,
                                       mid - 1);

    // Create right subtree
    root->right = sortedArrayToBSTRecur(arr, mid + 1,
                                        end);
    return root;
}

Node *sortedArrayToBST(vector<int> &arr)
{
    int n = arr.size();
    return sortedArrayToBSTRecur(arr, 0, n - 1);
}

void preOrder(Node *node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 6, 7, 8};
    Node *root = sortedArrayToBST(arr);
    preOrder(root);

    return 0;
}