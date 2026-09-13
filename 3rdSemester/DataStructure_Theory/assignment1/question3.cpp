#include <iostream>
using namespace std;

void print(int size, int arr[]);
void comb_sort(int size, int arr[]);

int main()
{
    int choice;
    do
    {
        cout << "Do you want to insert your own elements or use a preset ones (0/1): ";
        cin >> choice;

        if (choice != 1 && choice != 0)
        {
            cout << "\nInvalid Choice, Please try again.\n\n";
        }

    } while (choice != 1 && choice != 0);
    

    int size;
    int* array = nullptr;
    if (choice == 1)
    {
        size = 8;
        array = new int[size] {120, 35, 90, 15, 75, 10, 60, 25};
    }
    else
    {
        cout << "\nEnter size of array: ";
        cin >> size;

        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            cout << "\nEnter element of index " << i << ": ";
            cin >> array[i];
        }
    }

    

    cout << "Initial Array: ";
    print(size, array);

    comb_sort(size, array);

    cout << "\nFinal Array: ";
    print(size, array);

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

void comb_sort(int size, int arr[])
{
    int gap = size;
    bool swapped = false;
    for (int i = 0; i < size; i++)
    {
        gap = (gap*10)/13;
        if (gap < 1)
        {
            gap = 1;
        }
        int end = size - gap;
        for (int j = 0; j < end; j++)
        {
            if (arr[j] > arr[j+gap])
            {
                int temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;
                swapped = true;
            }
            
        }
        if (gap == 1 && !swapped)
        {
            return;
        }
        
    }
    
}