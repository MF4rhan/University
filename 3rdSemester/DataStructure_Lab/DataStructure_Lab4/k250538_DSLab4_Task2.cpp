//25K-0538, Muhammad Farhan
/*
This entire linked list is a single template that I had created myself from scratch.
It doesn't use the tail pointer or anything (because in Theory, we aren't allowed to use a tail pointer).
In Lab, Miss told us that we can do no tail, tail or tail + counter to keep track of number of nodes as well,
as long as the implementation is correct and it works.
However, I want to keep my concepts consistent across both theory and lab.
Hence, I will only be using the Head Pointer here on all the tasks.
(Task 1 was done in the lab, hence it uses the tail, but I won't be doing that at home).
I hope the checker will understand. Thank you.
*/
#include <iostream>
using namespace std;

class node
{
    private:
    int value;
    node* next;

    public:
    node(int val = 0) : value(val), next (nullptr)
    {}

    void set_value(int val)
    {
        value = val;
    }

    void set_next(node* ptr)
    {
        next = ptr;
    }

    int get_value() const
    {
        return value;
    }

    node* get_next() const
    {
        return next;
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
        }
    }

    void insert_node_at_head(int val)
    {
        node* new_node = new node(val);
        new_node->next = head;
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

    void print_list()
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

    //Task Method
    void remove_duplicates()
    {
        if (head == nullptr)
        {
            cout << "The list is empty.\n";
            return;
        }
        else if (head->next == nullptr)
        {
            cout << "There are no duplicates in the list.\n";
            return;
        }

        node* holder = head;

        while (holder != nullptr)
        {
            node* checker = holder;
            while (checker->next != nullptr)
            {
                if (holder->value == checker->next->value)
                {
                    node* to_delete = checker->next;
                    checker->next = to_delete->next;
                    delete to_delete;
                }
                else
                {
                    checker = checker->next;
                }
            }
            holder = holder->next;
        }
        
        
    }
};

int main()
{
    linked_list list1;
    //adding elements to test
    list1.insert_node_at_head(10);
    list1.insert_node_at_head(10);
    list1.insert_node_at_head(10);
    list1.insert_node_at_head(26);
    list1.insert_node_at_head(19);
    list1.insert_node_at_head(69);
    list1.insert_node_at_head(19);
    list1.print_list();
    list1.remove_duplicates();
    list1.print_list();
    return 0;
}