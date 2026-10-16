#include <iostream>
using namespace std;

void counting_sort(int* array, int size)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        
    }
    
    int counting_array[max+1] = {0};
    for (int i = 0; i < size; i++)
    {
        counting_array[array[i]]++;
    }
    
    for (int i = 1; i < max+1; i++)
    {
        counting_array[i] += counting_array[i-1];
    }
    
    int* sorted_array = new int[size];
    for (int i = size-1; i >= 0 ; i--)
    {
        sorted_array[--counting_array[array[i]]] = array[i];
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = sorted_array[i];
    }
    
}


void print(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
}

int main()
{
    int array[10] = {6, 9, 0, 1, 5, 2, 3, 7, 4, 8};
    int size = 10;

    print(array, size);

    counting_sort(array, size);

    print(array, size);

    return 0;
}