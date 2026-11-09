#include <iostream>
#include <string>

using namespace std;

class Computer
{
public:
    int id;
    int memory;

    Computer(int comp_id = 0, int comp_memory = 0)
        : id(comp_id), memory(comp_memory)
    {
    }
};

void quickSort(Computer array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    // pick middle element as pivot
    int middle = start + (end - start) / 2;
    int pivot = array[middle].memory;

    // two scanning pointers from left and right
    int i = start;
    int j = end;

    while (i <= j)
    {
        // move left pointer until an element >= pivot is found
        while (array[i].memory < pivot)
        {
            i++;
        }

        // move right pointer until an element <= pivot is found
        while (array[j].memory > pivot)
        {
            j--;
        }

        // swap elements and step both pointers forward to prevent infinite loops on matching values
        if (i <= j)
        {
            Computer temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    // sort left partition
    if (start < j)
    {
        quickSort(array, start, j);
    }

    // sort right partition
    if (i < end)
    {
        quickSort(array, i, end);
    }
}

void printComputers(Computer array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Computer " << array[i].id << " (" << array[i].memory << " MB)";
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

int main()
{
    int size = 5;
    Computer lab_computers[5] = {
        Computer(14, 2048),
        Computer(7, 512),
        Computer(21, 4096),
        Computer(3, 1024),
        Computer(18, 512)
    };

    cout << "Before sorting:" << endl;
    printComputers(lab_computers, size);

    quickSort(lab_computers, 0, size - 1);

    cout << "\nAfter sorting:" << endl;
    printComputers(lab_computers, size);

    return 0;
}
