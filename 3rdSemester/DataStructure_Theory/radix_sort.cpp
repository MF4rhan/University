#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int maxValue = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

void countingSort(int arr[], int n, int exp)
{
    // our final output array
    int* output = new int[n];
    int count[10] = {0}; //because digits are always gonna be 0 - 9

    // coutning the number of times each number appears in the input array
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // getting the prefix sum
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // making the output array
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10; //to make sure we are only sorting by the specific digit place we want
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // copy the new array back into the original array. If we need to return the sorted array, we just return without copying.
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    // clean up the memory
    delete[] output;
}

void radixSort(int arr[], int n)
{
    if (n <= 1) return;

    int maxValue = getMax(arr, n);

    for (int exp = 1; maxValue / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array:" << endl;
    printArray(arr, n);

    radixSort(arr, n);

    cout << "Sorted Array:" << endl;
    printArray(arr, n);

    return 0;
}