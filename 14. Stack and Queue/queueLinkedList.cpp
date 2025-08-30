#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Function to enqueue
    void enqueue(int x)
    {
        Node *new_node = new Node(x);
        if (isEmpty())
        {
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        rear = new_node;
    }

    // Function to deque
    void dequeue()
    {
        if (isEmpty())
            return;

        Node *temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    // Function to print the current state of the queue
    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty: " << endl;
        }
        Node *temp = front;
        cout << "Current Queue" << endl;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.dequeue();
    q.dequeue();

    q.printQueue();

    return 0;
}
