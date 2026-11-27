#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class ArrayStack {
    string arr[MAX];
    int top;
public:
    ArrayStack() { top = -1; }
    bool is_empty() { return top == -1; }
    void push(string x) { arr[++top] = x; }
    string pop() { return arr[top--]; }
};

struct Node {
    string data;
    Node* next;
};

class LinkedListStack {
    Node* top;
public:
    LinkedListStack() { top = nullptr; }
    bool is_empty() { return top == nullptr; }

    void push(string x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        string val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
};

void runBrowserHistory(ArrayStack &backStack, ArrayStack &forwardStack) {
    string currentPage = "Home";

    backStack.push(currentPage);
    currentPage = "Profile";

    backStack.push(currentPage);
    currentPage = "Settings";

    cout << "Currently at: " << currentPage << endl;

    forwardStack.push(currentPage);      // save current page before going back
    currentPage = backStack.pop();
    cout << "After Back: " << currentPage << endl;

    backStack.push(currentPage);         // save current page before going forward
    currentPage = forwardStack.pop();
    cout << "After Forward: " << currentPage << endl;
}

void runBrowserHistory(LinkedListStack &backStack, LinkedListStack &forwardStack) {
    string currentPage = "Home";

    backStack.push(currentPage);
    currentPage = "Profile";

    backStack.push(currentPage);
    currentPage = "Settings";

    cout << "Currently at: " << currentPage << endl;

    forwardStack.push(currentPage);
    currentPage = backStack.pop();
    cout << "After Back: " << currentPage << endl;

    backStack.push(currentPage);
    currentPage = forwardStack.pop();
    cout << "After Forward: " << currentPage << endl;
}

int main() {
    cout << "[Array Stack]\n";
    ArrayStack aBack, aForward;
    runBrowserHistory(aBack, aForward);

    cout << "\n[Linked List Stack]\n";
    LinkedListStack llBack, llForward;
    runBrowserHistory(llBack, llForward);

    return 0;
}