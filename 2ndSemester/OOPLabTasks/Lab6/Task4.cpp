#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
	static int count;
	int ID;
	string modelName;
	public:
	Vehicle(string n=""):modelName(n), ID(count)	{count++;}
	int getID()	{return ID;}
	string getName()	{return modelName;}
	void displayVehicleInfo()
	{
		cout<< "Car ID:\t\t\t" << ID<<endl;
		cout << "Model Name:\t\t"<<modelName<<endl;
	}
};

class Car: virtual public Vehicle
{
	string carType;
	public:
	Car(string t, string n): Vehicle(n), carType(t)	{}
	void displayCarInfo()
	{
		displayVehicleInfo();
		cout<<"Car Type:\t\t"<<carType<<endl;
	}
	string getCarType() const	{return carType;}
};

class Truck: virtual public Vehicle
{
	int loadCapacity;
	public:
	Truck(int l, string n): Vehicle(n), loadCapacity(l)	{}
	void displayTruckInfo()
	{
		displayVehicleInfo();
		cout<<"Load Capacity (tons):\t"<<loadCapacity<<endl;
	}
	int getLoad() const	{return loadCapacity;}
};

class PickupTruck: public Car, public Truck
{
	//whatever additional attributes you want to add, question doesnt state any.
public:
	PickupTruck(string n, string t, int l):Vehicle(n), Car(t, n), Truck(l, n)	{}
	void displayPickupTruckInfo()
	{
		displayCarInfo();
		cout<<"Load Capacity (tons):\t"<<getLoad()<<endl;
	}
};

int Vehicle::count = 0;

int main()
{
	PickupTruck trucky("Hillux", "Pickup Truck", 2);
	trucky.displayPickupTruckInfo();
	return 0;
}