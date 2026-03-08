#include <iostream>
#include <string>
using namespace std;

class Employee
{
	string name;
	int idNumber;
	string department;
	string position;
	
	public:
		Employee():name(""), idNumber(0), department(""), position("") {}
		
		Employee(string n, int num, string dep, string pos):name(n), idNumber(num), department(dep), position(pos) {}
		
		~Employee()
		{
			cout << "I am Destructor"<<endl;
		}
		void setName(string nam)
		{
			name = nam;
		}
		void setidNumber(int num)
		{
			idNumber = num;
		}
		void setDepartment(string dep)
		{
			department = dep;
		}
		void setPosition(string pos)
		{
			position = pos;
		}

		string getName()
		{
			return name;
		}
		int getidNumber()
		{
			return idNumber;
		}
		string getDepartment()
		{
			return department;
		}
		string getPosition()
		{
			return position;
		}
		
};

int main()
{
	Employee emp1,emp2,emp3("Farhan", 538, "Computer Science", "Student");
	
	cout << "Employee#1:"<< endl;
	cout << "Name: " << emp1.getName()<<endl;
	cout << "ID Number: " << emp1.getidNumber()<<endl;
	cout << "Department: " << emp1.getDepartment()<<endl;
	cout << "Position: " << emp1.getPosition()<<endl;
	cout <<endl;
	
	cout << "Employee#2:"<< endl;
	cout << "Name: " << emp2.getName()<<endl;
	cout << "ID Number: " << emp2.getidNumber()<<endl;
	cout << "Department: " << emp2.getDepartment()<<endl;
	cout << "Position: " << emp2.getPosition()<<endl;
	cout <<endl;
	
	cout << "Employee#3:"<< endl;
	cout << "Name: " << emp3.getName()<<endl;
	cout << "ID Number: " << emp3.getidNumber()<<endl;
	cout << "Department: " << emp3.getDepartment()<<endl;
	cout << "Position: " << emp3.getPosition()<<endl;
	cout <<endl;
	
	emp1.setName("Faraz");
	emp1.setidNumber(780);
	emp1.setDepartment("Data Science");
	emp1.setPosition("Deen");
	
	emp2.setName("Shoaib");
	emp2.setidNumber(973);
	emp2.setDepartment("FinTech");
	emp2.setPosition("Lecturer");
	
	cout << "Employee#1:"<< endl;
	cout << "Name: " << emp1.getName()<<endl;
	cout << "ID Number: " << emp1.getidNumber()<<endl;
	cout << "Department: " << emp1.getDepartment()<<endl;
	cout << "Position: " << emp1.getPosition()<<endl;
	cout <<endl;
	
	cout << "Employee#2:"<< endl;
	cout << "Name: " << emp2.getName()<<endl;
	cout << "ID Number: " << emp2.getidNumber()<<endl;
	cout << "Department: " << emp2.getDepartment()<<endl;
	cout << "Position: " << emp2.getPosition()<<endl;
	cout <<endl;
	
	cout << "Employee#3:"<< endl;
	cout << "Name: " << emp3.getName()<<endl;
	cout << "ID Number: " << emp3.getidNumber()<<endl;
	cout << "Department: " << emp3.getDepartment()<<endl;
	cout << "Position: " << emp3.getPosition()<<endl;
	cout <<endl;
	
	return 0;
}
