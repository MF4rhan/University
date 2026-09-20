#include <iostream>
using namespace std;

#define MAX 4   // kept small so the wraparound is easy to see

class CircularQueue {
    int arr[MAX];
    int front, rear;
    int count;   // how many elements are currently in the queue

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool is_empty() {
        return count == 0;
    }

    bool is_full() {
        return count == MAX;
    }

    void enqueue(int x) {
        if (is_full()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % MAX;   // wrap back to index 0 once we pass the end
        arr[rear] = x;
        count++;
    }

    void dequeue() {
        if (is_empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front = (front + 1) % MAX;   // move front forward, wrapping if needed
        count--;
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
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();       // removes 10, freeing up a slot at the front
    q.enqueue(40);
    q.enqueue(50);      // this one wraps around and reuses the freed slot

    cout << "Front after operations: " << q.peek() << endl;
    cout << "Is full? " << (q.is_full() ? "Yes" : "No") << endl;

    return 0;
}