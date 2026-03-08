#include <iostream>
#include <string>
using namespace std;

class Student
{
	string name;
	int roll;
	string courses[10];
public:
	Student()
	{
		name = "N/A";
		roll = 0;
		for (int i = 0; i < 10; ++i)
		{
			courses[i] = "None";
		}
	}

};
