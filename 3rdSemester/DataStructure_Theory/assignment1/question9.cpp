#include <iostream>
#include <string>
using namespace std;

class queue
{
    public:
    int arr[100];
    int front;
    int rear;
    int count;

    queue(): front(-1), rear(-1), count(0)
    {}

    bool is_empty()
    {
        return count == 0;
    }

    void enqueue(int val)
    {
        if (rear == 99)
        {
            cout << "\nQueue is Full.\n";
            return;
        }
        
        arr[++rear] = val;
        count++;
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout << "\nQueue is empty.\n";
            return -1;
        }
        count--;
        return arr[front++];
    }

    int get_count()
    {
        return count;
    }
};

int main()
{
    queue critical_queue;
    queue severe_queue;
    queue normal_queue;

    int patients_treated[100];
    int treated_count = 0;

    cout << "\nEnter number of commands: ";
    int commands;
    cin >> commands;

    cout << "Enter the operations (e.g., ARRIVE 105 1 or TREAT):\n";
    for (int i = 0; i < commands; i++)
    {
        string command;
        cin >> command;

        if (command == "ARRIVE")
        {
            int id, severity;
            cin >> id >> severity;

            if (severity == 1)
            {
                critical_queue.enqueue(id);
            }
            else if (severity == 2)
            {
                severe_queue.enqueue(id);
            }
            else if (severity == 3)
            {
                normal_queue.enqueue(id);
            } 
        }
        else if (command == "TREAT") 
        {
            if (!critical_queue.is_empty())
            {
                patients_treated[treated_count++] = critical_queue.dequeue();
            }
            else if (!severe_queue.is_empty())
            {
                patients_treated[treated_count++] = severe_queue.dequeue();
            }
            else if (!normal_queue.is_empty())
            {
                patients_treated[treated_count++] = normal_queue.dequeue();
            }
        }
        
    }
    
    cout << "\nEND OF DAY REPORT\n";
    
    cout << "Treatment Order: ";
    if (treated_count == 0) 
    {
        cout << "None";
    } 
    else 
    {
        for (int i = 0; i < treated_count; i++) 
        {
            cout << patients_treated[i];

            if (i < treated_count - 1) 
                cout << " -> ";
        }
    }
    cout << "\n";

    cout << "Total patients treated: " << treated_count << "\n";
    
    int remainingCritical = critical_queue.get_count();
    int remainingSerious = severe_queue.get_count();
    int remainingNormal = normal_queue.get_count();
    int totalRemaining = remainingCritical + remainingSerious + remainingNormal;

    cout << "Total patients remaining: " << totalRemaining << "\n";
    cout << "Critical waiting: " << remainingCritical << "\n";
    cout << "Serious waiting: " << remainingSerious << "\n";
    cout << "Normal waiting: " << remainingNormal << "\n";

    return 0;


}