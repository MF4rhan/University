#include <iostream>
#include <string>
using namespace std;

class VehicleInfo
{
	static int count;
	int ID;
	string modelName;
	public:
	VehicleInfo(string n=""):modelName(n), ID(count)	{count++;}
	int getID()	{return ID;}
	string getName()	{return modelName;}
};

class RentalInfo
{
	int rentalPricePerDay;
	bool availabilityStatus;
public:
	RentalInfo(int r, bool s):rentalPricePerDay(r), availabilityStatus(s)	{}
	void setRentalPrice(int r)	{rentalPricePerDay=r;}
	void setAvailabilityStatus(int s)	{availabilityStatus=s;}
	int getRentalPrice() const	{return rentalPricePerDay;}
	bool getAvaliability() const	{return availabilityStatus;}
};

class RentalVehicle: public VehicleInfo, public RentalInfo
{
	double TotalRentCost;
	int numberOfDays;
public:	RentalVehicle(int nD, string name, int rentDay, bool status):
	VehicleInfo(name), RentalInfo(rentDay, status), numberOfDays(nD), TotalRentCost(0)	{}

	void setNumberOfDays(int s)	{numberOfDays=s;}
	void DisplayDetails()
	{
		TotalRentCost=numberOfDays * getRentalPrice();
		cout <<"Vehicle ID: "<<getID()<< "\t Model Name: "<<getName() <<endl;
		cout <<"Status: "<< (getAvaliability()?"Avalaible":"Unavalaible" )<< endl;
		cout <<"Rent Per Day: "<< getRentalPrice()<<endl;
		cout <<"Total Rent: "<< TotalRentCost<<endl;
	}
};

int VehicleInfo::count = 0;

int main()
{
	RentalVehicle Car(7, "Corolla", 2000, true);
	Car.DisplayDetails();
	return 0;
}