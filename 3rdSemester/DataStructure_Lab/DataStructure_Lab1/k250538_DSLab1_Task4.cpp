//K250538, Muhammad Farhan
#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the size of your Array: ";
    int size;
    cin >> size;
    int *array = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter the element #" << i+1 << ": ";
        cin >> array[i];
    }

    cout << "The Array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n\nEnter the NEW size of your Array: ";
    int new_size;
    cin >> new_size;
    int *new_array = new int[new_size];
    for (int i = 0; i < new_size; i++)
    {
        if (i < size)
        {
            new_array[i] = array[i];
        }
        else
        {
            cout << "\nEnter the element #" << i+1 << ": ";
            cin >> new_array[i];
        }
    }

    cout << "The New Array:" << endl;
    for (int i = 0; i < new_size; i++)
    {
        cout << new_array[i] << " ";
    }


    delete[] array;
    delete[] new_array;
    return 0;
}