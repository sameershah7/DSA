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

bool isIdentical(Node *t1, Node *t2)
{
    if (t1 == nullptr && t2 == nullptr)
        return true;

    if (t1 == nullptr || t2 == nullptr)
        return false;

    return (t1->data == t2->data) &&
           isIdentical(t1->left, t2->left) &&
           isIdentical(t1->right, t2->right);
}

int main() {

    Node* r1 = new Node(1);    
    r1->left = new Node(2);   
    r1->right = new Node(3); 
    r1->left->left = new Node(4); 


    Node* r2 = new Node(1);    
    r2->left = new Node(2);   
    r2->right = new Node(3);  
    r2->left->left = new Node(4);

    if (isIdentical(r1, r2))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}