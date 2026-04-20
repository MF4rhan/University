#include <iostream>
#include <fstream>
using namespace std;

struct student
{
    char name[50];
    int id;
    float gpa;
};


int main()
{
    ofstream outFile("students.dat", ios::out | ios::binary);
    if (!outFile)
    {
        cout << "ERROR: File could not open.\n";
        return 1;
    }
    //writing phase
    int count;
    cout << "Enter the number of students to enter: ";
    cin >> count;
    cin.ignore();
    for (int i = 0; i < count ; i++)
    {
        student s;
        cout << "\n\nEnter student #" << i+1 << " name: ";
        cin.getline(s.name, 50);
        cout << "Enter student #" << i+1 << "id: ";
        cin >> s.id;
        cin.ignore();
        cout << "Enter student #" << i+1 << "GPA: ";
        cin >> s.gpa;
        cin.ignore();

        outFile.write((char*)&s, sizeof(student));
    }
    outFile.close();

    //now reading phase
    student reading;
    ifstream inFile("students.dat", ios::in | ios::binary);
    while (inFile.read((char*)&reading, sizeof(student)))
    {
        cout << "Name: " << reading.name << "\n";
        cout << "ID: " << reading.id << "\n";
        cout << "GPA: " << reading.gpa << "\n";
        cout << "\n\n";
    }
    inFile.close();
    return 0;
}
