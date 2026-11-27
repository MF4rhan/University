#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// only one pointer is needed: "rear". Since the last node always
// points back to the first node, the front is just rear->next.
class CircularQueue {
    Node* rear;

public:
    CircularQueue() {
        rear = nullptr;
    }

    bool is_empty() {
        return rear == nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;

        if (is_empty()) {
            newNode->next = newNode;   // single node points to itself
            rear = newNode;
        } else {
            newNode->next = rear->next;   // new node points to the current front
            rear->next = newNode;         // old rear now points to the new node
            rear = newNode;               // new node becomes the rear
        }
    }

    void dequeue() {
        if (is_empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* front = rear->next;

        if (front == rear) {
            // only one node was in the queue
            rear = nullptr;
        } else {
            rear->next = front->next;   // skip over the old front
        }
        delete front;
    }

    int peek() {
        if (is_empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return rear->next->data;   // front is always rear->next
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();          // removes 10
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front after operations: " << q.peek() << endl;
    cout << "Is empty? " << (q.is_empty() ? "Yes" : "No") << endl;

    return 0;
}