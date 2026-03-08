#include <iostream>
#include <string>
using namespace std;

class Person
{
	static int count;
	int ID;
	string name, city;
	public:
	Person(string n, string c):name(n), ID(count), city(c)	{count++;}
	int getID()	{return ID;}
	string getName()	{return name;}	
	string getCity()	{return city;}
};

class DeliveryStaff: public Person
{
	int numDelivery, payPerDelivery, sal;
	public:
		DeliveryStaff(int nd, int ppd, string name, string city):Person(name, city), numDelivery(nd), payPerDelivery(ppd), sal(0)	{}
		void setNumberofDelivery(int n)	{numDelivery=n;}
		void setPayPerDelivery(int p)	{payPerDelivery=p;}
		void DisplaySalary()
		{
			sal = numDelivery * payPerDelivery;
			if(numDelivery>100)
				{sal+=3000;}
			cout<<"Delivery Staff ID: "<<getID()<<"\t Name: "<<getName()<<"\tCity: "<<getCity()<<"\tSalary: "<<sal<<endl;
			
		}
		
};

class OfficeStaff: public Person
{
	int overtimeHours, fsalary, tsalary, overtimePay;
	public:
		OfficeStaff(int o, int fs, string name, string city):Person(name, city), overtimeHours(o), fsalary(fs), tsalary(0), overtimePay(0)	{}
		void setHours(int h)	{overtimeHours=h;}
		void setSalary(int s)	{fsalary=s;}
		void showTotalSalary()
		{
			overtimePay=overtimeHours*500;
			tsalary=overtimePay+fsalary;
			cout<<"Office Staff ID: "<<getID()<<"\t Name: "<<getName()<<"\tCity: "<<getCity()<<"\tTotal Salary: "<<tsalary<<endl;
		}
			
};


int Person::count=0;

int main()
{
	DeliveryStaff Mohsin(400, 300, "Mohsin", "Karachi");
	OfficeStaff Farhan(10, 60000, "Farhan", "Karachi");
	
	Mohsin.DisplaySalary();
	Farhan.showTotalSalary();
return 0;
}
