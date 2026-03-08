#include "VehicleCore.h"
#include <iostream>
using namespace std;

//constructors
VehicleCore::VehicleCore():
brand("Unspecified"), model("Unspecified"), modelYear(0), mileage(0), chassisNumber("Unknown"), engineCC(0) {}
VehicleCore::VehicleCore(string b, string m, int year, int mil, string chassis, int cc)
:brand(b), model(m), modelYear(year), mileage(mil), chassisNumber(chassis), engineCC(cc) {}
VehicleCore::VehicleCore(const VehicleCore& other)
:brand(other.brand), model(other.model), modelYear(other.modelYear), mileage(other.mileage), chassisNumber(other.chassisNumber), engineCC(other.engineCC)
{}

//getters
string VehicleCore::getBrand() const    { return brand;}
string VehicleCore::getModel() const    {return model;}
int VehicleCore::getModelYear() const   {return modelYear;}
int VehicleCore::getMileage() const {return mileage;}
string VehicleCore::getChassisNumber() const    {return chassisNumber;}
int VehicleCore::getEngineCC() const    {return engineCC;}

//setter
void VehicleCore::setMileage(int m) 
{
    if (m >= 0) 
        mileage = m;
}

//methods
int VehicleCore::calculateAge(int currentYear) const    {return currentYear-modelYear;} 

string VehicleCore::getConditionCategory() 
{
    if (mileage <= 10000 && mileage >= 0) return "Almost Brand New.";
    else if (mileage <= 30000 && mileage > 10000) return "Lightly Used.";
    else if (mileage <= 75000) return "Moderately Used.";
    else return "Heavily Used.";
}

void VehicleCore::displayCoreSpecs() const
{
    cout << "\t--Vehicle Core Specificatoins---"<<endl;
    cout<<"Brand:\t\t"<<brand<<endl;
    cout<< "Model:\t\t"<<model<<endl;
    cout<<"Model Year:\t\t"<<modelYear<<endl;
    cout<<"Mileage:\t\t"<<mileage<<endl;
    cout<<"Engine CC:\t\t"<<engineCC<<endl;
    cout <<"Chassis Number:\t\t"<<chassisNumber<<endl;
    cout<<"\n\n";
}

bool VehicleCore::isLocallyManufactured() 
{
    if (!chassisNumber.empty() && (chassisNumber[0] == 'P' || chassisNumber[0] == 'p'))
        return true;
    else
        return false; 
}