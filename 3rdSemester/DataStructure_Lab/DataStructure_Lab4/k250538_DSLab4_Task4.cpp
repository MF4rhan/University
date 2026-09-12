#include <iostream>
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

    public:
    linked_list() : head(nullptr)
    {}
    ~linked_list()
    {
        node* to_delete = head;
        while (to_delete != nullptr)
        {
            node* next_node = to_delete->next;
            delete to_delete;
            to_delete = next_node;
        }
        head = nullptr;
    }

    void insert_node_at_tail(int val)
    {
        if (head == nullptr)
        {
            head = new node(val);
        }
        else
        {
            node* temp = head; 
            while (temp->next != nullptr)
            {
                temp = temp->next;
            } 
            temp->next = new node(val);
            temp->next->previous = temp;
        }
    }

    void insert_node_at_head(int val)
    {
        node* new_node = new node(val);
        new_node->next = head;
        if (head != nullptr)
        {
            head->previous = new_node;
        }
        head = new_node;
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
        while (temp != nullptr && counter < index - 1) 
        {
            temp = temp->next;
            counter++;
        }
        
        if (temp == nullptr)
        {
            cout << "Invalid Index." << endl;
            return;
        }

        node* new_node = new node(val);
        new_node->next = temp->next;
        if (new_node->next != nullptr)
        {
            new_node->next->previous = new_node;
        }
        new_node->previous = temp;
        temp->next = new_node;
    }

    void delete_at_tail()
    {
        if (head == nullptr)
        {
            return;
        }
        else if (head->next == nullptr) 
        {
            delete head;
            head = nullptr;
            return;
        }
        
        node* temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void delete_at_head()
    {
        if (head == nullptr)
        {
            return;
        }
        
        node* temp = head->next;
        if (temp != nullptr)
        {
            temp->previous = nullptr;
        }
        delete head;
        head = temp;
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
        while (temp->next != nullptr && temp->next->value != val )
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            cout << "Value does not exist in the list." << endl;
            return;
        }

        node* to_delete = temp->next;
        if (to_delete->next != nullptr)
        {
            to_delete->next->previous = temp;
        }
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
        while (temp != nullptr && counter < index - 1) 
        {
            counter++;
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) 
        {
            cout << "Invalid Index." << endl;
            return;
        }
        
        node* to_delete = temp->next;
        if (to_delete->next != nullptr)
        {
            to_delete->next->previous = temp;
        }
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
        while (to_find != nullptr && to_find->value != val)
        {
            to_find = to_find->next;
        }
        if (to_find == nullptr)
        {
            cout << "The value does not exist in any node." << endl;
            return nullptr;
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

        while (to_find != nullptr && counter < index)
        {
            to_find = to_find->next;
            counter++;
        }
        if (to_find == nullptr)
        {
            cout << "Invalid index." << endl;
            return nullptr;
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

    void print_list_forward()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        node* to_print = head;
        while (to_print != nullptr)
        {
            cout << to_print->value << " -> ";
            to_print = to_print->next;
        }
        cout << "nullptr" << endl;
    }

    void print_list_backward()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        node* to_print = head;
        while (to_print->next != nullptr)
        {
            to_print = to_print->next;
        }
        while (to_print != head)
        {
            cout << to_print->value << " -> ";
            to_print = to_print->previous;
        }
        cout << head->value << " (head)" << endl;
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
   list1.print_list_forward();
   list1.print_list_backward();

    cout << "\nEnter the index where you want to delete a node: ";
    int index;
    cin >> index;
    list1.delete_at_index(index);

   cout << "List after Deleting: " << endl;
   cout << "Forward: ";
   list1.print_list_forward();
   cout << "Backward: ";
   list1.print_list_backward();

    return 0;
}