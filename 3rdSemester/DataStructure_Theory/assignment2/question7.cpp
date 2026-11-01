#include <iostream>
#include <string>

using namespace std;

struct Parcel
{
    long long tracking_number;
    string sender_name;
    string destination_city;
    int region_code;
    Parcel* next;

    Parcel() : tracking_number(0), sender_name(""), destination_city(""), region_code(0), next(nullptr)
    {
    }

    Parcel(long long tracking, string sender, string destination, int region) : tracking_number(tracking), sender_name(sender), destination_city(destination), region_code(region), next(nullptr)
    {
    }
};

void counting_sort_by_digit(Parcel* parcels, int total_parcels, long long place_value)
{
    Parcel* output = new Parcel[total_parcels];
    int count[10] = {0};

    for (int i = 0; i < total_parcels; i++)
    {
        int digit = (parcels[i].tracking_number / place_value) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // backwards loop preserves stability
    for (int i = total_parcels - 1; i >= 0; i--)
    {
        int digit = (parcels[i].tracking_number / place_value) % 10;
        output[count[digit] - 1] = parcels[i];
        count[digit]--;
    }

    for (int i = 0; i < total_parcels; i++)
    {
        parcels[i] = output[i];
    }

    delete[] output;
}

// part 1, radix sort for tracking numbers
void radix_sort_tracking(Parcel* parcels, int total_parcels)
{
    long long max_value = 0;
    for (int i = 0; i < total_parcels; i++)
    {
        if (parcels[i].tracking_number > max_value)
        {
            max_value = parcels[i].tracking_number;
        }
    }

    for (long long place_value = 1; max_value / place_value > 0; place_value *= 10)
    {
        counting_sort_by_digit(parcels, total_parcels, place_value);
    }
}

void split_list(Parcel* source, Parcel** front_ref, Parcel** back_ref)
{
    Parcel* slow = source;
    Parcel* fast = source->next;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front_ref = source;
    *back_ref = slow->next;
    slow->next = nullptr;
}

Parcel* merge_lists(Parcel* left_list, Parcel* right_list)
{
    if (left_list == nullptr)
    {
        return right_list;
    }
    if (right_list == nullptr)
    {
        return left_list;
    }

    Parcel* head = nullptr;
    Parcel* tail = nullptr;

    // <= keeps relative order stable for identical region codes
    if (left_list->region_code <= right_list->region_code)
    {
        head = left_list;
        left_list = left_list->next;
    }
    else
    {
        head = right_list;
        right_list = right_list->next;
    }
    tail = head;

    while (left_list != nullptr && right_list != nullptr)
    {
        if (left_list->region_code <= right_list->region_code)
        {
            tail->next = left_list;
            left_list = left_list->next;
        }
        else
        {
            tail->next = right_list;
            right_list = right_list->next;
        }
        tail = tail->next;
    }

    if (left_list != nullptr)
    {
        tail->next = left_list;
    }
    else
    {
        tail->next = right_list;
    }

    return head;
}

// part 2, merge sort on linked list with o(log n) stack space
Parcel* merge_sort_regions(Parcel* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Parcel* left_half = nullptr;
    Parcel* right_half = nullptr;

    split_list(head, &left_half, &right_half);

    left_half = merge_sort_regions(left_half);
    right_half = merge_sort_regions(right_half);

    return merge_lists(left_half, right_half);
}

void print_array(Parcel* parcels, int total_parcels)
{
    for (int i = 0; i < total_parcels; i++)
    {
        cout << parcels[i].tracking_number << " "<< parcels[i].sender_name << " "<< parcels[i].destination_city << " "<< parcels[i].region_code << "\n";
    }
    cout << "\n";
}

void print_list(Parcel* head)
{
    Parcel* current = head;
    while (current != nullptr)
    {
        cout << current->region_code << " "<< current->tracking_number << " " << current->sender_name << " "<< current->destination_city << "\n";
        current = current->next;
    }
    cout << "\n";
}

int main()
{
    const int total_parcels = 5;
    Parcel parcel_array[total_parcels] = {
        Parcel(84920, "Farhan", "Karachi", 104),
        Parcel(999201931, "Faraz", "Lahore", 102),
        Parcel(7, "Ali", "Islamabad", 104),
        Parcel(10203040, "Bilal", "Peshawar", 101),
        Parcel(504, "Hamza", "Quetta", 102)
    };

    cout << "Part 1:\n";
    radix_sort_tracking(parcel_array, total_parcels);
    print_array(parcel_array, total_parcels);

    Parcel* head = &parcel_array[0];
    for (int i = 0; i < total_parcels - 1; i++)
    {
        parcel_array[i].next = &parcel_array[i + 1];
    }
    parcel_array[total_parcels - 1].next = nullptr;

    cout << "Part 2:\n";
    head = merge_sort_regions(head);
    print_list(head);

    return 0;
}