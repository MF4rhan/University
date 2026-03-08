#include <iostream>
#include <cstring>
using namespace std;

class StudentRecord
{
    int rollNo;
    char* name;
    float gpa;
    
    public:
        
    StudentRecord() 
    {
        rollNo=0;
        gpa = 0.0;
        name = new char[20];
        strcpy(name, "Unknown");
    }
    StudentRecord(int rollNo, float gpa, const char* name)
    {
        int len=strlen(name);
        this->name = new char[len+1];
        strcpy(this->name, name);
        this->rollNo = rollNo;
        this->gpa=gpa;
    }
    
    StudentRecord(const StudentRecord &cop)
    {
        int len=strlen(cop.name);
        this->name = new char[len + 1];
        strcpy(this->name, cop.name);
        rollNo = cop.rollNo;
        gpa = cop.gpa;
    }
    
    ~StudentRecord() {
        delete[] name;
    }
    
    void displayData()
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "GPA: " << gpa << endl;
    }
    
    void inputData() 
    {
        char temp[100];
        cout << "Enter Name: ";
        cin >> temp;
        delete[] this->name;
        this->name = new char[strlen(temp) + 1];
        strcpy(this->name, temp);
        cout << "Enter Roll No and GPA: ";
        cin >> rollNo >> gpa;
    }
    
};

int main()
{
    StudentRecord* obj[3];

    obj[0] = new StudentRecord(); 

    obj[1] = new StudentRecord(123, 3.3, "Farhan");
    
    obj[2] = new StudentRecord(*obj[1]); 

    obj[2]->inputData(); 

    for(int i = 0; i < 3; i++) 
    {
        obj[i]->displayData();
    }

    for(int i = 0; i < 3; i++) 
    {
        delete obj[i];
    }
    
    return 0;
}
