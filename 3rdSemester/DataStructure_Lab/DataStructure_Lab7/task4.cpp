#include <iostream>
#include <string>

using namespace std;

int getMax(int arr[], int n)
{
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
    return max_val;
}

void countingSort(int arr[], int n, int exp)
{
    int* output = new int[n];
    int count[10] = {0};

    // count occurrences of each digit
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // prefix sum for index positions
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // build output array backwards to keep it stable
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // copy sorted elements back into arr
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    delete[] output;
}

void radixSort(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int max_val = getMax(arr, n);

    for (int exp = 1; max_val / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

// find all values that tie for the highest frequency
void findMostFrequent(int arr[], int n)
{
    if (n <= 0)
    {
        return;
    }

    int max_freq = 0;
    int current_freq = 1;

    // pass 1, find the highest frequency count
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            current_freq++;
        }
        else
        {
            if (current_freq > max_freq)
            {
                max_freq = current_freq;
            }
            current_freq = 1;
        }
    }
    if (current_freq > max_freq)
    {
        max_freq = current_freq;
    }

    // pass 2, print any intensity matching max_freq
    cout << "The most frequently occurring intensity values:" << endl;
    current_freq = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            current_freq++;
        }
        else
        {
            if (current_freq == max_freq)
            {
                cout << "Intensity " << arr[i - 1] << "\tFrequency: " << max_freq << endl;
            }
            current_freq = 1;
        }
    }
    if (current_freq == max_freq)
    {
        cout << "Intensity " << arr[n - 1] << "\tFrequency: " << max_freq << endl;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

int main()
{
    // original pixel intensities kept unchanged
    int original_pixels[10] = {120, 45, 200, 45, 120, 255, 45, 200, 10, 120};
    int n = 10;

    // copy so the original array stays untouched
    int sorted_pixels[10];
    for (int i = 0; i < n; i++)
    {
        sorted_pixels[i] = original_pixels[i];
    }

    radixSort(sorted_pixels, n);

    cout << "Sorted pixel intensities:" << endl;
    printArray(sorted_pixels, n);
    cout << endl;

    findMostFrequent(sorted_pixels, n);

    return 0;
}
