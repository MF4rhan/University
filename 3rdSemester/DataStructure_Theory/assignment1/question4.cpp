#include <iostream>
#include <string>
using namespace std;

class rider
{
    public:
    int id;
    string name;
    int orders;
    rider* next;

    rider(int ide = 0, string namae = "N/A", int ordero = 0) : id(ide), name(namae), orders(ordero), next(nullptr)
    {}

};

class kfc
{
    private:
    rider* head;

    public:
    kfc() : head(nullptr)
    {}

    rider* get_tail() //helper method to get tail instead of constantly repeating the same loop
    {
        if (head == nullptr)
        {
            cout << "\nThe list is empty.\n";
            return nullptr;
        }

        rider* checker = head;
        while (checker->next != head)
        {
            checker = checker->next;
        }
        return checker; 
    }

    rider* get_head()
    {
        if (head == nullptr)
        {
            cout << "\nThe list is empty.\n";
            return nullptr;
        }
        return head;
    }

    void insert_at_head(int id, string name, int order)
    {
        if (head == nullptr)
        {
            rider* new_rider = new rider(id, name, order);
            head = new_rider;
            head->next = head;
            cout << "\nRider Assigned to head.\n";
        }
        else
        {
            rider* new_rider = new rider(id, name, order);
            rider* tail = get_tail();
            rider* temp = head;
            head = new_rider;
            new_rider->next = temp;
            
            tail->next = head;
        }
    }

    void insert_at_tail(int id, string name, int order)
    {
        if (head == nullptr)
        {
            rider* new_rider = new rider(id, name, order);
            head = new_rider;
            head->next = head;
            cout << "\nRider assigned to the tail (head).\n";
        }
        else
        {
            rider* new_rider = new rider(id, name, order);
            rider* tail = get_tail();
            tail->next = new_rider;
            new_rider->next = head;
        } 
    }

    void insert_at_index(int id, string name, int order, int index)
    {
        if (index == 0)
        {
            insert_at_head(id, name, order);
            return;
        }

        rider* checker = head;
        int counter = 0;
        while (counter < index - 1)
        {
            checker = checker->next;
            counter++;
            if (checker == head)
            {
                cout << "\nInvalid Position.\n";
                return;
            }
        }
        rider* new_rider = new rider(id, name, order);
        new_rider->next = checker->next;
        checker->next = new_rider; 
    }

    void delete_from_head()
    {
        
    }

};

int main()
{

}