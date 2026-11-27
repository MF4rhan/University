#include <iostream>
using namespace std;

#define MAX 100  // maximum size of the stack

class Stack {
    int arr[MAX];   // static array to hold stack elements
    int top;        // index of the top element

public:
    Stack() {
        top = -1;   // empty stack -> top = -1
    }

    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (is_full()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;   // move top up first, then insert
    }

    void pop() {
        if (is_empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;   // just move top down, "removes" the element
    }

    int peek() {
        if (is_empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
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