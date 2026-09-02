#include <iostream>
using namespace std;

void insertion_sort(int size, int arr[]);
int binary_search(int array[], int size, int val);

int main()
{
    int size = 7;
    int array[] = {78, 45, 92, 67, 55, 88, 73};

    //first, sort.
    insertion_sort(size, array);
    
    cout << "Enter the number to see if it exists in the array: ";
    int num;
    cin >> num;
    
    //now we search.
    int result = binary_search(array, size, num);

    if (result == -1)
    {
       cout << "\n\nThe input number was not in the array.";
    }
    else
    {
       cout << "\n\nThe input number was found at index: " << result << endl;
       cout << "Array[" << result <<"] = " << array[result] << endl;  
    }

    return 0;
}

void insertion_sort(int size, int arr[])
{
    int temp;
    for (int i = 1; i < size; ++i)
    {
        temp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > temp; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp; 
    }
}

int binary_search(int array[], int size, int val)
{
    int middle;
    int start = 0;
    int end = size-1;
    while(start <= end) //if start becomes equal or greater than end, then that means we have completed our sort.
    {
        middle = (start + end)/2;
        if (array[middle] == val)
        {
            return middle;
        }
        if (array[middle] < val)
        {
            start = middle + 1;
        }
        if (array[middle] > val)
        {
            end = middle - 1;
        }
    }
    return -1;
}