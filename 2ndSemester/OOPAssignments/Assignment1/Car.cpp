#include "Car.h"
#include <iostream>
using namespace std;

//constructors
Car::Car()
	:baseSpecs(), transmission("Manual"), hasSunroof(false), trunkCapacityLitres(0), assemblyType("Local") {}
Car::Car(string b, string m, int year, int mil, string chassis, int cc, string trans, bool sunroof, int trunk, string assembly) 
    : baseSpecs(b, m, year, mil, chassis, cc), transmission(trans), hasSunroof(sunroof), trunkCapacityLitres(trunk), assemblyType(assembly)	{}
Car::Car(const Car& other)
:baseSpecs(other.baseSpecs), transmission(other.transmission),hasSunroof(other.hasSunroof), trunkCapacityLitres(other.trunkCapacityLitres),
 assemblyType(other.assemblyType)   {}

//getters
VehicleCore Car:: getBaseSpecs() const	{return baseSpecs;}
    string Car::getTransmission() const	{return transmission;}
    bool Car::getHasSunroof() const	{return hasSunroof;}
    int Car::getTrunkCapacityLitres() const	{return trunkCapacityLitres;}
    string Car::getAssemblyType() const	{return assemblyType;}

//methods
string Car::generateListingTitle() 
    //to_string() is required to convert the integer year into text so we can generate a string only title 
{return to_string(baseSpecs.getModelYear()) + " " + baseSpecs.getBrand() + " " + baseSpecs.getModel() + " " + transmission;}

string Car::comparePerformance(Car otherCar) 
{
    int myCC = baseSpecs.getEngineCC();
    int otherCC = otherCar.getBaseSpecs().getEngineCC();

    if (myCC > otherCC)
    	return "This car is more powerful.";
    else if (myCC < otherCC)
    	return "The compared car is more powerful.";
    else
    	return "Both cars have equal engine performance.";
}

bool Car::checkTaxStatus(int currentYear) {
    int age = baseSpecs.calculateAge(currentYear);
    //rule: tax exempt if the car is older than 10 years or it's engine is smaller than 1000cc
    if (age > 10 || baseSpecs.getEngineCC() < 1000)
    	return true;
    else
    	return false; 
}

int Car::evaluateFamilySuitability()
{
    int score = 0;
    if (trunkCapacityLitres >= 400)	
    	score += 5;
    else if (trunkCapacityLitres >= 300)
    	score += 3;
    if (transmission == "Automatic" || transmission == "automatic")
        score += 3; 
    if (hasSunroof)
        score += 2;
    return score; 
}