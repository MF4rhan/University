#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string model_name;
    double rental_rate;
public:
    Vehicle(string name, double rate) : model_name(name), rental_rate(rate)
    {
    }

    virtual double get_daily_rate() = 0;

    virtual void display_details() = 0;
};

class Car: public Vehicle
{
public:
    Car(string name, double rate) : Vehicle(name, rate)
    {
    }

    double get_daily_rate() override
    {
        return rental_rate;
    }

    void display_details() override
    {
        cout << "Vehicle Class: Car" << endl;
        cout << "Model Name: " << model_name << endl;
        cout << "Rental Rate: " << rental_rate << endl << endl;
    }
};

class Bike: public Vehicle
{
public:
    Bike(string name, double rate) : Vehicle(name, rate)
    {
    }

    double get_daily_rate() override
    {
        return rental_rate;
    }

    void display_details() override
    {
        cout << "Vehicle Class: Bike" << endl;
        cout << "Model Name: " << model_name << endl;
        cout << "Rental Rate: " << rental_rate << endl << endl;
    }
};

int main()
{
    //making objects
    Car car1("Toyota Corolla", 2000);
    Bike bike1("Honda CD70", 400);

    //Car method calls below
    cout << "Car Daily Rental Rate: " << car1.get_daily_rate() << endl;
    car1.display_details();

    //Bike method calls below
    cout << "Bike Daily Rental Rate: " << bike1.get_daily_rate() << endl;
    bike1.display_details();

    return 0;
};
