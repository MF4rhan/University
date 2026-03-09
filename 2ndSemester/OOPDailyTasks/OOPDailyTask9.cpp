#include <iostream>
#include <string>
using namespace std;

class Donations
{
	float cash_donations;
	int food_donations, clothing_donations;
public:
	Donations():cash_donations(0), food_donations(0), clothing_donations(0)	{}

	void add_donation(string type, float amount, string donor="Anonymous")
	{
		if (type=="Cash")
			cash_donations+=amount;
		else if (type=="Food")
			food_donations+=amount;
		else if (type=="Clothing")
			clothing_donations+=amount;
		else
			{cout<<"Invalid Donation Type. Try again.\n"<<endl;	return;}
		cout<<"Donation was successfully made by " <<donor<<endl;
	}

	void print_donations()
	{
		cout<<"\nCash Donations:\t\t"<<cash_donations<<endl;
		cout<<"Food Donations:\t\t"<<food_donations<<endl;
		cout<<"Clothing Donations:\t"<<clothing_donations<<endl;
	}
};

int main()
{
	Donations d1;
	d1.add_donation("Clothing", 5);
	d1.add_donation("Cash", 5000, "Farhan");
	d1.add_donation("Food", 10, "Evelyne");

	d1.print_donations();
return 0;
}