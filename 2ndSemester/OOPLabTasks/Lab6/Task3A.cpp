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

class Employee : public Person
{
	string department;
	int basicSalary;
public:
	Employee(string d, int s, string name):Person(name), department(d), basicSalary(s)	{}
	void setDepartment(string d)	{department=d;}
	void setSalary(int s)	{basicSalary=s;}
	string getDepartment() const {return department;}
	int getSalary() const	{return basicSalary;}
};

class Manager : public Employee
{
	int teamSize;
	double totalSalary;
public:
	Manager(int ts, string d, int s, string name):Employee(d, s, name), teamSize(ts), totalSalary(0)	{};
	void setTeamSize(int t)	{teamSize=t;}
	int getTeamSize() const {return teamSize;}
	double getTotalSalary()	
	{
		return totalSalary = getSalary() + (teamSize * 1000);
	}
};

int Person::count = 0;

int main()
{
	Manager Farhan(5, "CyberSecurity", 1000000, "Farhan");
	cout<<"Student ID: "<<Farhan.getID()<<"\t Name: "<<Farhan.getName()<<"\nDepartment: "<<Farhan.getDepartment()<<
	"\tTeam Size: "<<Farhan.getTeamSize()<< "\nBase Salary: "<<Farhan.getSalary()<<"\tTotal Salary: "<<Farhan.getTotalSalary() <<endl;
return 0;	
}