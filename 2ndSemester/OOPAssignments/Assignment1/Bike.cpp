#include "Bike.h"
#include <iostream>
using namespace std;

//constructors
Bike::Bike()
	:baseSpecs(), bikeType("commuter"), dryWeightKg(0), hasDiscBrakes(false), coolingSystem("Air-Cooled") {}
Bike::Bike(string b, string m, int year, int mil, string chassis, int cc, string bt, float dwk, bool db, string cs)
	:baseSpecs(b, m, year, mil, chassis, cc), bikeType(bt), dryWeightKg(dwk), hasDiscBrakes(db), coolingSystem(cs)	{}
Bike::Bike(const Bike& other)
:baseSpecs(other.baseSpecs), bikeType(other.bikeType), dryWeightKg(other.dryWeightKg), hasDiscBrakes(other.hasDiscBrakes),
 coolingSystem(other.coolingSystem) {}

	//getters
    VehicleCore Bike::getBaseSpecs() const  {return baseSpecs;}
    string Bike::getBikeType() const    {return bikeType;}
    float Bike::getDryWeightKg() const  {return dryWeightKg;}
    bool Bike::getHasDiscBrakes() const     {return hasDiscBrakes;}
    string Bike::getCoolingSystem() const   {return coolingSystem;}

	//methods
string Bike::generateListingTitle() 
    //to_string() is required to convert the integer year into text so we can generate a string only title 
{return to_string(baseSpecs.getModelYear()) + " " + baseSpecs.getBrand() + " " + baseSpecs.getModel() + " " + bikeType;}

string Bike::requiresLicenseCategory()
{
	if (baseSpecs.getEngineCC()<=150)
		return "Standard Motorcycle License Required.";
	else
		return "Heavy Bike License Required.";
}

float Bike::calculatePowerToWeightRatio()
{return baseSpecs.getEngineCC()/dryWeightKg;}

int Bike::evaluateCommuterSuitability()
{
    int score = 0;
    if (bikeType=="Commuter" || bikeType=="commuter")
    	score+=4;
    if (dryWeightKg<=120)
    	score+=2;
    if (coolingSystem=="Air-Cooled")
    	score+=4;
    return score; 
}
