#include <iostream>
#include <string>

using namespace std;

// Class representing a single student record node in the linked list
class studentNode
{
public:
    int app_no;
    string student_name;
    studentNode* next_node;

    // Constructor to initialize node data using an initializer list
    studentNode(int num, string name) : app_no(num), student_name(name), next_node(nullptr)
    {
    }
};

// Class to manage the hash table using separate chaining
class hashTable
{
private:
    static const int table_size = 10;
    studentNode* table[table_size];

    // Division method to calculate the index for a given application number
    int getHashIndex(int app_no)
    {
        return app_no % table_size;
    }

public:
    // Constructor to initialize all table slots to nullptr
    hashTable()
    {
        for (int i = 0; i < table_size; i++)
        {
            table[i] = nullptr;
        }
    }

    // Search for an application number and return a pointer to the node if found
    studentNode* searchRecord(int app_no, bool show_message = true)
    {
        int index = getHashIndex(app_no);
        studentNode* current_node = table[index];

        // Traverse the linked list at the calculated index
        while (current_node != nullptr)
        {
            if (current_node->app_no == app_no)
            {
                if (show_message)
                {
                    cout << "Record Found - Application No: " << current_node->app_no
                         << ", Name: " << current_node->student_name
                         << " (Index: " << index << ")" << endl;
                }
                return current_node;
            }
            current_node = current_node->next_node;
        }

        if (show_message)
        {
            cout << "Record Not Found - Application No: " << app_no << endl;
        }
        return nullptr;
    }

    // Insert a new student application record at the end of the chain
    void insertRecord(int app_no, string student_name)
    {
        // Check if the application number already exists before inserting
        if (searchRecord(app_no, false) != nullptr)
        {
            cout << "Duplicate Error: Application No " << app_no << " already exists." << endl;
            return;
        }

        int index = getHashIndex(app_no);

        // Create and populate the new node
        studentNode* new_node = new studentNode(app_no, student_name);

        // If the slot is empty, place the new node at the head
        if (table[index] == nullptr)
        {
            table[index] = new_node;
        }
        else
        {
            // Traverse to the end of the chain and attach the new node
            studentNode* current_node = table[index];
            while (current_node->next_node != nullptr)
            {
                current_node = current_node->next_node;
            }
            current_node->next_node = new_node;
        }
    }

    // Remove a node from the linked list (handles head, middle, and tail nodes)
    void removeRecord(int app_no)
    {
        int index = getHashIndex(app_no);
        studentNode* current_node = table[index];
        studentNode* prev_node = nullptr;

        // Search for the node to delete while keeping track of the previous node
        while (current_node != nullptr && current_node->app_no != app_no)
        {
            prev_node = current_node;
            current_node = current_node->next_node;
        }

        // If the record does not exist in the list
        if (current_node == nullptr)
        {
            cout << "Removal Failed: Application No " << app_no << " does not exist." << endl;
            return;
        }

        // Case 1: Deleting the first node (head) of the linked list
        if (prev_node == nullptr)
        {
            table[index] = current_node->next_node;
        }
        // Case 2 & 3: Deleting a middle node or the last node (tail)
        else
        {
            prev_node->next_node = current_node->next_node;
        }

        cout << "Removed Application No: " << current_node->app_no
             << " (" << current_node->student_name << ")" << endl;
        delete current_node;
    }

    // Display all indexes of the hash table and their linked-list contents
    void displayTable()
    {
        cout << "\nComplete Hash Table:" << endl;
        for (int i = 0; i < table_size; i++)
        {
            cout << "Index [" << i << "]: ";
            studentNode* current_node = table[i];

            if (current_node == nullptr)
            {
                cout << "Empty";
            }
            else
            {
                while (current_node != nullptr)
                {
                    cout << "[" << current_node->app_no << " | " << current_node->student_name << "]";
                    if (current_node->next_node != nullptr)
                    {
                        cout << " -> ";
                    }
                    current_node = current_node->next_node;
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    hashTable admission_system;

    admission_system.insertRecord(27, "Ali");
    admission_system.insertRecord(37, "Sara");
    admission_system.insertRecord(17, "Ahmed");
    admission_system.insertRecord(42, "Hina");
    admission_system.insertRecord(52, "Zain");
    admission_system.insertRecord(62, "Ayesha");
    admission_system.insertRecord(34, "Usman");
    admission_system.insertRecord(44, "Fatima");
    admission_system.insertRecord(54, "Hamza");
    admission_system.insertRecord(24, "Maryam");

    cout << "Initial Search:" << endl;
    admission_system.searchRecord(62);
    admission_system.searchRecord(72);

    cout << "\nModifications:" << endl;
    admission_system.removeRecord(27);
    admission_system.removeRecord(54);

    admission_system.insertRecord(47, "Daniyal");
    cout << "Inserted Application No: 47 (Daniyal)" << endl;

    cout << "\nPost-Modification Search:" << endl;
    admission_system.searchRecord(37);
    admission_system.searchRecord(54);
    admission_system.searchRecord(47);

    admission_system.displayTable();

    return 0;
}