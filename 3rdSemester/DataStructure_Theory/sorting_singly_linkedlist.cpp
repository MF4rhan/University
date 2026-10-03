#include <iostream>
using namespace std;

class node
{
    public:
    int val;
    node* next;

    node() : next(nullptr) {}

};

class linkedlist
{
    node* head;

    public:
    linkedlist() : head(nullptr)    {}

    node* get_prev(node* target)
    {
        if (head == target)
            return nullptr;          // head has no previous node
        
        node* p = head;
        while (p != nullptr && p->next != target)
            p = p->next;  
        
        return p;
    }

    void swap_nodes(node* a, node* b)
    {
        if (a == nullptr || b == nullptr || a == b)
            return;

        node* prevA = get_prev(a);
        node* prevB = get_prev(b);

        // Step 1: swap the incoming pointers
        if (prevA == nullptr)
            head = b;
        else
            prevA->next = b;

        if (prevB == nullptr)
            head = a;
        else
            prevB->next = a;

        // Step 2: swap the outgoing pointers
        node* temp = a->next;
        a->next = b->next;
        b->next = temp;
    }

    node* get_tail()
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        node* checker = head;
        while (checker->next != nullptr)
        {
            checker = checker->next;
        }
        return checker;
    }

    int get_count()
    {
        int counter = 0;
        node* checker = head;
        while (checker != nullptr)
        {
            checker = checker->next;
            ++counter;
        }
        return counter;
    }

    void bubble_sort()
    {
        if ( head == nullptr || head->next == nullptr)
        {
            return;
        }
        int size = get_count();

        node* checker = nullptr; 
        for (int i = 0; i < size; i++)
        {
            checker = head;
            for (int j = 0; j < size-1-i; j++)
            {
                if (checker->val > checker->next->val)
                {
                    swap_nodes(checker, checker->next);
                }
                else
                {
                    checker = checker->next; 
                    //here, the moving further is inside an else block for a reason.
                    //because unlike a normal array, even after swapping, jth position, stays the jth position. the slot itself doesn't move.
                    //however with nodes, when we swap nodes, we changed the physical slot forward, and after swapping,
                    //we are already on the next node (checker is A, A -> B), after swapping: (B -> A, checker is still A)
                    //we already moved forward by swapping nodes, hence we avoid advancing further by
                    //putting the manual advancement inside a else block.
                }
            }
            
        }
        
    }

    void selection_sort()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        
        int size = get_count();
        node* checker = head;
        for (int i = 0; i < size-1; i++)
        {
            
            node* min = checker;
            node* inner_checker = checker->next;
            for (int j = i+1; j < size; j++)
            {
                if (inner_checker->val < min->val)
                {
                    min = inner_checker;
                }
                inner_checker = inner_checker->next;
            }
            if (min != checker)
            {
                swap_nodes(checker, min);
            }
            
            checker = min->next;
            //here we are using min->next, because:
            //whether we swapped or not swapped: min is the gonna be the node to be placed at at the ith position.
            //if we used checker->next, then we would need an if else condition.
            //if for not swapped (in that case, checker stays at ith position)
            //else for swapped (in that case, checker is where min previously used to be).
            //so using min->next is simpler since it will be the ith position regardless.
        }
        
    }


};


