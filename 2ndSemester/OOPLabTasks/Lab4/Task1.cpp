#include <iostream>
#include <string>
using namespace std;

class Student 
{
	string roll, name;
	float cgpa;
	static int count;
	public: 
	Student(): roll(""), name(""), cgpa(0.0) {count++;}
	Student(string r, string n, float c): roll(r), name(n), cgpa(c){count++;}
	int getCount() {return count;}
};

int Student::count=0;

void checking()
{
	Student obj4("126", "Talha", 3.34); //counted when the function is called
}

int main()
{
	Student obj1("123", "Farhan", 3.3); //counts
	Student obj2("124", "Faraz", 3.6); //counts
	if (obj1.getCount()>1)
	{
		Student obj3("125", "Jawwad", 2.97); //counts
	}
	checking();
	
	cout <<"The total count is: " << obj1.getCount()<< endl;
return 0;
}

