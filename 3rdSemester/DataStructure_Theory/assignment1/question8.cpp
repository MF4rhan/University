#include <iostream>
#include <string>
using namespace std;

class node
{
    public:
    char move;
    node* next;
    node(char mov): move(mov), next(nullptr)
    {}
};


class stack
{
  private:
  int position;
  node* top;
  int success;
  int successUndo;

  public:
  stack(): position(0), top(nullptr), success(0), successUndo(0)
  {}

  bool is_empty()
  {
    return top == nullptr;
  }

   void pop()
  {
    if (is_empty())
    {
        cout << "\nThe Stack is Empty.\n";
        return;
    }
    node* temp = top;
    top = top->next;
    delete temp;
  }

  void move(char val)
  {
    if (val == 'R')
    {
        position++;
        success++;
    }
    else if (val == 'J')
    {
        position += 2;
        success++;
    }
    else if (val == 'L')
    {
        if (position <= 0)
        {
            cout << "\nThe position is 0. Cannot move back.\n";
            return;
        }
        position--;
        success++;
    }
    else if (val == 'B')
    {
        if (top == nullptr)
        {
            cout << "\nThe Stack is Empty.\n";
            return;
        }
        
        if (top->move == 'R')
        {
            position--;
        }
        else if (top->move == 'L')
        {
            position++;
        }
        else if (top->move == 'J')
        {
            position -= 2;
        }
        pop();
        successUndo++;
        return;
    }
    
    node* new_node = new node(val);
    new_node->next = top;
    top = new_node;
  }

  char peek()
  {
    if (is_empty())
    {
        cout << "\nThe Stack is Empty.\n";
        return -1;
    }
    return top->move;
  }

  void print()
  {
    if (top == nullptr)
    {
        cout << "\nThe Stack is Empty.\n";
        return;
    }
    
    cout << "\nFinal Position: " << position
         << "\nTotal Number of Successful Movements: " << success 
         << "\nTotal Number of Successful Undos: " << successUndo << "\n";

    node* reader = top;
    cout << "Stack: ";
    while (reader != nullptr)
    {
        cout << reader->move << ", ";
        reader = reader->next;
    }

  }
};


int main()
{
    stack game;
    int n;
    char command;

    cout << "Enter the number of commands: ";
    cin >> n;

    cout << "Enter the commands (R, L, J, B):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        game.move(command);
    }

    game.print();
    cout << endl;

    return 0;
}