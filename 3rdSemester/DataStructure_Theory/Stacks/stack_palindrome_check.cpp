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

bool isPalindrome(string str, ArrayStack &s) {
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != s.pop()) {
            return false;
        }
    }
    return true;
}

bool isPalindrome(string str, LinkedListStack &s) {
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != s.pop()) {
            return false;
        }
    }
    return true;
}

int main() {
    string str1 = "madam";
    string str2 = "hello";

    cout << "[Array Stack]\n";
    ArrayStack arrS1, arrS2;
    cout << str1 << " -> " << (isPalindrome(str1, arrS1) ? "Palindrome" : "Not Palindrome") << endl;
    cout << str2 << " -> " << (isPalindrome(str2, arrS2) ? "Palindrome" : "Not Palindrome") << endl;

    cout << "\n[Linked List Stack]\n";
    LinkedListStack llS1, llS2;
    cout << str1 << " -> " << (isPalindrome(str1, llS1) ? "Palindrome" : "Not Palindrome") << endl;
    cout << str2 << " -> " << (isPalindrome(str2, llS2) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}