#include <iostream>
using namespace std;

node* get_prev(node* target)
{
    if (head == nullptr || target == nullptr)
        return nullptr;

    node* checker = head;
    do
    {
        if (checker->next == target)
            return checker;
        checker = checker->next;
    } while (checker != nullptr && checker != head);

    return nullptr;
}

void swap_nodes_circular(node* A, node* B) //for circular
{

    node* prevA = get_prev(A);
    node* prevB = get_prev(B);

    prevA->next = B;
    prevB->next = A;

    node* temp;
    temp = A->next;
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

void swap_nodes_non_circular(node* A, node* B) //for non circular
{

    node* prevA = get_prev(A);
    node* prevB = get_prev(B);

    if (prevA == nullptr)
    {
        head = B;
    }
    else
    {
        prevA->next = B;  
    }
    
    if (prevB == nullptr)
    {
        head = A;
    }
    else
    {
        prevB->next = A;
    }
   

    node* temp;
    temp = A->next;
    A->next = B->next;
    B->next = temp;
}

void swap_nodes(node* A, node* B) //combined for both
{
    if (A == nullptr || B == nullptr || A == B)
        return;

    node* old_head = head;                 // remember the head BEFORE changing anything

    node* prevA = get_prev(A);
    node* prevB = get_prev(B);

    if (prevA != nullptr)                  // plain list, A is head: nothing to redirect
        prevA->next = B;
    if (prevB != nullptr)
        prevB->next = A;

    node* temp = A->next;
    A->next = B->next;
    B->next = temp;

    if (old_head == A)                     // fix head once, at the end, for both kinds
        head = B;
    else if (old_head == B)
        head = A;
}