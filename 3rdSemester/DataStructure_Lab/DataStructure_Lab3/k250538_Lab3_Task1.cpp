#include <iostream>
using namespace std;

int bubble_sort(int size, int arr[]);

int main()
{
    int size = 9;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter element #" << i + 1 << ": ";
        cin >> arr[i];
        cout << endl;
    }

    cout << "Initial Array: \n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int swaps = bubble_sort(size, arr);

    cout << "Sorted Array: \n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The Number of Swaps: " << swaps << endl;

    return 0;
}

int bubble_sort(int size, int arr[])
{
    int temp, counta=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                counta++;
            }
        }
    }

    return counta;
}