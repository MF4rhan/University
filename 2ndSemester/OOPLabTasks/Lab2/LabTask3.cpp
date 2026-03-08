#include <iostream>
#include <string>
using namespace std;

class Person
{
	string name;
	int age;
	bool male;
	string occupation;
	bool cook;
	
	public:
		void setName(string namo)
		{
			name = namo;
		}
		void setAge(int ageo)
		{
			age = ageo;
		}
		void setMale(bool gender)
		{
			male = gender;
		}
		void setOccupation(string occu)
		{
			occupation = occu;
		}
		void setCook(bool cooker)
		{
			cook = cooker;
		}
		
		string getName()
		{
			return name;
		}
		int getAge()
		{
			return age;
		}
		bool getMale()
		{
			return male;
		}
		string getOccupation()
		{
			return occupation;
		}
		bool getCook()
		{
			return cook;
		}
};

int main()
{
	Person p1, p2;
	p1.setName("Farhan");
	p1.setAge(19);
	p1.setMale(true);
	p1.setOccupation("Student");
	p1.setCook(false);
	
	cout << p1.getName()<< endl;
	cout << p1.getAge()<< endl;
	cout << p1.getMale()<< endl;
	cout << p1.getOccupation()<< endl;
	cout << p1.getCook()<< endl<<endl;
	
	p2.setName("Ayeshia");
	p2.setAge(20);
	p2.setMale(false);
	p2.setOccupation("Student");
	p2.setCook(true);
	
	cout << p2.getName()<< endl;
	cout << p2.getAge()<< endl;
	cout << p2.getMale()<< endl;
	cout << p2.getOccupation()<< endl;
	cout << p2.getCook()<< endl;

return 0;
}
