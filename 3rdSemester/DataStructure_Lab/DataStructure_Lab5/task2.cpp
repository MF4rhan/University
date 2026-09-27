#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class stack
{
    string arr[MAX];
    string redos[MAX];
    int top;
    int redo_top;

    public:
    stack() : top(-1), redo_top(-1) {}

    bool is_empty()
    {
        return top == -1;
    }

    bool is_full()
    {
        return top == MAX-1;
    }

    void type(string word)
    {
        if (is_full())
        {
            cout << "\nThe stack is full.\n";
            return;
        }
        arr[++top] = word;
        redo_top = -1;

    }

    void undo()
    {
        if (is_empty())
        {
            cout << "\nThe stack is empty.\n";
            return;
        }
        redos[++redo_top] = arr[top--];
    }

    void redo()
    {
        if (redo_top == -1)
        {
            return;
        }
        arr[++top] = redos[redo_top--];
    }

    string peek()
    {
        if (is_empty())
        {
            cout << "\nThe stack is empty.\n";
        }
        return arr[top];
    }

    void display_all()
    {
        if (is_empty())
        {
            cout << "\nThe stack is empty.\n";
            return;
        }
        
        for (int i = 0; i < top+1; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    stack editor;
    editor.type("Hello");
    cout << editor.peek() << " ";
    editor.type("World");
    cout << editor.peek() << " ";

    cout << endl;
    editor.undo();
    cout << editor.peek() << " ";
    editor.redo();
    cout << editor.peek() << " ";

    cout << endl;
    editor.undo();
    cout << editor.peek() << " ";
    editor.type("There");
    cout << editor.peek() << " ";
    editor.redo();
    cout << editor.peek() << " ";
    return 0;
}