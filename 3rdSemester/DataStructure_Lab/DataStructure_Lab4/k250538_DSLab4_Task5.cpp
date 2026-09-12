#include <iostream>
#include <string>
using namespace std;

class node
{
    private:
    int value;
    node* next;
    node* previous;

    public:
    node(int val = 0) : value(val), next (nullptr), previous(nullptr)
    {}

    void set_value(int val)
    {
        value = val;
    }

    void set_next(node* ptr)
    {
        next = ptr;
    }

    void set_previous(node* ptr)
    {
        previous = ptr;
    }

    int get_value() const
    {
        return value;
    }

    node* get_next() const
    {
        return next;
    }

    node* get_previous() const
    {
        return previous;
    }

    friend class linked_list;
};

class linked_list
{
    private:
    node* head;
    node* current; //for the task

    public:
    linked_list() : head(nullptr), current(nullptr)
    {}
    ~linked_list()
    {
        if (head == nullptr)
        {
            return;
        }
        node* to_delete = head->next;
        while (to_delete != head)
        {
            node* next_node = to_delete->next;
            delete to_delete;
            to_delete = next_node;
        }
        delete head;
        head = nullptr;
    }

    void insert_node_at_tail(int val)
    {
        if (head == nullptr)
        {
            head = new node(val);
            head->next = head;
            head->previous = head;
        }
        else
        {
            node* temp = head; 
            while (temp->next != head)
            {
                temp = temp->next;
            } 
            temp->next = new node(val);
            temp->next->previous = temp;
            temp->next->next = head;
            head->previous = temp->next;
        }
    }

    void insert_node_at_head(int val)
    {
        node* new_node = new node(val);
        if (head == nullptr)
        {
            head = new_node;
            head->next = head;
            head->previous = head;
            return;
        }
        node* tail = get_tail();
        new_node->next = head;
        head->previous = new_node;
        head = new_node;
        tail->next = head;
        head->previous = tail;
    }

    void insert_node_at_index(int val, int index)
    {
        if (index == 0)
        {
            insert_node_at_head(val);
            return;
        }
        
        int counter = 0;
        node* temp = head;
        
        while (counter < index - 1) 
        {
            temp = temp->next;
            counter++;
            if (temp == head)
            {
                cout << "Invalid Index." << endl;
                return;
            }
        }
        
        if (temp->next == head)
        {
            insert_node_at_tail(val);
            return;
        }
        
        node* new_node = new node(val);
        new_node->next = temp->next;
        temp->next->previous = new_node;
        new_node->previous = temp;
        temp->next = new_node;
    }

    void delete_at_tail()
    {
        if (head == nullptr)
        {
            return;
        }
        else if (head->next == head) 
        {
            delete head;
            head = nullptr;
            return;
        }
        
        node* temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
        head->previous = temp;
    }

    void delete_at_head()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        node* temp = head->next;
        node* tail = get_tail();
        delete head;
        head = temp;
        head->previous = tail;
        tail->next = head;
    }

    void delete_at_value(int val)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->value == val)
        {
            delete_at_head();
            return;
        }

        node* temp = head;
        while (temp->next != head && temp->next->value != val )
        {
            temp = temp->next;
        }
        if (temp->next == head)
        {
            cout << "Value does not exist in the list." << endl;
            return;
        }

        node* to_delete = temp->next;
        to_delete->next->previous = temp;
        temp->next = to_delete->next;
        delete to_delete;
    }

    void delete_at_index(int index)
    {
        if (index == 0)
        {
            delete_at_head();
            return;
        }

        int counter = 0;
        node* temp = head;
        node* tail = get_tail();
        while (counter < index - 1) 
        {
            counter++;
            temp = temp->next;
            if (temp == head)
            {
                cout << "Invalid Index." << endl;
                return;
            }
        }
 
        node* to_delete = temp->next;
        if (to_delete == head)
        {
            cout << "Invalid index.\n";
            return;
        }
        
        to_delete->next->previous = temp;
        temp->next = to_delete->next;
        delete to_delete;
    }

    node* search_node_by_value(int val)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->value == val)
        {
            return head;
        }

        node* to_find = head;
        while (to_find->value != val)
        {
            to_find = to_find->next;
            if (to_find == head)
            {
                cout << "The value does not exist in any node." << endl;
                return nullptr;
            }
        }

        return to_find;
    }

    node* search_node_by_index(int index)
    {
        if (index == 0)
        {
            return head;
        }

        int counter = 0;
        node* to_find = head;

        while (counter < index)
        {
            to_find = to_find->next;
            counter++;
            if (to_find == head)
            {
                cout << "Invalid index." << endl;
                return nullptr;
            }
        }

        return to_find;
    }

    void update_node_by_value(int val)
    {
        node* to_update = search_node_by_value(val);
        if (to_update == nullptr)
        {
            return;
        }
        cout << "Enter the new value: ";
        int new_val;
        cin >> new_val;
        to_update->value = new_val;

        cout << "Node value updated." << endl;
    }

    void update_node_by_index(int val, int index)
    {
        node* to_update = search_node_by_index(index);
        if (to_update == nullptr)
        {
            return;
        }

        to_update->value = val;
        cout << "Node value Updated." << endl;
    }

    void print_list()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        cout << head->value << " -> ";
        node* to_print = head->next;
        while (to_print != head)
        {
            cout << to_print->value << " -> ";
            to_print = to_print->next;
        }
        cout << "head" << endl;
    }

    node* get_tail()
    {
        if (head == nullptr)
        {
            cout << "The list is empty.\n";
            return nullptr;
        }
        
        node* checker = head;
        while (checker->next != head)
        {
            checker = checker->next;
        }
        return checker;
    }

    node* get_head()
    {
        if (head == nullptr)
        {
            cout << "The list is empty.\n";
            return nullptr;
        }
        return head;
    }

    void move(int steps, string directoin)
    {
        if (head == nullptr)
        {
            cout << "The list is empty.\n";
            return;
        }
        if (current == nullptr)
        {
            current = head;
        }

        for (int i = 0; i < steps; i++)
        {
            if (directoin == "forward" || directoin == "Forward" || directoin == "FORWARD")
            {
                current = current->next;
            }
            else if (directoin == "backward" || directoin == "Backward" || directoin == "BACKWARD")
            {
                current = current->previous;
            }
            else
            {
                cout << "Invalid Direction.\n";
                return;
            }
        }
        
        cout << "Current Node: " << current->value << endl;
    }
};

int main()
{
    linked_list list1;
 
   cout << "Enter the number of elements to add to the list: ";
    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cout << "\nEnter value of Node " << i << ": " << endl;
        int value;
        cin >> value;
        int choice, index;
        do
        {
            cout << "Enter one of the following operations:\n";
            cout << "1. Insert Node at Head.\n2. Insert Node at Tail.\n3. Insert node at any index.\nEnter your choice(1,2 or 3): ";
            cin >> choice;
            
            if (choice < 1 || choice > 3)
            {
                cout << "Invalid Choice.\n";
            }
            
        } while (choice < 1 || choice > 3);
        
        if (choice == 1)
        {
            list1.insert_node_at_head(value);
        }
        else if (choice == 2)
        {
            list1.insert_node_at_tail(value);
        }
        else if (choice == 3)
        {
            cout << "\nEnter the Index: ";
            cin >> index;
            list1.insert_node_at_index(value, index);
        }
        
    }

   cout << "List after Insertions: " << endl;
   list1.print_list();

  int steps;
    string direction;
    cout << "Enter number of steps: ";
    cin >> steps;
    cout << "Enter direction (forward/backward): ";
    cin >> direction;
    list1.move(steps, direction);

    return 0;
}