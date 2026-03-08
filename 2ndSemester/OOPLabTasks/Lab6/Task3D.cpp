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
	int getSalary() const {return baseSalary+5000;}
};

class Doctor: virtual public Staff
{
	int patientsTreated;
public:
	Doctor(int t, string n, int s): Staff(n, s), patientsTreated(t)	{}
	void setTrips(int t)	{patientsTreated=t;}
	int getBonus1()	{return patientsTreated*500;}
	void DisplayInfo()
	{
		cout<<"Staff ID: "<< getID()<< "\t Name: "<< getName()<<endl;
		cout <<"Base Salary (including 5000 standard Allowance): "<< getSalary()<<endl;
		cout <<"Bonus: "<< getBonus1()<<endl;
	}
};

class Nurse: virtual public Staff
{
	int hoursOvertime;
public:
	Nurse(int i, string n, int s): Staff(n, s), hoursOvertime(i)	{}
	void setItems(int i)	{hoursOvertime=i;}
	int getBonus2()	{return hoursOvertime*200;}
	void DisplayInfo()
		{
			cout<<"Staff ID: "<< getID()<< "\t Name: "<< getName()<<endl;
			cout <<"Base Salary (including 5000 standard Allowance): "<< getSalary()<<endl;
			cout <<"Bonus: "<< getBonus2()<<endl;
		}
};

class HeadNurse: public Nurse, public Doctor
{
	int totalSalary;
public:
	HeadNurse(int t, int i, string n, int s): Nurse(i, n, s), Doctor(t, n , s), Staff(n, s), totalSalary(0)	{}
	int getTotalSalary()	
	{
		totalSalary=getSalary()+getBonus1()+getBonus2();
		return totalSalary;
	}
	void DisplayInfo()
	{
		cout<<"Staff ID: "<< getID()<< "\t Name: "<< getName()<<endl;
		cout <<"Total Salary (inlcuding Bonuses and Allowance): "<< getTotalSalary()<<endl;
	}
};

int Staff::count = 0;

int main()
{
	HeadNurse Evelyne(100, 15, "Evelyne", 150000);
	Evelyne.DisplayInfo();
	return 0;
}