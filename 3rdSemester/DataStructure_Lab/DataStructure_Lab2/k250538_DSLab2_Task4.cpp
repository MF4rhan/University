//25K0538, Muhammad Farhan
//For this task too, the most efficient and suitable way to store is to use Jagged Array.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int rows[4] = {3,2,1,1}; //size is small so its easier to input names
    string** Names = new string*[4]; //4 rows
    Names[0] = new string[3] ; //R1
    Names[1] = new string[4] ; //R2
    Names[2] = new string[1] ; //R3
    Names[3] = new string[1] ; //R4

    //taking inputs
    for (int i = 0; i < 4; i++)
    {
        cout << "\nRow " << i+1 << ": " << endl;
        for (int j = 0; j < rows[i]; j++)
        {
            cout << "Enter name for R" << i+1 << "C" << j+1 << ": ";
            cin >> Names[i][j];
            cout << endl;
        }
        cout << endl;
    }

    //showing output
    for (int i = 0; i < 4; i++)
    {
        cout << "Row " << rows[i] << ": ";
        for (int j = 0; j < rows[i]; j++)
        {
            cout << Names[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < 4; i++)
    {
        delete[] Names[i];
    }
    delete[] Names;
    return 0;
}