#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    int roll;
    float* marks;
    static int count;
    static float totalmarks;
    public:
    Student(string nam, int rol, float m1, float m2, float m3): roll(rol), name(nam)
    {
        count++;
        marks = new float [3];
        marks[0]=m1;
        marks[1]=m2;
        marks[2]=m3;
        totalmarks+= (m1+m2+m3);
    }

    Student(const Student& other)
    {
        roll=other.roll;
        name=other.name;
        marks = new float[3];
        for(int i=0; i<3; i++)
        {
            marks[i] = other.marks[i];
            totalmarks+= other.marks[i];
        }
        count++;
    }

    ~Student()
    {
        totalmarks-= (marks[0] + marks[1] + marks[2]);
        count--;
        delete[] marks;
    }

    void display()
    {
        cout<<"Name: "<<name<<", Roll no: "<<roll<<", Marks:";
        for(int i=0; i<3; i++)
            cout<<" "<<marks[i];
        cout<<endl;
    }

};

int Student::count=0;
float Student::totalmarks=0;

int main()
{
    Student s1("Farhan", 538, 70, 85, 78.2);
    Student s2("Faraz", 780, 89, 78.2, 69.8);
    Student s3(s1);

    s1.display();
    s2.display();
    s3.display();

    return 0;
};
