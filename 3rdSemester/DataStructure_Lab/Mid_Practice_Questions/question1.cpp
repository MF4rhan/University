#include <iostream>
using namespace std;
//this is basically just a circular queue
#define MAX 10
class customers
{
    public:
    int id;
    int tickets;

    customers(int ide = 0, int tic = 0) : id(ide), tickets(tic) {}

};


class ticket_counter
{
    customers array[MAX];
    int front, rear;
    int total_tickets;
    int count;
    
    public:
    ticket_counter(int total = 100) : front(0), rear(-1), total_tickets(total), count(0)    {}
    bool is_empty()
    {
        return count == 0;
    }

    bool is_full()
    {
        return count == MAX;
    }

    void add_tickets(int tix)
    {
        total_tickets += tix;
    }

    void queue(int id, int ticket)
    {
        if (is_full())
        {
            cout << "\nThe Ticket line is full.\n";
            return;
        }
        rear = (rear + 1) % MAX;
        array[rear].id = id;
        array[rear].tickets = ticket;
        count++;
    }

    void dequeue()
    {
        if (is_empty())
        {
            cout << "\nThe ticket line is empty.\n";
            return;
        }
        if (array[front].tickets > total_tickets)
        {
            cout << "\nThe Tickets have Ran out. Customer Leaves.\n";
        }
        else
        {
            cout << "\nSale successful. Customer bought " << array[front].tickets << " tickets!.\n";
            total_tickets -= array[front].tickets;
        }
        count--;
        front = (front + 1) % MAX;
    }

    customers get_front_customer()
    {
        if (is_empty())
        {
            cout << "\nThere are no customers.\n";
            return customers(-1, -1);
        }
        return array[front]; 
    }

    customers get_rear_customer()
    {
        if (is_empty())
        {
            cout << "\nThere are no customers.\n";
            return customers(-1, -1);
        }
        return array[rear]; 
    }

    int get_waiting_count()
    {
        return count;
    }

};
