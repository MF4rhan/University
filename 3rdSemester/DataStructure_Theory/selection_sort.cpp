#include <iostream>
using namespace std;

void selection_sort(int size, int arr[]);

int main()
{
    int size = 9;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter element #" << i+1 << ": ";
        cin >> arr[i];
        cout << endl;
    }

     cout << "Initial Array: \n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    selection_sort(size, arr);

    cout << "Sorted Array: \n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void selection_sort(int size, int arr[])
{
    int temp, min, index;
    for (int i = 0; i < size-1; i++) //size-1 because the last element would be sorted by the 2nd last loop anyway.
    {
        min = arr[i];
        index = i;
        for (int j = i+1; j < size; j++) //i+1 to avoid comparing arr[i] to itself o-n the first loop
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        if (arr[i] == min)
        {
            continue;
        }
        temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }
}