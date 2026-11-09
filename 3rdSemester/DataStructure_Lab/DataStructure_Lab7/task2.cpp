#include <iostream>
#include <string>

using namespace std;

class Guest
{
public:
    string name;
    int reg_id;
    int priority_score;
    int seat_number;

    Guest(string guest_name = "", int id = 0, int score = 0)
        : name(guest_name), reg_id(id), priority_score(score), seat_number(0)
    {
    }
};

// merges two halves in descending order
void merge(Guest array[], Guest left_array[], Guest right_array[], int left_size, int right_size)
{
    int i = 0, l = 0, r = 0;

    while (l < left_size && r < right_size)
    {
        // >= keeps it stable so earlier registered guests come first on a tie
        if (left_array[l].priority_score >= right_array[r].priority_score)
        {
            array[i] = left_array[l];
            i++;
            l++;
        }
        else
        {
            array[i] = right_array[r];
            i++;
            r++;
        }
    }

    while (l < left_size)
    {
        array[i] = left_array[l];
        i++;
        l++;
    }

    while (r < right_size)
    {
        array[i] = right_array[r];
        i++;
        r++;
    }
}

// standard recursive merge sort
void mergeSort(Guest array[], int size)
{
    if (size <= 1)
    {
        return;
    }

    int middle = size / 2;
    Guest* left_array = new Guest[middle];
    Guest* right_array = new Guest[size - middle];

    int i = 0;
    int j = 0;

    for (; i < size; i++)
    {
        if (i < middle)
        {
            left_array[i] = array[i];
        }
        else
        {
            right_array[j] = array[i];
            j++;
        }
    }

    mergeSort(left_array, middle);
    mergeSort(right_array, size - middle);

    merge(array, left_array, right_array, middle, size - middle);

    delete[] left_array;
    delete[] right_array;
}

// assigns seat numbers starting from 1 after sorting
void assignSeats(Guest array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i].seat_number = i + 1;
    }
}

// search for a guest registration ID and returns their seat number
int searchSeatByRegId(Guest array[], int size, int target_id)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i].reg_id == target_id)
        {
            return array[i].seat_number;
        }
    }
    return -1;
}

int main()
{
    int size = 5;
    Guest guest_list[5] = {
        Guest("Areeba", 104, 85),
        Guest("Hamza", 101, 92),
        Guest("Zain", 105, 85),
        Guest("Hira", 102, 96),
        Guest("Saad", 103, 92)
    };

    // sort by priority descending
    mergeSort(guest_list, size);

    // assign seats 1 to N
    assignSeats(guest_list, size);

    // print sorted guest order with seat numbers
    cout << "Seating arrangement:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << guest_list[i].name << " (" << guest_list[i].seat_number << ")";
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << endl << endl;

    // search tests
    cout << "Seat for ID 102 (Hira): " << searchSeatByRegId(guest_list, size, 102) << endl;
    cout << "Seat for ID 104 (Areeba): " << searchSeatByRegId(guest_list, size, 104) << endl;
    cout << "Seat for ID 999 (Non-existent): " << searchSeatByRegId(guest_list, size, 999) << endl;

    return 0;
}
