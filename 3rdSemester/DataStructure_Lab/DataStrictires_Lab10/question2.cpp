#include <iostream>
#include <string>

using namespace std;

// Class representing a single slot in the hash table
class hashSlot
{
public:
    int auth_code;
    string status;

    // Constructor to initialize each slot as Empty
    hashSlot() : auth_code(-1), status("Empty")
    {
    }
};

// Class to manage the banking hash table using quadratic probing
class bankingHashTable
{
private:
    static const int table_size = 11;
    hashSlot table[table_size];

    // Quadratic probing formula: h(k, i) = (k mod 11 + i^2) mod 11
    int getProbeIndex(int key, int i)
    {
        return ((key % table_size) + (i * i)) % table_size;
    }

public:
    // Search for a transaction authentication code
    int searchCode(int key, bool show_message = true)
    {
        for (int i = 0; i < table_size; i++)
        {
            int index = getProbeIndex(key, i);

            // Stop searching only if a never-used (Empty) slot is reached
            if (table[index].status == "Empty")
            {
                break;
            }

            // Return index if an active matching record is found
            if (table[index].status == "Occupied" && table[index].auth_code == key)
            {
                if (show_message)
                {
                    cout << "Code Found: " << key << " at Index [" << index << "]" << endl;
                }
                return index;
            }
        }

        if (show_message)
        {
            cout << "Code Not Found: " << key << endl;
        }
        return -1;
    }

    // Insert a new transaction authentication code with duplicate prevention and slot reuse
    void insertCode(int key)
    {
        int first_deleted_index = -1;

        for (int i = 0; i < table_size; i++)
        {
            int index = getProbeIndex(key, i);

            // Prevent duplicate insertion if the code already exists
            if (table[index].status == "Occupied" && table[index].auth_code == key)
            {
                cout << "Duplicate Error: Code " << key << " already exists at Index [" << index << "]" << endl;
                return;
            }

            // Save the first deleted slot encountered, but continue probing for duplicates
            if (table[index].status == "Deleted" && first_deleted_index == -1)
            {
                first_deleted_index = index;
            }

            // Reached an Empty slot, so the code does not exist later in the sequence
            if (table[index].status == "Empty")
            {
                int target_index = (first_deleted_index != -1) ? first_deleted_index : index;
                table[target_index].auth_code = key;
                table[target_index].status = "Occupied";
                cout << "Inserted Code: " << key << " at Index [" << target_index << "]" << endl;
                return;
            }
        }

        // If no Empty slot was hit during probing, reuse the saved deleted slot if available
        if (first_deleted_index != -1)
        {
            table[first_deleted_index].auth_code = key;
            table[first_deleted_index].status = "Occupied";
            cout << "Inserted Code: " << key << " at Index [" << first_deleted_index << "]" << endl;
            return;
        }

        cout << "Insertion Failed: No available slot for Code " << key << endl;
    }

    // Mark an existing transaction code as expired (Deleted)
    void removeCode(int key)
    {
        int index = searchCode(key, false);

        if (index == -1)
        {
            cout << "Removal Failed: Code " << key << " does not exist." << endl;
            return;
        }

        table[index].status = "Deleted";
        cout << "Removed Code: " << key << " from Index [" << index << "] (Marked as Deleted)" << endl;
    }

    // Display the complete hash table along with each position's status
    void displayTable()
    {
        cout << "\nFinal Hash Table:" << endl;
        for (int i = 0; i < table_size; i++)
        {
            cout << "Index [" << i << "]: Status = " << table[i].status;
            if (table[i].status == "Occupied")
            {
                cout << ", Code = " << table[i].auth_code;
            }
            cout << endl;
        }
    }
};

int main()
{
    bankingHashTable bank_system;

    cout << "Initial Insertions:" << endl;
    bank_system.insertCode(22);
    bank_system.insertCode(33);
    bank_system.insertCode(44);
    bank_system.insertCode(55);
    bank_system.insertCode(66);
    bank_system.insertCode(77);

    cout << "\nInitial Search:" << endl;
    bank_system.searchCode(55);
    bank_system.searchCode(77);

    cout << "\nModifications:" << endl;
    bank_system.removeCode(33);

    bank_system.searchCode(66);

    bank_system.insertCode(88);
    bank_system.insertCode(55);

    bank_system.removeCode(44);

    bank_system.insertCode(99);

    bank_system.displayTable();

    return 0;
}