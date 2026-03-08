#include <iostream>
using namespace std;

struct employee
{
	int ID;
	string name;
	int salary;
};

int main()
{
	struct employee emp[3];
	int highest=0;
	
	for(int i=0; i<3; i++)
	{
		cout << "Enter ID of employee#" << i+1 << endl;
		cin >> emp[i].ID;
		cout << "Enter name of employee#" << i+1 << endl;
		cin >> emp[i].name;
		cout << "Enter Salary of employee#" << i+1 << endl;
		cin >> emp[i].salary;
		if (highest < emp[i].salary)
		{
			highest = emp[i].salary;
		}
	}
	for (int i=0; i<3; i++)
	{
		if (highest == emp[i].salary)
		{
			cout << "Employee#" << i+1 <<" has the highest salary." << endl;
			cout << "ID: " << emp[i].ID << endl;
			cout << "Name: " << emp[i].name << endl;
			cout << "Salary: " << highest << endl;
		}
	}
}
