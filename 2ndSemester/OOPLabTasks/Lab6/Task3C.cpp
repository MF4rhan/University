#include <iostream>
#include <string>
using namespace std;
class Staff
{
	static int count;
	int ID;
	string name;
	int baseSalary;
	public:
	Staff(string n, int s):name(n), ID(count), baseSalary(s)	{count++;}
	int getID()	const {return ID;}
	string getName()	{return name;}	
	int getSalary() const {return baseSalary+2000;}
};

class Driver: public Staff
{
	int tripsCompleted;
public:
	Driver(int t, string n, int s): Staff(n, s), tripsCompleted(t)	{}
	void setTrips(int t)	{tripsCompleted=t;}
	int getBonus()	{return tripsCompleted*500;}
	void DisplayInfo()
	{
		cout<<"Staff ID: "<< getID()<< "\t Name: "<< getName()<<endl;
		cout <<"Base Salary (including 2000 standard Allowance): "<< getSalary()<<endl;
		cout <<"Bonus: "<< getBonus()<<endl;
	}
};

class Loader: public Staff
{
	int itemsHandled;
public:
	Loader(int i, string n, int s): Staff(n, s), itemsHandled(i)	{}
	void setItems(int i)	{itemsHandled=i;}
	int getBonus()	{return itemsHandled*200;}
	void DisplayInfo()
		{
			cout<<"Staff ID: "<< getID()<< "\t Name: "<< getName()<<endl;
			cout <<"Base Salary (including 2000 standard Allowance): "<< getSalary()<<endl;
			cout <<"Bonus: "<< getBonus()<<endl;
		}
};

int Staff::count = 0;

int main()
{
	Driver Farhan(200, "Farhan", 60000);
	Loader Mohsin(300, "Mohsin", 65000);
	Farhan.DisplayInfo();
	Mohsin.DisplayInfo();
	return 0;
}