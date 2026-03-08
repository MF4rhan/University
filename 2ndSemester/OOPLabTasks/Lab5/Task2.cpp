#include <iostream>
#include <string>
using namespace std;
class Passenger;
class Flight;
class Time
{
int hour, minute;
public:
	Time(int h, int m): hour(h), minute(m) {}
	int getHour() const {return hour;}
	int getMinute() const {return minute;}
	void setHour(int h) {hour=h;}
	void setMinute(int m) {minute=m;}

	void PrintTime()
	{
		cout<<hour<<":"<<minute<<endl;
	}
};

class Flight
{
	string flightNo;
	Time departureTime;
	Passenger** passengers;
	int passengerCount;
	int capacity;
public:
	Flight(string fno, Time t, int c): flightNo(fno), departureTime(t), capacity(c), passengerCount(0) 
		{passengers = new Passenger*[capacity];}
	~Flight()	{delete[] passengers;}

	string getFlightNo() const {return flightNo;}
	void setFlightNo(string fno) {flightNo=fno;}
	void getDepartureTime() {departureTime.PrintTime();}
	void ShowFlightTime()
	{
		cout << "Flight Number: " << flightNo<< endl;
		cout <<"Departure Time:";
		getDepartureTime();
	}
	void addPassenger(Passenger* p) 
	{passengers[passengerCount]=p; passengerCount++;}

	void showPassengers() const;
};

class Passenger
{
	string name;
	int age;
public:
	Passenger(string n, int a): name(n), age(a) {}
	string getName() const {return name;}
	int getAge() const {return age;}
	void setName(string n)	{name=n;}
	void setAge(int a)	{age=a;}

	void bookFlight(Flight&f)
	{

		f.addPassenger(this);
		cout << "Passenger: "<< name << " has booked Flight " << f.getFlightNo() << endl;
	}
};

void Flight::showPassengers() const
{
	cout << "Passenger List for Flight: " << flightNo <<endl;
	for (int i = 0; i < passengerCount; ++i)
	{
		cout << i+1 << "- Name: " << passengers[i]->getName() << ", Age: " << passengers[i]->getAge() << endl;
	}
}

int main() {

    Time t1(14, 45);
    
    Flight f1("PK101", t1, 5);
    
    f1.ShowFlightTime();
    
    //creating passengers
    Passenger* p1 = new Passenger("Alice", 25);
    Passenger* p2 = new Passenger("Bob", 30);
    
    p1->bookFlight(f1);
    p2->bookFlight(f1);
    
    f1.showPassengers();
    
    //clean
    delete p1;
    delete p2;
    
    return 0;
}
