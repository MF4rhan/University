#include <iostream>
#include <string>
using namespace std;

class Person
{
	static int count;
	int ID;
	string name;
	public:
	Person(string n=""):name(n), ID(count)	{count++;}
	int getID()	{return ID;}
	string getName()	{return name;}	
};

class student:public Person
{
	int OOP, DLD, MVC;
	public:
		student(int o, int d, int m, string name):Person(name), OOP(o), DLD(d), MVC(m)	{}
		
	void displayResult()
	{
		float avg = (OOP+DLD+MVC)/3.0;
		if(avg>=50)
			cout<<"Student ID: "<<getID()<<"\t Name: "<<getName()<<"\tStatus: Passed\t Average Marks: "<<avg<<endl;
		else
			cout<<"Student ID: "<<getID()<<"\t Name: "<<getName()<<"\tStatus: Failed\t Average Marks: "<<avg<<endl;
	}
	
};

class teacher: public Person
{
	int hours, sal;
	public:
		teacher(int h, string name): Person(name), hours(h), sal(0)	{}
		
	void showSal()
	{
		sal=hours*1000;
		cout<<"Teacher ID: "<<getID()<<"\t Name: "<<getName()<<"\tSalary: "<<sal<<endl;
	}
	void setHours(int h)	{hours=h;}
};


int Person::count=0;

int main()
{
	student Farhan(80, 78, 79, "Farhan");
	teacher Owais(250, "Owais");
	
	Farhan.displayResult();
	Owais.showSal();
	
	return 0;
}
