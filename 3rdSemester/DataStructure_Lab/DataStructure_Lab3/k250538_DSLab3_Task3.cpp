#include <iostream>
using namespace std;

void insertion_sort(int size, int arr[]);
int binary_search(int array[], int size, int val);

int main()
{
    int size = 7;
    int array[] = {78, 45, 92, 67, 55, 88, 73};

    //first, sort according to task.
    insertion_sort(size, array);
    
    cout << "Enter the K'th smallest score you want to find: ";
    int posi;
    cin >> posi;

    cout << "The " << posi << "'th smallest score is: " << array[posi-1] << endl;

    /*
    now...the 4th and 5th requirement doesn't really make much sense.
    we just printed the kth smallest value from the array, so of course it exists in the array,
    so why do we need to binary research to see if it exists or not?
    therefore i will be changing it up to ask the user for any score,
    then we will do a binary search to see if that value is in the array or not.
    */

    cout << "Enter the score to see if it exists in the array: ";
    int score;
    cin >> score;

    int result = binary_search(array, size, score);

    if (result == -1)
    {
       cout << "\n\nThe input score was not in the array.";
    }
    else
    {
       cout << "\n\nThe input score was found at index: " << result << endl;
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
    while(start <= end)
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