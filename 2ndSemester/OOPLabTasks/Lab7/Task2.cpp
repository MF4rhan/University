#include <iostream>
#include <string>
using namespace std;

class Shipment
{
protected:
	static int counter;
	const int shipmentID;
	float weight;
public:
	Shipment(float w): weight(w), shipmentID(counter++)	{}

	float virtual calculateCost()	{return 0.0;}
};

class StandardDelivery:public Shipment
{
public:
	StandardDelivery(float w): Shipment(w)	{}

	float calculateCost()	{return weight*5;}
};

class ExpressDelivery: public Shipment
{
public:
	ExpressDelivery(float w): Shipment(w)	{}

	float calculateCost()	{return (weight*8.0)+50;}
};

class InternationalDelivery: public Shipment
{
	public:
	InternationalDelivery(float w): Shipment(w)	{}

	float calculateCost()	{return (weight*12.0)+100;}
};

int Shipment::counter=0;

int main()
{
	Shipment* Array[3];
	StandardDelivery normal(20);
	ExpressDelivery fast(20);
	InternationalDelivery global(20);

	Array[0] = &normal;
	Array[1] = &fast;
	Array[2] = &global;

	for (int i = 0; i < 3; ++i)
	{
		cout<<"Shipement #"<<i+1<<" Cost:\t"<<Array[i]->calculateCost()<<endl<<endl;
	}

	return 0;
}