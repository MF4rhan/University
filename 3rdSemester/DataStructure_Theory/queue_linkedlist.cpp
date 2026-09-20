#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool is_empty() {
        return front == nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        if (is_empty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;   // link old rear to the new node
            rear = newNode;         // new node becomes the rear
        }
    }

    void dequeue() {
        if (is_empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr)   // queue became empty after this removal
            rear = nullptr;
        delete temp;
    }

    int peek() {
        if (is_empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    cout << "Front after dequeue: " << q.peek() << endl;

    cout << "Is empty? " << (q.is_empty() ? "Yes" : "No") << endl;

    return 0;
}