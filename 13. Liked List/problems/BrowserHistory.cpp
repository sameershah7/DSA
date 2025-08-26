#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node *prev;

    Node(string x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class BrowserHistory
{
public:
    Node *curr;

    // Constructor to initialize home page
    BrowserHistory(string homepage)
    {
        curr = new Node(homepage);
    };

    // Function to visid new url
    void visit(string url)
    {
        Node *urlNode = new Node(url);

        urlNode->prev = curr;

        curr->next = urlNode;

        curr = urlNode;
    }

    // The function to movie back by step time
    string back(int step)
    {
        Node *tra = curr;

        // Travel back if step posable
        while (tra->prev != nullptr && step > 0)
        {
            tra = tra->prev;
            step--;
        }

        // Update the current pointer moving back
        curr = tra;
        return curr->data;
    }

    // Function to move forward by step time
    string forward(int step)
    {
        Node *tra = curr;

        // Travel forward step if the possible
        while (tra->next != nullptr && step > 0)
        {
            tra = tra->next;
            step--;
        }

        curr = tra;
        return curr->data;
    }
};

int main()
{
    string homepage = "Eduction.org";
    BrowserHistory obj(homepage);

    string url = "google.com";
    obj.visit(url);

    url = "facebook.com";
    obj.visit(url);

    url = "youtube.com";
    obj.visit(url);

    cout << obj.back(1) << endl;
    cout << obj.back(1) << endl;
    cout << obj.forward(1) << endl;
    obj.visit("linkedin.com");
    cout << obj.back(0) << endl;
}