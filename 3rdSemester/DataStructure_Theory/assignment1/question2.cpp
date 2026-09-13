#include <iostream>
using namespace std;

void print(int size, int arr[]);
void insertion_sort(int size, int arr[]);
void insert_shelf(int val, int index, int &currSize, int*& arr);

int main()
{
    cout << "Enter the initial Size of the array: ";
    int size;
    cin >> size;

    int* array = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter element Index " << i << " storage: ";
        cin >> array[i];
    }
    
    cout << "Initial Array: ";
    print(size, array);
    
    insertion_sort(size, array);
    cout << "Sorted Array: ";
    print(size, array);

    cout << "\nRenovation: Insert the index where you want to insert the new shelf: ";
    int index;
    cin >> index;
    cout << "\nEnter the value/storage of that index: ";
    int storage;
    cin >> storage;

    insert_shelf(storage, index, size, array);

    cout << "Final Array: ";
    print(size, array);
    cout << endl;

    return 0;
}



void print(int size, int arr[])
{
    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
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
        //print(size, arr);
    }
    
}

void insert_shelf(int val, int index, int& currSize, int*& arr)
{
    currSize++;
    int* new_array = new int[currSize];

    bool flag = false;
    int j = 0;
    for (int i = 0; i < currSize; i++, j++)
    {
        if (i == index)
        {
            new_array[index] = val;
            flag = true;
            continue;
        }
        else
        {
            if (flag)
            {
                j--;
                flag = false;
            }
            new_array[i] = arr[j];
        }
        
    }

    cout << "\nArray after inserting new shelf: ";
    print(currSize, new_array);

    insertion_sort(currSize, new_array);

    delete[] arr;
    arr = new_array;
    
}