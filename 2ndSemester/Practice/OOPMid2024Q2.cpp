#include <iostream>
#include <string>
using namespace std;

class Astronaut
{
	string name, expertise;
	bool status;

public:
Astronaut(string n="", string e="", bool s=true): name(n), expertise(e), status(s) {}
};


class Spaceship
{
	const string name;
	int capacity;
	bool status;

public:
	Spaceship(string n="n/a", int c=3, bool s=true): name(n), capacity(c), status(s) {}
	bool getStatus() const	{return status;}
	int getCapacity() const	{return capacity;}
};

class Mission
{
	const string name;
	string missionreq, duration, destination;
	Spaceship* ship;
	int astcount, astmax;
	Astronaut* asts;
public:
	Mission(string n="n/a", string mr="none", string d="0", string dest="n/a"): name(n), missionreq(mr), duration(d), destination(dest), ship(nullptr), asts(nullptr), astcount(0), astmax(0) {}
	~Mission()	{delete[] asts;}
	void assignShip(Spaceship* s)
	{
		if (s->getStatus())
		{
			ship =s;
			astmax=s->getCapacity();
			asts = new Astronaut[astmax];
		}
		else
		{
			cout << "This Spaceship is unavaliable for Mission."<< endl;
		}
	}

	void addAstonaut(Astronaut* a)
	{
		if (asts==nullptr)
		{
			cout<<"Error: No Ship as been Assignment, Please Assign a Ship first."<< endl;
			return;
		}
		if (astcount<astmax)
		{
			asts[astcount]= (*a);
			astcount++;
		}
		else
		{
			cout <<"Astronaut Capacity is full."<<endl;
		}
	}
};