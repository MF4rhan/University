#include <iostream>
#include <string>
using namespace std;

class OutOfBoundsException
{
private:
    string error;

public:
    OutOfBoundsException(string msg) : error(msg)
    {}

    string getError() const
    {
        return error;
    }
};


template <typename T>
class SmartArray
{
private:
    T* Array;
    int size;

public:
    SmartArray(int input_size) : size(input_size)
    {
        Array = new T[size];
    }

    ~SmartArray()
    {
        delete []Array;
    }

    T& operator[] (int index)
    {
        if (index < 0 || index >= size)
        {
            throw OutOfBoundsException("Invalid index access attempted.");
        }
        return Array[index];
    }
};

int main()
{
    SmartArray<int> array_one(5);

    try
    {
        for (int i = 0 ; i < 5 ; i++)
        {
            array_one[i] = i;
        }

        for (int i = 0 ; i < 5 ; i++)
        {
            cout << "Index " << i << ": " << array_one[i] << "\n";
        }

        cout << "Index 5: " <<array_one[5] << "\n";
    }
    catch (const OutOfBoundsException& e)
    {
        cout << "Error: " << e.getError();
    }
}
