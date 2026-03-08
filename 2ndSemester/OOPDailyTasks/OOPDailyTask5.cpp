//25K-0538, BCS-2K, M.Farhan
#include <iostream>
#include <string>
using namespace std;
class Party
{
	//attributes
	string venue;
	string date;
	int frens;
	double* payments;
public:
	//All constructors + destructor
	Party():venue(""), date(""),frens(0), payments(NULL) {}
	Party(string ven, string dat, int freno): venue(ven), date(dat), frens(freno) 
	{
		payments = new double[frens];
		for (int i = 0; i < frens; ++i)
		{
			payments[i]=0.0;
		}
	}
	Party(const Party& copy)
	{
		venue = copy.venue;
		date = copy.date;
		frens = copy.frens;
		payments = new double[frens];
		for (int i = 0; i < frens; ++i)
		{
			payments[i] = copy.payments[i];
		}
	}
	~Party()
	{
		delete[] payments;
	}
	//setters
	void set_payments() 
	{//This setter is in case you use parametrized Constructor to set all other values before hand.
		for (int i = 0; i < frens; ++i)
		{
			cout << "Enter Payment amount of friend #" << i+1<< ": "<< endl;
			cin >> payments[i];
		}
	}
	void set_Data()
	{//if you dont use parametrized constructor, you can use this one to set all values at once.
		cout << "Enter Name of Venue: "<<endl;
		cin>>venue;
		cout << "Enter Date: "<< endl;
		cin>>date;
		cout << "Enter number of Friends: "<< endl;
		cin >> frens;

		payments = new double[frens];
		for (int i = 0; i < frens; ++i)
		{
			cout << "Enter Payment amount of friend #" << i+1<< ": "<< endl;
			cin >> payments[i];
		}
	}
	//getters
	string getVenue() {return venue;}
	int getFrens() {return frens;}
};
//Global Function declarations
void findMostFriends(Party part[], int size);
Party getMostFriends(Party part[], int size);
void printParties(Party part[], int size);
//main
int main()
{
	Party part[12];
	for (int i = 0; i < 12; ++i)
	{
		part[i].set_Data();
	}
	findMostFriends(part, 12);
	Party p = getMostFriends(part, 12);
	cout << "The party with the highest number of friends attending is:"<< endl;
	cout << "Venue: "<< p.getVenue()<<endl;
	cout << "Total Attending: "<< p.getFrens()<<endl;
	printParties(part, 12);
return 0;
}

//Global Functions
void findMostFriends(Party part[],int size)
{
	int highest=0, index=0;
	for (int i=0; i < size; ++i)
	{
		if (part[i].getFrens()>highest)
		{
			highest=part[i].getFrens();
			index =i;
		}
	}
	cout<< "The Party with the Highest number of Friends attending is Party#" << index+1<< endl;
	cout << "Venue: "<< part[index].getVenue()<<endl;
	cout << "Total Attending: "<< part[index].getFrens()<<endl;
}

Party getMostFriends(Party part[],int size)
{
	int highest=0, index=0;
	for (int i = 0; i < size; ++i)
	{
		if (part[i].getFrens()>highest)
		{
			highest=part[i].getFrens();
			index =i;
		}
	}
	return part[index];
}

void printParties(Party part[],int size)
{
	cout << "The Parties with More than 5 friends attending are: "<< endl;
	for (int i = 0; i < size; ++i)
	{
		if (part[i].getFrens()>5)
		{
			cout << "Venue: "<< part[i].getVenue()<<endl;
		}
	}
}