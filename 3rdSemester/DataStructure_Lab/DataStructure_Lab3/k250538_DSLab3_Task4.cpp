#include <iostream>
using namespace std;

void insertion_sort(int size, int arr[]);
int binary_search(int array[], int size, int val);

int main()
{
    int size = 7;
    int books[] = {105, 203, 150, 87, 310, 120, 250};
    
    cout << "Enter the Book ID you want to search: ";
    int ID;
    cin >> ID;
    
    //initial search.
    int result = binary_search(books, size, ID);

    if (result == -1)
    {
       cout << "\n\nThe input ID could not be found.";
    }
    else
    {
       cout << "\n\nThe input ID was found at index: " << result << endl;
       cout << "Book[" << result <<"] = " << books[result] << endl;  
    }

    //now sort.
    insertion_sort(size, books);

    //again, search.
    result = binary_search(books, size, ID);

    if (result == -1)
    {
       cout << "\n\nThe input ID could not be found.";
    }
    else
    {
       cout << "\n\nThe input ID was found at index: " << result << endl;
       cout << "Book[" << result <<"] = " << books[result] << endl;  
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
    while(start <= end) //if start becomes equal or greater than end, then that means we have completed our search.
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