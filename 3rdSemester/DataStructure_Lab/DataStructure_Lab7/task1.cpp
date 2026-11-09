#include <iostream>
#include <string>

using namespace std;

class Transaction
{
public:
    string id;
    int time;

    Transaction(string transac = "", int timer = 0) : id(transac), time(timer)
    {}
};

void mergeLogs(Transaction array[], Transaction left_array[], Transaction right_array[], int left_size, int right_size)
{
    int i = 0, l = 0, r = 0;

    while (l < left_size && r < right_size)
    {
        // <= ensures Counter A gets priority if times are equal
        if (left_array[l].time <= right_array[r].time)
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

void findLongestGap(Transaction array[], int size)
{
    int max_gap = -1;
    string id_1 = "";
    string id_2 = "";

    for (int i = 0; i < size - 1; i++)
    {
        int gap = array[i + 1].time - array[i].time;
        if (gap > max_gap)
        {
            max_gap = gap;
            id_1 = array[i].id;
            id_2 = array[i + 1].id;
        }
    }

    cout << "The longest gap is " << max_gap << " minutes, between " << id_1 << " and " << id_2 << endl;
}

string searchByTime(Transaction array[], int size, int target_time)
{
    for (int i = 0; i < size; i++)
    {
        // Returns the first match found since array is already sorted
        if (array[i].time == target_time)
        {
            return array[i].id;
        }
    }
   return "-1";
}

int main()
{
    Transaction counter_a[4] =
    {
        Transaction("A1", 540),
        Transaction("A2", 555),
        Transaction("A3", 600),
        Transaction("A4", 660)
    };
    int size_a = 4;

    Transaction counter_b[4] =
    {
        Transaction("B1", 545),
        Transaction("B2", 600),
        Transaction("B3", 610),
        Transaction("B4", 700)
    };
    int size_b = 4;

    int total_size = size_a + size_b;
    Transaction merged_log[8];

    mergeLogs(merged_log, counter_a, counter_b, size_a, size_b);

    cout << "Merged log: ";
    for (int i = 0; i < total_size; i++)
    {
        cout << merged_log[i].id << " " << merged_log[i].time;
        if (i < total_size - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    findLongestGap(merged_log, total_size);

    cout << "Searching 600 returns: " << searchByTime(merged_log, total_size, 600) << endl;
    cout << "Searching 650 returns: " << searchByTime(merged_log, total_size, 650) << endl;

    return 0;
}
