#include <iostream>
using namespace std;

void merge(int array[], int left_array[], int right_array[], int left_size, int right_size);

void merge_sort(int array[], int size)
{
    if (size <= 1)
    {
        return; //base case
    }

    int middle = size/2;
    int* left_array = new int[middle]; //left array
    int* right_array = new int[size - middle]; //right array

    int i = 0; //for copying left array
    int j = 0; //for copying right array

    for ( ; i < size; i++)
    {
        if (i < middle)
        {
            left_array[i] = array[i];
        }
        else
        {
            right_array[j] = array[i];
            j++;
        }
    }

    merge_sort(left_array, middle);
    merge_sort(right_array, size - middle);



    merge(array, left_array, right_array, middle, size - middle);
    
}

void merge(int array[], int left_array[], int right_array[], int left_size, int right_size)
{
    int i = 0, l = 0, r = 0; //indices for original, left and right array respectively.
    while (l < left_size && r < right_size)
    {
        if (left_array[l] < right_array[r])
        {
            array[i] = left_array[l];
            i++;
            l++;
        }
        else
        {
            array[i] = right_array[r];
            i++;
            r++;
        }
    }
    //now theres probably a element or two that are left due to no comparisions left.
    //so we will make two loops for both left and right arrays.
    while (l < left_size)
    {
        array[i] = left_array[l];
        i++;
        l++;
    }
    while (r < right_size)
    {
        array[i] = right_array[r];
        i++;
        r++;
    }
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
    int array[10] = {9, 2, 1, 6, 8, 3, 5, 4, 7, 0};
    int size = sizeof(array)/sizeof(array[0]);

    print(array, size);

    merge_sort(array, size);

    print(array, size);
    return 0;
}