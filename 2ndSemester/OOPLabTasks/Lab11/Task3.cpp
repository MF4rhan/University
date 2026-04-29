#include <iostream>
#include <string>
using namespace std;

class Exception
{
private:
    string error;

public:
    Exception(string msg) : error(msg)
    {}

    string getError()
    {
        return error;
    }
};

template <typename T>
class DataTool
{
private:
    T* array;
    int size;

public:
    DataTool(T* input_array, int input_size) : array(input_array), size(input_size)
    {}

    T findMax()
    {
        if (size <= 0)
        {
            throw Exception("Array is Empty.");
        }
        T max = array[0];
        for (int i = 0 ; i < size ; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
            }
        }
        return max;
    }
};


int main()
{
    int int_array[] = {15, 25, 24, 16, 9, 39, 69};
    int int_size = sizeof(int_array) / sizeof(int_array[0]);
    //basically a guaranteed way to get the size of any array of any data type, you could hard code it to divide by 4 for int only

    try
    {
        DataTool<int> tool_one(int_array, int_size);
        cout << "Max Integer: " << tool_one.findMax() << "\n";
    }
    catch(Exception e)
    {
        cout << "Error: " << e.getError();
    }
    double double_array[] = {23.432, 54.453, 3.444, 6.9999};
    double double_size = sizeof(double_array) / sizeof(double_array[0]);

    try
    {
        DataTool<double> tool_two(double_array, double_size);
        cout << "Max Double: " << tool_two.findMax() << "\n";
    }
    catch(Exception e)
    {
        cout << "Error: " << e.getError();
    }

    return 0;
}
