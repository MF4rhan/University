#include <iostream>
using namespace std;

void quick_sort(int array[], int start, int end)
{
    if (start >= end) //base case
    {
        return;
    }
    
    int pivot = array[end]; //pivot being the last element
    int j = start;
    int i = j - 1;
    while (j < end) //or j != end
    {
        if (array[j] >= pivot)
        {
            j++;
            continue;
        }
        else
        {
            ++i;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            j++;
        }
        
    }
    ++i;
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    
    quick_sort(array, start, i-1);
    quick_sort(array, i+1, end);
    
}

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
}

int main()
{
    int array[10] = {8, 9, 2, 7, 1, 4, 0, 3, 6, 5};
    int size = 10;
    print(array, size);

    quick_sort(array, 0, size-1);

    print(array, size);
    return 0;
}