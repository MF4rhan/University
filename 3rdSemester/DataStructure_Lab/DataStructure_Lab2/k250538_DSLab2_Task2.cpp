#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the size of array: ";
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the Element #" << i + 1 << ": ";
        cin >> arr[i];
    }

    int* unique = new int[size];
    int unique_count = 0;

    for (int i = 0; i < size; i++)
    {
        bool found = false;

        for (int j = 0; j < unique_count; j++)
        {
            if (arr[i] == unique[j])
            {
                found = true;
                cout << arr[i] << " is a duplicate element.\n" << "Enter a new unique element: ";
                int new_element;
                cin >> new_element;

                bool already_exists = false;

                for (int k = 0; k < unique_count; k++)
                {
                    if (new_element == unique[k])
                    {
                        already_exists = true;
                        break;
                    }
                }

                if (!already_exists)
                {
                    unique[unique_count] = new_element;
                    unique_count++;
                }

                break;
            }
        }

        if (!found)
        {
            unique[unique_count] = arr[i];
            unique_count++;
        }
    }

    cout << "\nOriginal Array: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nNew Array: ";

    for (int i = 0; i < unique_count; i++)
    {
        cout << unique[i] << " ";
    }

    delete[] arr;
    delete[] unique;

    return 0;
}
