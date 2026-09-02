#include <iostream>
using namespace std;

void selection_sort(int size, int arr[]);

int main()
{
    int size = 7;
    int salaries[] = {45000, 62000, 38000, 75000, 51000, 68000, 42000};
    
    selection_sort(size, salaries);

    cout << "Lowest Salary: " << salaries[0] << endl;
    if (size % 2)
    {
        cout << "Middle Salary: " << salaries[size/2] << endl;
    }
    else
    {
        cout << "Middle Salary: " << salaries[size/2 - 1] << " and " << salaries[size/2] << endl;
    }
    cout << "Highest Salary: " << salaries[size - 1] << endl;
    
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