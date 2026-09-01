//25K0538, Muhammad Farhan
#include <iostream>
using namespace std;

int main()
{
    int sizes[4] = {3,4,2,1};
    int** array = new int*[4]; 
    array[0] = new int[3] {3, 4, 3}; 
    array[1] = new int[4] {10, 2, 7, 3}; 
    array[2] = new int[2] {4, 8}; 
    array[3] = new int[1] {9}; 

    int max = 0;
    int max_index = 0;
   for (int i = 0; i < 4; i++)
    {
        int count = 0;
        for (int j = 0; j < sizes[i]; j++)
        {
            count++;
        }
        if (count > max)
        {
            max = count;
            max_index = i;
        }
    }
    
    cout << "Row " << max_index+1 << " contains the maximum number of elements." << endl;
    cout << "Size: " << max << endl;
    for (int i = 0; i < max; i++)
    {
        cout << array[max_index][i] << " ";
    }

    for (int i = 0; i < 4; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}