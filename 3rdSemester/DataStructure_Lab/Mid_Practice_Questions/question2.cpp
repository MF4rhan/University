#include <iostream>
using namespace std;

class node
{
    public:
    int id;
    int security;
    node* next;

    node(int i = 0, int sec = 0) : id(i), security(sec), next(nullptr)  {}
};

class guard_list
{
    node* head;

    public:
    guard_list() : head(nullptr)    {}

    void add_guard_to_tail(int id, int sec)
    {
        node* new_node = new node(id, sec);
        if (head == nullptr)
        {
            head = new_node;
            head->next = head;
            return;
        }
        node* checker = head;
        while (checker->next != head)
        {
            checker = checker->next;
        }
        checker->next = new_node;
        new_node->next = head;
    }

    node* get_prev(node* target)
    {
        if (head == nullptr || target == nullptr)
        {
            return nullptr;
        }

        node* checker = head;
        do
        {
            if (checker->next == target)
            {
                return checker;
            }
            checker = checker->next;
        } while (checker != head);
        
        return nullptr; //nullptr if the target isn't in the list
    }

    void swap_nodes(node* A, node* B)
    {
        if (A == nullptr || B == nullptr || A == B)
        {
            return;
        }

        node* prevA = get_prev(A);
        node* prevB = get_prev(B);

        prevA->next = B;
        prevB->next = A;

        node* temp = A->next;
        A->next = B->next;
        B->next = temp;

        if (A == head)
        {
            head = B;
        }
        else if (B == head)
        {
            head = A;
        }   
        
    }

    int get_size()
    {
        if (head == nullptr)
        {
            return 0;
        }
        int count = 0;
        node* checker = head;
        do
        {
            count++;
            checker = checker->next;
        } while (checker != head);
        return count;
    }

    void inspect()
    {
        if (head == nullptr)
        {
            cout << "\nThe list is empty.\n";
            return;
        }
        if (head->next == head || head->next->next == head)
        {
            return;
        }
        int size = get_size();
        int swap_count = 0;
        node* checker = head;
        while (swap_count < size)
        {
            node* next_guard = checker->next;
            if (checker->next != head && checker->next->next != head && checker->next->next->security > checker->security)
            {
                swap_nodes(checker, checker->next->next);
                swap_count = 0;
            }
            else
            {
                swap_count++;
            }
            checker = next_guard;
        }
    }

    void print()
    {
        if (head == nullptr)
        {
            cout << "\nThe list is empty.\n";
            return;
        }
        node* checker = head;
        int i = 1;
        do
        {
            cout << "Guard #" << i << ":\tID: " << checker->id << "\tSecurity: " << checker->security << endl;
            checker = checker->next;
            i++;
        } while (checker != head);
        
    }
};


int main()
{
    guard_list museum;
    museum.add_guard_to_tail(01, 3);
    museum.add_guard_to_tail(02, 2);
    museum.add_guard_to_tail(03, 5);
    museum.add_guard_to_tail(04, 1);
    museum.add_guard_to_tail(05, 3);
    museum.add_guard_to_tail(06, 3);
    museum.add_guard_to_tail(07, 2);
    museum.add_guard_to_tail(10, 1);
    museum.add_guard_to_tail(11, 3);
    museum.add_guard_to_tail(12, 1);

    museum.print();
    cout << endl;

    museum.inspect();
    cout << endl;
    museum.print();

    return 0;
}