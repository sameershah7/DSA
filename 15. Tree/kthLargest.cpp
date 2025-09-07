#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to perform Morris Traversal and return kth largest element
int kthLargest(Node* root, int k) {
    if (root == nullptr) return -1;
    
    Node* curr = root;
    int cnt = 0;
    
    while (curr != nullptr) {
        
        if (curr->right == nullptr) {
            cnt++;
            
            if (cnt == k) 
                return curr->data;
                
            curr = curr->left;    
        }
        else {
            Node* succ = curr->right;
            
            while (succ->left != nullptr && succ->left != curr) {
                succ = succ->left;
            }
           
            if (succ->left == nullptr) {
                succ->left = curr;
                curr = curr->right;
            }
            
            else {
                cnt++;  
                
                succ->left = nullptr;
                
                if (cnt == k) 
                    return curr->data;
                
                curr = curr->left;
            }
        }
    }
    
    return -1;
}

int main() {

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    
    int k = 3;
    
    cout << kthLargest(root, k) << endl;

    return 0;
}