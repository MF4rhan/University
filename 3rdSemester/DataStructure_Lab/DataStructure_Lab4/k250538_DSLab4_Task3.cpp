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
    void even_odd()
    {
        if (head == nullptr)
        {
            cout << "The list is empty.\n";
            return;
        }
        else if (head->next == nullptr)
        {
            cout << "Cannot modify with only one node.\n";
            return;
        }

        node* checker = head;
        node* even_head = nullptr;
        node* even_tail = nullptr;
        node* odd_head = nullptr;
        node* odd_tail = nullptr;
        while (checker != nullptr)
        {
            if ((checker->value % 2) == 0)
            {
                if(even_head == nullptr)
                {
                    even_head = checker;
                    even_tail = even_head;
                }
                else
                {
                    even_tail->next = checker;
                    even_tail = even_tail->next;
                }
            }
            else
            {
                if(odd_head == nullptr)
                {
                    odd_head = checker;
                    odd_tail = odd_head;
                }
                else
                {
                    odd_tail->next = checker;
                    odd_tail = odd_tail->next;
                }
            }
            checker = checker->next;
        }

        if (even_head == nullptr)
        {
            head = odd_head;
        }
        else 
        {
            head = even_head;
            even_tail->next = odd_head;
        }

        if (odd_head != nullptr)
        {
            odd_tail->next = nullptr;
        }
        else if (even_head != nullptr)
        {
            even_tail->next = nullptr;
        }
        
    }

    node* get_tail()
    {
        if (head == nullptr)
        {
            cout << "The list is empty.\n";
            return nullptr;
        }
        
        node* checker = head;
        while (checker->next != nullptr)
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
};

int main()
{
    linked_list list1;
    //adding elements to test
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
    
    list1.print_list();
    node* head_check = list1.get_head();
    node* tail_check = list1.get_tail();
    if (head_check != nullptr && tail_check != nullptr)
    {
        cout << "Head: " << head_check->get_value();
        cout << "\nTail: " << tail_check->get_value() << endl;
    }

    list1.even_odd();

    list1.print_list();
    head_check = list1.get_head();
    tail_check = list1.get_tail();
    if (head_check != nullptr && tail_check != nullptr)
    {
        cout << "Head: " << head_check->get_value();
        cout << "\nTail: " << tail_check->get_value();
    }
    return 0;
}