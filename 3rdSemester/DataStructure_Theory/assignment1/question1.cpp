#include <iostream>
using namespace std;

void print(int size, int arr[]);
void insertion_sort(int size, int arr[]);

//this is insertion sort
int main()
{
    int choice;
    do
    {
        cout << "Do you want to insert your own lengths or use a preset ones (0/1): ";
        cin >> choice;

        if (choice != 1 && choice != 0)
        {
            cout << "\nInvalid Choice, Please try again.\n\n";
        }

    } while (choice != 1 && choice != 0);
    

    int size;
    int* lengths = nullptr;
    if (choice == 1)
    {
        size = 6;
        lengths = new int[size] {85, 42, 120, 35, 67, 50};
    }
    else
    {
        cout << "\nEnter size of array: ";
        cin >> size;

        lengths = new int[size];
        for (int i = 0; i < size; i++)
        {
            cout << "\nEnter length of index " << i << ": ";
            cin >> lengths[i];
        }
    }

    cout << "initial lengths: ";
    print(size, lengths);

    insertion_sort(size, lengths);

    cout << "\nFinal Array: ";
    print(size, lengths);

    return 0;
}

void print(int size, int lengths[])
{
    for (int i = 0; i < size; i++)
    {
        cout << lengths[i] << " ";
    }
    cout << "\n";
}

void insertion_sort(int size, int arr[])
{
    int temp, index;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > temp ; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
        print(size, arr);
    }
    
}

