//25K-0538, Muhammad Farhan, updated version with topics in class
#include <iostream>
#include <string>
using namespace std;

class Employee
{
    int emp_id;
    public:
    Employee(int id):emp_id(id) {}
    void work() 
    {cout<<"I am working"<<endl;}
    void attend_meeting()
    {
        cout<<"I am attending as a Employee "<<endl;
    }
};

class Developer: public Employee
{
    //for later use
    public:
    Developer(int id):Employee(id) {}
    void writeCode(string lang)
    {
        cout<<"I am developing in "<<lang<<endl;
    }
    void writeCode(string lang, string ling)
    {
        cout<<"I am developing in "<<lang<<" and "<<ling<<endl;
    }
    void attend_meeting()
    {
        cout<<"I am attending as a Developer "<<endl;
    }
    
};

class Tester : public Employee
{
    //for later use
    public:
    Tester(int id):Employee(id) {}
    void testCode(string lang)
    {
      cout<<"I am testing code written in "<<lang<<endl;
    }
    void testCode(string lang, string ling)
    {
      cout<<"I am testing code written in "<<lang<<" and "<<ling<<endl;
    }
void attend_meeting()
    {
        cout<<"I am attending as a Tester "<<endl;
    }
};

int main() {
    Developer dev(123);
    Tester test(345);
    dev.work();
    test.work();
    dev.writeCode("Rust");
    dev.writeCode("Rust", "Ruby");
    dev.attend_meeting();
    test.testCode("Rust");
    test.testCode("Rust","Ruby");
    test.attend_meeting();

    return 0;
}