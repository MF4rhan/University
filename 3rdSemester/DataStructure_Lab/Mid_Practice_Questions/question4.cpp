#include <iostream>
#include <string>
using namespace std;

#define LIMIT 20
//i am using a queue to manage the history

class node
{
    public:
    int id;
    string title;
    int times_opened;
    node* next;
    node* prev;

    node(int i = 0, string titl = "N/A") : id(i), title(titl), times_opened(0), next(nullptr), prev(nullptr) {}
    
};

class book
{
    node* head;
    node* current;
    int history_id[LIMIT]; //basically a queue
    int history_tail;

    public:
    book() : head(nullptr), history_tail(-1), current(nullptr)   {}

    bool is_full()
    {
        return history_tail == LIMIT - 1;
    }

    void insert_page_at_tail(int id, string title)
    {
        node* new_node = new node(id, title);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        node* checker = head;
        while (checker->next != nullptr)
        {
            checker = checker->next;
        }
        checker->next = new_node;
        new_node->prev = checker;
        
    }

    void navigate(string direction)
    {
        if (head == nullptr)
        {
            cout << "\nThe book is empty.\n";
            return;
        }
        
        if (current == nullptr)
        {
            current = head;
            current->times_opened++;
            history_id[++history_tail] = current->id;
        }
        
        if (direction == "forward")
        {
            if (current->next == nullptr)
            {
                cout << "\nEnd of the book. Cannot move Forward.\n";
                return;
            }
            current = current->next;
            current->times_opened++;
            for (int i = 0; i <= history_tail; i++)
            {
                if (history_id[i] == current->id)
                {
                   for (int j = i; j < history_tail; j++)
                    {
                        history_id[j] = history_id[j+1];
                    }
                    history_id[history_tail] = current->id;
                   return;
                }
            }
            if (is_full())
            {
                int tempid = history_id[0];
                for (int i = 0; i < LIMIT-1; i++)
                {
                    history_id[i] = history_id[i+1];
                }
                history_id[history_tail] = current->id;
                delete_node(tempid);
            }
            else
            {
                history_id[++history_tail] = current->id;
            }
            
        }
        else if (direction == "backward")
        {
            if (current->prev == nullptr)
            {
                cout << "\nEnd of the book. Cannot move Backward.\n";
                return;
            }
            current = current->prev;
            current->times_opened++;
            for (int i = 0; i <= history_tail; i++)
            {
                if (history_id[i] == current->id)
                {
                   for (int j = i; j < history_tail; j++)
                    {
                        history_id[j] = history_id[j+1];
                    }
                    history_id[history_tail] = current->id;
                   return;
                }
            }
            if (is_full())
            {
                int tempid = history_id[0];
                for (int i = 0; i < LIMIT-1; i++)
                {
                    history_id[i] = history_id[i+1];
                }
                history_id[history_tail] = current->id;
                delete_node(tempid);
            }
            else
            {
                history_id[++history_tail] = current->id;
            }

        }
        else
        {
            cout << "\nInvalid Command. Please Try Again.\n";
        }
    }

    void print_history()
    {
        cout << "\n\nHistory (Oldest to Recent): \n";
        for (int i = 0; i <= history_tail; i++) //the history tail here ITSELF is the index of the most recent page
        {
            cout << "Page ID: " << history_id[i] << endl;
        }  
    }
    void print_history_reverse()
    {
        cout << "\n\nHistory (Recent to Oldest): \n";
        for (int i = history_tail; i >= 0; i--)
        {
            cout << "Page ID: " << history_id[i] << endl;
        }  
    }

    void print_current_page()
    {
        if (current == nullptr)
        {
            cout << "\nYou haven't started reading yet.\n";
            return;
        }
        
        cout << "Details of Current Page: \n" << endl;
        cout << "Page ID: " << current->id << "\tPage Title: " << current->title << "\tTime Opened: " << current->times_opened << endl;

    }

    void delete_node(int id)
    {
        if (head == nullptr)
        {
            cout << "\nThe list is empty.\n";
            return;
        }
        if (head->id == id)
        {
            node* deleter = head;
            head = head->next;
            head->prev = nullptr;
            delete deleter;
            return;
        }

        node* checker = head;
        while (checker != nullptr && checker->id != id)
        {
            checker = checker->next;
        }
        if (checker ==  nullptr)
        {
            cout << "\nInvalid ID.\n";
            return;
        }
        if (checker->next == nullptr) //means if checker is the tail
        {
            node* prevNode = checker->prev;
            delete checker;
            prevNode->next = nullptr;
            return;
        }
        
        node* prevNode = checker->prev;
        node* nextNode = checker->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        
        delete checker;
    }
};

int main()
{
    book booker;
    booker.insert_page_at_tail(01, "Potato");
    booker.insert_page_at_tail(02, "Brotato");
    booker.insert_page_at_tail(03, "skyu");
    booker.insert_page_at_tail(04, "mirchi");
    booker.insert_page_at_tail(05, "comb");
    booker.insert_page_at_tail(06, "life");
    booker.insert_page_at_tail(07, "water");
    booker.insert_page_at_tail(10, "Jelly");
    booker.insert_page_at_tail(11, "Chicken");

    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("backward");
    booker.navigate("backward");
    booker.navigate("backward");
    booker.navigate("backward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("backward");
    booker.navigate("backward");
    booker.navigate("backward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");
    booker.navigate("forward");


    booker.print_history();
    booker.print_history_reverse();
    booker.print_current_page();

    return 0;
}