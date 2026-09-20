#include <iostream>
#include <string>
using namespace std;

#define MAX 100

// ---------- Stack using array ----------
class ArrayStack {
    char arr[MAX];
    int top;
public:
    ArrayStack() { top = -1; }
    bool is_empty() { return top == -1; }
    void push(char x) { arr[++top] = x; }
    char pop() { return arr[top--]; }
};

// ---------- Stack using linked list ----------
struct Node {
    char data;
    Node* next;
};

class LinkedListStack {
    Node* top;
public:
    LinkedListStack() { top = nullptr; }
    bool is_empty() { return top == nullptr; }

    void push(char x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        char val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
};

// version that uses the array-based stack
bool isBalanced(string expr, ArrayStack &s) {
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.is_empty()) return false;   // nothing to match closing bracket
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;   // wrong bracket type
        }
    }
    return s.is_empty();
}

// same logic, but using the linked-list-based stack
bool isBalanced(string expr, LinkedListStack &s) {
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.is_empty()) return false;
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }
    return s.is_empty();
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";

    cout << "[Array Stack]\n";
    ArrayStack arrS1, arrS2;
    cout << expr1 << " -> " << (isBalanced(expr1, arrS1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << " -> " << (isBalanced(expr2, arrS2) ? "Balanced" : "Not Balanced") << endl;

    cout << "\n[Linked List Stack]\n";
    LinkedListStack llS1, llS2;
    cout << expr1 << " -> " << (isBalanced(expr1, llS1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << " -> " << (isBalanced(expr2, llS2) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}