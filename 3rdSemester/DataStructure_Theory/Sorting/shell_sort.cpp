#include <iostream>
using namespace std;

void shell_sort(int size, int arr[]);

int main()
{
    int size = 9;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
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

    shell_sort(size, arr);

    cout << "Sorted Array: \n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}

void shell_sort(int size, int arr[])
{
    int temp;
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; ++i)
        {
            temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap)
            {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}