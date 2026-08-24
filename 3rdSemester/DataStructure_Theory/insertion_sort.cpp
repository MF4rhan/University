#include <iostream>
using namespace std;

void insertion_sort(int size, int arr[]);

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

    insertion_sort(size, arr);

    cout << "Sorted Array: \n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void insertion_sort(int size, int arr[])
{
    int temp;
    for (int i = 1; i < size; ++i)
    {
        temp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > temp; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp; 
    }
}