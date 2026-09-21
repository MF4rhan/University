#include <iostream>
using namespace std;

// each node stores data + pointer to the next node
class Node {
    public:
    int data;
    Node* next;
    
    Node(int dat = 0) : data(dat), next(nullptr)
    {}
};

class Stack {
    Node* top;   // pointer to the topmost node

public:
    Stack() {
        top = nullptr;   // empty stack -> no nodes
    }

    bool is_empty() {
        return top == nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;   // new node points to old top
        top = newNode;         // new node becomes the top
    }

    void pop() {
        if (is_empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;   // move top pointer down
        delete temp;        // free the removed node's memory
    }

    int peek() {
        if (is_empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Top after pop: " << s.peek() << endl;

    cout << "Is empty? " << (s.is_empty() ? "Yes" : "No") << endl;

    return 0;
}