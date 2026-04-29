#include <iostream>
#include <string>
using namespace std;

class BaseException
{
private:
    string message;

public:
    BaseException(string msg) : message(msg)
    {}

    string getError() const
    {
        return message;
    }
};

class InvalidAgeException : public BaseException
{
public:
    InvalidAgeException(string msg) : BaseException(msg)
    {}
};

class InvalidSalaryException : public BaseException
{
public:
    InvalidSalaryException(string msg) : BaseException(msg)
    {}
};

class InvalidHeightException : public BaseException
{
public:
    InvalidHeightException(string msg) : BaseException(msg)
    {}
};

int main()
{
    int age, salary;
    double height;

    try
    {
        cout << "Enter Age: ";
        cin >> age;
        if (age <=0 || age >= 120)
        {
            throw InvalidAgeException("Age must be between 1 and 119.");
        }

        cout << "Enter Salary: ";
        cin >> salary;
        if (salary <= 0)
        {
            throw InvalidSalaryException("Salary must be Positive.");
        }

        cout << "Enter Height: ";
        cin >> height;
        if (height <= 0)
        {
            throw InvalidHeightException("Height must be Positive.");
        }
    }
    catch (const InvalidAgeException& e)
    {
        cout << "InvalidAgeException caught: " << e.getError() << "\n";
    }
    catch (const InvalidSalaryException& e)
    {
        cout << "InvalidSalaryException caught: " << e.getError() << "\n";
    }
    catch (const InvalidHeightException& e)
    {
        cout << "InvalidHeightException caught: " << e.getError() << "\n";
    }

    return 0;
}
