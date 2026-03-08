#include <iostream>
#include <string>
using namespace std;

class Teacher
{
	string ID, Name, subject;
	int salary;
	public:
		static int totalsalary;
		Teacher(): ID(""), Name(""), subject(""), salary(0) {}
		Teacher(string ido, string nam, string sub, int sal): ID(ido), Name(nam) ,subject(sub), salary(sal) 
		{
		totalsalary+=sal;

		}
		
		void displayAll()
		{
			cout << "ID: " << ID << endl;
			cout << "Name: " << Name << endl;
			cout << "Subject: " << subject << endl;
			cout << "Salary: " << salary << endl;
			cout << endl;
		}
		int getSal() {return salary;}

};

int Teacher::totalsalary=0;

int main()
{
	string name, subject, ID;
	int salary, n;
	
	cout<< "Enter Number of Teachers: " << endl;
	cin >> n;
	
	Teacher* arro = new Teacher[n];
	
	for(int i=0; i<n; ++i)
	{
		cout << "Enter Teacher #"<< i+1<< " ID: " << endl;
		cin >> ID;
		cout << "Enter Name: " << endl;
		cin >> name;
		cout << "Enter Subject: " << endl;
		cin >> subject;
		cout << "Enter Salary: " << endl;
		cin >> salary;
		
		arro[i] = {ID, name, subject, salary};
	}
	cout << endl;
	cout<< endl;
	cout << "All Data of Teachers: "<< endl;
	for(int i=0; i<n ; ++i)
	{
		cout << "Teacher #"<< i+1 << endl;
		arro[i].displayAll();
	}
	
	cout << "The Highest Paid teacher is: "<< endl;
	int ind=0, high=0;
	for (int i=0; i<n; ++i)
	{
		if(arro[i].getSal()>high)
		{
			high = arro[i].getSal();
			ind=i;
		}
	}
	cout << "Teacher #" << ind+1<<endl;
	cout << "Salary: " << high<<endl;
	cout <<endl;
	
	cout << "The Average Salary is: " << (Teacher::totalsalary)/n << endl;
	
return 0;
}
