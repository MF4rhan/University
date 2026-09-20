#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;   // front = index of first element, rear = index of last element

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool is_empty() {
        return front == -1;
    }

    bool is_full() {
        return rear == MAX - 1;
    }

    void enqueue(int x) {
        if (is_full()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (is_empty())
            front = 0;   // first element being added
        arr[++rear] = x;
    }

    void dequeue() {
        if (is_empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if (front == rear) {
            // removing the last remaining element, reset the queue
            front = -1;
            rear = -1;
        } else {
            front++;   // just move front forward
        }
    }

    int peek() {
        if (is_empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
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