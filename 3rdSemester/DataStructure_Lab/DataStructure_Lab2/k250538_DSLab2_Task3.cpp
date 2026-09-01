//25K0538, Muhammad Farhan
//For this task, the most efficient and suitable way to store is to use Jagged Array.
#include <iostream>
using namespace std;

int main()
{
    string departments[4] = {"SE", "AI", "CS", "DS"};
    int sizes[4] = {3,4,2,1};
    double** GPA = new double*[4]; //4 departments
    GPA[0] = new double[3] {3.3, 3.67, 3}; //SE
    GPA[1] = new double[4] {2.3, 2.67, 2, 3}; //AI
    GPA[2] = new double[2] {4, 3.3}; //CS
    GPA[3] = new double[1] {2.67}; //DS

    for (int i = 0; i < 4; i++)
    {
        cout << departments[i] << ": ";
        for (int j = 0; j < sizes[i]; j++)
        {
            cout << GPA[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < 4; i++)
    {
        delete[] GPA[i];
    }
    delete[] GPA;
    return 0;
}