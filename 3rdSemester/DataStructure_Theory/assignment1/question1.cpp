#include <iostream>
using namespace std;

void print(int size, int arr[]);
void insertion_sort(int size, int arr[]);

//this is insertion sort
int main()
{
    int lengths[6] = {85, 42, 120, 35, 67, 50};
    int size = 6;
    cout << "initial lengths: ";
    print(size, lengths);

    insertion_sort(size, lengths);

    cout << "\nFinal Array: ";
    print(size, lengths);

    return 0;
}

void print(int size, int lengths[])
{
    for (int i = 0; i < size; i++)
    {
        cout << lengths[i] << " ";
    }
    cout << "\n";
}

void insertion_sort(int size, int arr[])
{
    int temp, index;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > temp ; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
        print(size, arr);
    }
    
}

