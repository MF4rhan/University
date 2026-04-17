#pragma once
#include <string>
#include <iostream>
using namespace std;

// below is the Abstract base class for the base attributes shared across all other derived classes
class Vehicle
{
protected:
    string brand;
    string model;
    int modelYear;
    int mileage;
    string chassisNumber;
    int engineCC;

public:
    Vehicle();
    Vehicle(string b, string m, int year, int mil, string chassis, int cc);
    virtual ~Vehicle(); // virtual destructor to properly manage memory

    string getBrand() const;
    string getModel() const;
    int getModelYear() const;
    int getMileage() const;
    string getChassisNumber() const;
    int getEngineCC() const;
    void setMileage(int m);

    int calculateAge(int currentYear) const;
    string getConditionCategory() const;
    bool isLocallyManufactured() const;

    // pure virtual function
    virtual void displaySpecs() const = 0;
    virtual void print(ostream& os) const = 0; // used as a virtual print function

    // operator overloading, compares chassis to find identical vehicles
    bool operator==(const Vehicle& other) const;

    friend ostream& operator<<(ostream& os, const Vehicle& v);
};

// derived class Car
class Car : public Vehicle
{
private:
    string transmission;
    bool hasSunroof;
    int trunkCapacityLitres;
    string assemblyType;

public:
    Car();
    Car(string b, string m, int year, int mil, string chassis, int cc, string trans, bool sunroof, int trunk, string assembly);

    void displaySpecs() const override;

    string getTransmission() const;
    bool getHasSunroof() const;
    int getTrunkCapacityLitres() const;
    string getAssemblyType() const;

    string comparePerformance(const Car& otherCar) const;
    bool checkTaxStatus(int currentYear) const;
    int evaluateFamilySuitability() const;

    // global operator overloading using fren function
    void print(ostream& os) const override;
};

// Derived class Bike
class Bike : public Vehicle
{
private:
    string bikeType;
    float dryWeightKg;
    bool hasDiscBrakes;
    string coolingSystem;

public:
    Bike();
    Bike(string b, string m, int year, int mil, string chassis, int cc, string type, float weight, bool disc, string cooling);

    void displaySpecs() const override;

    string getBikeType() const;
    float getDryWeightKg() const;
    bool getHasDiscBrakes() const;
    string getCoolingSystem() const;

    string requiresLicenseCategory() const;
    float calculatePowerToWeightRatio() const;
    int evaluateCommuterSuitability() const;

    // global operator overloading using fren function
    void print(ostream& os) const override;
};

// Derived class CommercialTruck
class CommercialTruck : public Vehicle
{
private:
    float payloadCapacityTons;
    int axleCount;

public:
    CommercialTruck();
    CommercialTruck(string b, string m, int year, int mil, string chassis, int cc, float payload, int axles);

    void displaySpecs() const override;

    // global operator overloading using fren function
    void print(ostream& os) const override;
};

// derived class Van
class Van : public Vehicle
{
private:
    int seatingCapacity;
    bool isHighRoof;

public:
    Van();
    Van(string b, string m, int year, int mil, string chassis, int cc, int seats, bool highRoof);

    void displaySpecs() const override;
    void print(ostream& os) const override;
};

// derived class Bus
class Bus : public Vehicle
{
private:
    int passengerCapacity;
    string routeType;

public:
    Bus();
    Bus(string b, string m, int year, int mil, string chassis, int cc, int capacity, string route);

    void displaySpecs() const override;
    void print(ostream& os) const override;
};
