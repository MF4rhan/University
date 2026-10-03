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
            B = head;
        }
        else if (B == head)
        {
            A == head;
        }   
        
    }

    void inspect()
    {
        //guard->next->next.security > guard
        //then swap
        //something like this.
    }
};