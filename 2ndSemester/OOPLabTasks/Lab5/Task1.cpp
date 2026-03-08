#include <iostream>
#include <string>
using namespace std;
class Project;
class SwipeCard;
class Manager
{
	string name;
	double salary;
	Project* project; //This is Composition, because we are making a project object using DMA inside the Manager class.
public:
	Manager(string name, double salary);
	~Manager();
	string getName() const {return name;}
	void setSalary(double salary) {this->salary=salary;}
	double getSalary() const {return salary;}
	void setName(string name) {this->name=name;}
	void AssignProject();
	void Logon(SwipeCard& sc);
	//This is a Use-a connection or Dependency.
	//The Manager only uses the SwipeCard object temporarily and after using it, has no connection to it.
};

class SwipeCard
{
	string swipecardname;
public:
	SwipeCard(string swipecardname) {this->swipecardname=swipecardname;}
	string getName() const {return swipecardname;}
	void setName(string name) {this->swipecardname=name;}
	void swipe(Manager& m) 
	{
		cout<<"Manager with Name: "<<m.getName()<< " Has logged on to the system."<<endl;
	}
};

class Project
{
	string name;
	Manager* manager;
public:
	Project(string name,Manager* manager)
	{
		this->manager=manager;
		this->name=name;
	}
	void increaseSalary() 
	{
	manager->setSalary(manager->getSalary()+1);
	}
};

void Manager::Logon(SwipeCard& sc) {sc.swipe(*this);}
void Manager::AssignProject()  {this->project->increaseSalary();}

//constructor defined here, otherwise it wouldnt run inside the Manager Class due to C++ compiler.
//because by the time it executes the constructor, it doesnt know what the project class is.
Manager::Manager(string name, double salary) 
{
	this->name=name;
	this->salary=salary;
	this->project= new Project("Nova",this); //This is Composition.
}
//Destructor defined here, otherwise it wouldnt run inside the Manager Class due to C++ compiler.
//because by the time it executes the destructor, it doesnt know what the project class is.
Manager::~Manager() 
{
    delete this->project;
}


int main()
{
	Manager Boss("Ali", 60000);
	SwipeCard Card("Ali Card");
	Boss.Logon(Card);
	
	cout << "Salary Before assigning project: $" << Boss.getSalary() << endl;
	
	Boss.AssignProject();
	
	cout << "Salary After assigning project:  $" << Boss.getSalary() << endl;

return 0;
}