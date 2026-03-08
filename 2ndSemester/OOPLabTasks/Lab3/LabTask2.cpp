#include <iostream>
#include <string>
using namespace std;

class Student
{
	string stdID, stdName, dept;
	public:
		Student(): stdID(""), stdName(""), dept("") {}
		
		Student(string ido, string nam): stdID(ido), stdName(nam) {}
		
		Student(string ido, string nam, string dep)
		:stdID(ido), stdName(nam), dept(dep) {}
		
		Student(string nam, string dep, bool dummy)
		:stdName(nam), dept(dep) {}
		
		void setData() 
		{
		cout << "--- User Input for Student ---" << endl;
        cout << "Enter ID: "; 
        cin >> this->stdID;
        cout << "Enter Name: "; 
        cin >> this->stdName;
        cout << "Enter Dept: "; 
        cin >> this->dept;
		}
		
		void displayData() 
		{
	    cout << "--- Student Record ---" << endl;
	    cout << "ID:   " << this->stdID << endl;
	    cout << "Name: " << this->stdName << endl;
	    cout << "Dept: " << this->dept << endl;
	    cout << "----------------------" << endl;
	    cout <<endl;
		}
	~Student() 
	{
    cout << "Destructor called for Student: " << this->stdName << endl;
	}
};

int main()
{
	//local objects
	Student obj1, obj2("12345", "Ali Hassan"), obj3("23456", "Sheeraz Depp", "Computer Science");
	Student obj4(obj3);
	//dynamic objects
	Student* s1= new Student("111", "Riley Victoria", "FinTech");
	Student* s2= new Student("222", "Alex Wilson", "Electrical Engineering");
	Student* s3= new Student("333", "Erika", "Accounting and Finance");
	
	//displaying everything
	obj1.displayData();
	obj2.displayData();
	obj3.displayData();
	obj4.displayData();
	
	s1->displayData();
	s2->displayData();
	s3->displayData();
	
	obj1.setData();
    obj1.displayData();
	
	//calling destructors
	delete s1;
	delete s2;
	delete s3;
	obj1.~Student();
	obj2.~Student();
	obj3.~Student();
	obj4.~Student();
	
	return 0;
}
