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

    ~kfc()
    {
        if (head == nullptr)
        {
            return;
        }
        rider* to_delete = head->next;
        while (to_delete != head)
        {
            rider* holder = to_delete->next;
            delete to_delete;
            to_delete = holder;
        }
        delete head;
        head = nullptr;
    }

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
        if (head == nullptr)
        {
            cout << "\nThe List is empty.\n";
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        
        rider* tail = get_tail();
        rider* rida = head->next;
        delete head;
        head = rida;
        tail->next = head;
    }

    void delete_from_tail()
    {
        if (head == nullptr)
        {
            cout << "\nThe List is empty.\n";
            return;
        }

        rider* rida = head;
        if (rida->next == head)
        {
            delete_from_head();
            return;
        }
        
        while (rida->next->next != head)
        {
            rida = rida->next;
        }
        delete rida->next;
        rida->next = head;  
    }

    void delete_from_position(int index)
    {
        if (head == nullptr)
        {
            cout << "\nThe List is empty.\n";
            return;
        }
        if (index == 0)
        {
            delete_from_head();
            return;
        }
        
        rider* rida = head;
        int counter = 0;
        while (counter < index - 1)
        {
            rida = rida->next;
            counter++;
            if (rida == head)
            {
                cout << "\nInvalid Index Bro.\n";
                return;
            }
        }
        
        if (rida->next == head)
        {
            cout << "\nInvalid Index Bro.\n";
            return;
        }
        rider* to_delete = rida->next;
        rida->next = to_delete->next;
        delete to_delete;
    }

    rider* search_rider_by_id(int sid)
    {
        if (head == nullptr)
        {
            cout << "\nThe List is empty.\n";
            return nullptr;
        }

        rider* checker = head;
        do
        {
            if (checker->id == sid)
            {
                return checker;
            }
            checker = checker->next;
        } while (checker != head);

        return nullptr;
    }

    void update_rider_by_id(int sid)
    {
        rider* rida = search_rider_by_id(sid);

        if (rida == nullptr)
        {
            cout << "\nInput ID does not belong to any rider.\n";
            return;
        }

        cout << "\nEnter new Rider name: ";
        string namae;
        getline(cin, namae);
        rida->name = namae;

        cout << "\nEnter new Rider Order numbers: ";
        int new_orders;
        cin >> new_orders;
        rida->orders = new_orders;

        cout << "\nThe Rider Information has been updated!\n";
    }

    int count_riders()
    {
        if (head == nullptr)
        {
            return 0;
        }

        int counter = 0;
        rider* checker = head;

        do
        {
            checker = checker->next;
            counter++;
        } while (checker != head);

        return counter;
    }

    void display_all_riders()
    {
        if (head == nullptr)
        {
            cout << "\nThere are no riders.\n";
        }

        rider* checker = head;
        int counter = 1;
        do
        {
            cout << "\nRider #" << counter++ << ": ID: " << checker->id << "  Name: " << checker->name << "   Orders: " << checker->orders;
            checker = checker->next;
        } while (checker != head);
    }

    void traverse_from_rider(int sid)
    {
        rider* selected = search_rider_by_id(sid);
        if (selected == nullptr)
        {
            cout << "\nInput ID does not belong to any rider.\n";
            return;
        }

        rider* checker = selected;
        int counter = 1;
        do
        {
            cout << "\nRider #" << counter++ << ": ID: " << checker->id << "  Name: " << checker->name << "   Orders: " << checker->orders;
            checker = checker->next;
        } while (checker != selected);
        
    }
};

int main()
{
    kfc system;

    // Hardcoded test data
    system.insert_at_head(1, "Ali", 10);
    system.insert_at_tail(2, "Bilal", 5);
    system.insert_at_index(3, "Raza", 15, 1);
    
    system.display_all_riders();
    cout << "\n";

    system.delete_from_head();
    system.display_all_riders();
    cout << "\n";

    system.traverse_from_rider(2);
    cout << "\n";

    return 0;
}