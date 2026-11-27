#include <iostream>
#include <string>

using namespace std;

// Class representing a single slot in the hospital hash table
class hashSlot
{
public:
    int patient_id;
    string status;

    // Constructor to initialize slot as Empty
    hashSlot() : patient_id(-1), status("Empty")
    {
    }
};

// Class to manage emergency patient records using double hashing
class hospitalHashTable
{
private:
    static const int table_size = 13;
    hashSlot table[table_size];
    int total_collisions;

    // Primary hash function: h1(k) = k mod 13
    int primaryHash(int key)
    {
        return key % table_size;
    }

    // Secondary hash function: h2(k) = 7 - (k mod 7)
    int secondaryHash(int key)
    {
        return 7 - (key % 7);
    }

    // Double hashing formula: h(k, i) = (h1(k) + i * h2(k)) mod 13
    int getProbeIndex(int key, int i)
    {
        return (primaryHash(key) + (i * secondaryHash(key))) % table_size;
    }

public:
    // Constructor to initialize collision counter
    hospitalHashTable() : total_collisions(0)
    {
    }

    // Search for a patient ID in the hash table
    int searchPatient(int key, bool show_message = true)
    {
        for (int i = 0; i < table_size; i++)
        {
            int index = getProbeIndex(key, i);

            // Stop searching if a never-used slot is reached
            if (table[index].status == "Empty")
            {
                break;
            }

            // Return index if active matching patient ID is found
            if (table[index].status == "Occupied" && table[index].patient_id == key)
            {
                if (show_message)
                {
                    cout << "Patient Found: ID " << key << " at Index [" << index << "]" << endl;
                }
                return index;
            }
        }

        if (show_message)
        {
            cout << "Patient Not Found: ID " << key << endl;
        }
        return -1;
    }

    // Insert a patient ID with duplicate prevention, deleted slot reuse, and collision counting
    void insertPatient(int key)
    {
        int first_deleted_index = -1;
        int current_collisions = 0;

        for (int i = 0; i < table_size; i++)
        {
            int index = getProbeIndex(key, i);

            // Check if the slot is currently occupied
            if (table[index].status == "Occupied")
            {
                // Prevent duplicate insertion
                if (table[index].patient_id == key)
                {
                    cout << "Duplicate Error: Patient ID " << key << " already exists at Index [" << index << "]" << endl;
                    return;
                }

                // Count occupied position encountered during probing
                current_collisions++;
            }
            // Record the first deleted slot encountered while continuing to check for duplicates
            else if (table[index].status == "Deleted" && first_deleted_index == -1)
            {
                first_deleted_index = index;
            }
            // Reached an Empty slot; safe to insert into first deleted slot or this empty slot
            else if (table[index].status == "Empty")
            {
                int target_index = (first_deleted_index != -1) ? first_deleted_index : index;
                table[target_index].patient_id = key;
                table[target_index].status = "Occupied";
                total_collisions += current_collisions;
                cout << "Inserted Patient ID: " << key << " at Index [" << target_index << "]" << endl;
                return;
            }
        }

        // Reuse the saved deleted slot if the entire table was probed without hitting Empty
        if (first_deleted_index != -1)
        {
            table[first_deleted_index].patient_id = key;
            table[first_deleted_index].status = "Occupied";
            total_collisions += current_collisions;
            cout << "Inserted Patient ID: " << key << " at Index [" << first_deleted_index << "]" << endl;
            return;
        }

        cout << "Insertion Failed: Hash table is full for Patient ID " << key << endl;
    }

    // Remove a patient ID by marking its slot as Deleted
    void removePatient(int key)
    {
        int index = searchPatient(key, false);

        if (index == -1)
        {
            cout << "Removal Failed: Patient ID " << key << " does not exist." << endl;
            return;
        }

        table[index].status = "Deleted";
        cout << "Removed Patient ID: " << key << " from Index [" << index << "] (Marked as Deleted)" << endl;
    }

    // Display the final hash table and total collision count
    void displayTable()
    {
        cout << "\nFinal Hash Table:" << endl;
        for (int i = 0; i < table_size; i++)
        {
            cout << "Index [" << i << "]: Status = " << table[i].status;
            if (table[i].status == "Occupied")
            {
                cout << ", Patient ID = " << table[i].patient_id;
            }
            cout << endl;
        }
        cout << "\nTotal Collisions: " << total_collisions << endl;
    }
};

int main()
{
    hospitalHashTable hospital_system;

    cout << "Initial Insertions:" << endl;
    hospital_system.insertPatient(18);
    hospital_system.insertPatient(31);
    hospital_system.insertPatient(44);
    hospital_system.insertPatient(57);
    hospital_system.insertPatient(70);
    hospital_system.insertPatient(83);
    hospital_system.insertPatient(96);
    hospital_system.insertPatient(109);

    cout << "\nInitial Search:" << endl;
    hospital_system.searchPatient(83);
    hospital_system.searchPatient(120);

    cout << "\nModifications:" << endl;
    hospital_system.removePatient(44);
    hospital_system.insertPatient(135);

    cout << "\nPost-Insertion Search:" << endl;
    hospital_system.searchPatient(135);
    hospital_system.searchPatient(44);

    cout << "\nFurther Modifications:" << endl;
    hospital_system.insertPatient(148);
    hospital_system.insertPatient(83);
    hospital_system.removePatient(57);

    hospital_system.displayTable();

    return 0;
}