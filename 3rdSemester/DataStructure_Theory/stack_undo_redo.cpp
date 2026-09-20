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

void runUndoRedo(ArrayStack &undoStack, ArrayStack &redoStack) {
    undoStack.push("Type A");
    undoStack.push("Type B");
    undoStack.push("Type C");

    string undone = undoStack.pop();
    redoStack.push(undone);
    cout << "Undo -> " << undone << endl;

    undone = undoStack.pop();
    redoStack.push(undone);
    cout << "Undo -> " << undone << endl;

    string redone = redoStack.pop();
    undoStack.push(redone);
    cout << "Redo -> " << redone << endl;
}

void runUndoRedo(LinkedListStack &undoStack, LinkedListStack &redoStack) {
    undoStack.push("Type A");
    undoStack.push("Type B");
    undoStack.push("Type C");

    string undone = undoStack.pop();
    redoStack.push(undone);
    cout << "Undo -> " << undone << endl;

    undone = undoStack.pop();
    redoStack.push(undone);
    cout << "Undo -> " << undone << endl;

    string redone = redoStack.pop();
    undoStack.push(redone);
    cout << "Redo -> " << redone << endl;
}

int main() {
    cout << "[Array Stack]\n";
    ArrayStack aUndo, aRedo;
    runUndoRedo(aUndo, aRedo);

    cout << "\n[Linked List Stack]\n";
    LinkedListStack llUndo, llRedo;
    runUndoRedo(llUndo, llRedo);

    return 0;
}