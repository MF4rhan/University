#include <iostream>
using namespace std;

#define MAX 100

class stack
{
    int arr[MAX];
    int top;

    public:
    stack() : top(-1) {}

    bool is_empty()
    {
        return top == -1;
    }

    bool is_full()
    {
        return top == MAX-1;
    }

    void push(int num)
    {
        if (is_full())
        {
            cout << "\nThe stack is full.\n";
            return;
        }
        arr[++top] = num;
    }

    void undo()
    {
        if (is_empty())
        {
            cout << "\nThe stack is empty.\n";
            return;
        }
        top--;
    }

    int peek()
    {
        if (is_empty())
        {
            cout << "\nThe stack is empty.\n";
            return -1;
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
    stack stacky;
    // adding operations to stack
    stacky.push(12);
    cout << stacky.peek() << endl;
    stacky.push(25);
    cout << stacky.peek() << endl;
    stacky.push(17);
    cout << stacky.peek() << endl;
    stacky.push(31);
    cout << stacky.peek() << endl;
    stacky.push(44);
    cout << stacky.peek() << endl;
    stacky.push(19);
    cout << stacky.peek() << endl << endl;

    //now undo-ing
    stacky.undo();
    cout << stacky.peek() << endl;
    stacky.undo();
    cout << stacky.peek() << endl;
    stacky.undo();
    cout << stacky.peek() << endl << endl;

    //perming new operation 52
    stacky.push(52);
    cout << stacky.peek() << endl << endl;

    //undo-ing twice more
    stacky.undo();
    cout << stacky.peek() << endl;
    stacky.undo();
    cout << stacky.peek() << endl << endl;

    //display all
    stacky.display_all();
    cout << endl;
    return 0;
}