#include <iostream>
using namespace std;

int main()
{
    int *dynamicArray1D = new int[5];
    int **dynamicArray2D =  new int*[5];

     for (int i = 0; i < 5 ; i++)
    {
        dynamicArray2D[i] = new int[5];
    }

    for (int i = 0; i < 5 ; i++)
    {
        dynamicArray1D[i] = (i*3)/2;
    }

    for (int i = 0; i < 5 ; i++)
    {
        for (int j = 0; j < 5 ; j++)
        {
            dynamicArray2D[i][j] = (i*j)+10;
        }

    }

    cout << "1D Array: \n";
    for (int j = 0; j < 5 ; j++)
    {
        cout << dynamicArray1D[j] << " ";
    }
    cout << "\n\n\n";

    cout << "2D Array: \n";
    for (int i = 0; i < 5 ; i++)
    {
        for (int j = 0; j < 5 ; j++)
        {
            cout << dynamicArray2D[i][j] << " ";
        
        }
        cout << "\n";
    }



    

    delete[] dynamicArray1D;
    for (int j = 0; j < 5 ; j++)
    {
        delete[] dynamicArray2D[j];
    }
    delete[] dynamicArray2D;

    return 0;
}