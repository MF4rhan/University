#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class ArrayStack {
    char arr[MAX];
    int top;
public:
    ArrayStack() { top = -1; }
    bool is_empty() { return top == -1; }
    void push(char x) { arr[++top] = x; }
    char pop() { return arr[top--]; }
};

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

string reverseString(string str, ArrayStack &s) {
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string result = "";
    while (!s.is_empty()) {
        result += s.pop();
    }

    return result;
}

string reverseString(string str, LinkedListStack &s) {
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string result = "";
    while (!s.is_empty()) {
        result += s.pop();
    }

    return result;
}

int main() {
    string str = "Hello World";

    ArrayStack arrS;
    cout << "[Array Stack] Reversed: " << reverseString(str, arrS) << endl;

    LinkedListStack llS;
    cout << "[Linked List Stack] Reversed: " << reverseString(str, llS) << endl;

    return 0;
}