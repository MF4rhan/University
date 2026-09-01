#include <iostream>
using namespace std;

void bubble_sort(int size, int arr[],int &comparisions,int &swaps);

int main()
{
    int size = 7;
    int arr[7] = { 1200, 450, 800, 450, 1500, 700, 1200 };

    cout << "Initial Array: \n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int comparisions = 0, swaps = 0;
    bubble_sort(size, arr, comparisions, swaps);

    cout << "Sorted Array: \n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The Number of Swaps: " << swaps << endl;
    cout << "The Number of Comparisions: " << comparisions << endl;
    return 0;
}

void bubble_sort(int size, int arr[], int &comparisions, int &swaps)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            comparisions++;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;

            }
        }
        cout << "Price: " << arr[size - 1 - i] << " has reached its final position." << endl;
    }

}