#include "Vehicles.h"
#include <iostream>

using namespace std;

// Vehicle bass implementaton
Vehicle::Vehicle()
: brand("Unspecified"), model("Unspecified"), modelYear(0), mileage(0), chassisNumber("Unknown"), engineCC(0) {}

Vehicle::Vehicle(string b, string m, int year, int mil, string chassis, int cc)
: brand(b), model(m), modelYear(year), mileage(mil), chassisNumber(chassis), engineCC(cc) {}

Vehicle::~Vehicle() {}

string Vehicle::getBrand() const {return brand;}
string Vehicle::getModel() const {return model;}
int Vehicle::getModelYear() const {return modelYear;}
int Vehicle::getMileage() const {return mileage;}
string Vehicle::getChassisNumber() const {return chassisNumber;}
int Vehicle::getEngineCC() const {return engineCC;}

void Vehicle::setMileage(int m)
{
    if (m >= 0)
        mileage = m;
}

int Vehicle::calculateAge(int currentYear) const {return currentYear - modelYear;}

string Vehicle::getConditionCategory() const
{
    if (mileage <= 10000 && mileage >= 0)
        return "Almost Brand New.";
    if (mileage <= 30000)
        return "Lightly Used.";
    if (mileage <= 75000)
        return "Moderately Used.";

    return "Heavily Used.";
}

bool Vehicle::isLocallyManufactured() const
{
    return (!chassisNumber.empty() && (chassisNumber[0] =='P' || chassisNumber[0] =='p'));
}

bool Vehicle::operator==(const Vehicle& other) const
{
    return chassisNumber == other.chassisNumber;
}

ostream& operator<<(ostream& os, const Vehicle& v)
{
    v.print(os);
    return os;
}

// Car functions below
Car::Car() : Vehicle(), transmission("Manual"), hasSunroof(false), trunkCapacityLitres(0), assemblyType("Local") {}

Car::Car(string b, string m, int year, int mil, string chassis, int cc, string trans, bool sunroof, int trunk, string assembly)
: Vehicle(b, m, year, mil, chassis, cc), transmission(trans), hasSunroof(sunroof), trunkCapacityLitres(trunk), assemblyType(assembly) {}

void Car::displaySpecs() const {
    cout << "Car Specifications: " << modelYear << " " << brand << " " << model << "  " << engineCC << "cc  " << transmission << endl;
}

string Car::getTransmission() const {return transmission;}
bool Car::getHasSunroof() const {return hasSunroof;}
int Car::getTrunkCapacityLitres() const {return trunkCapacityLitres;}
string Car::getAssemblyType() const {return assemblyType;}

string Car::comparePerformance(const Car& otherCar) const
{
    if (engineCC > otherCar.getEngineCC())
        return "This car is more powerful.";
    if (engineCC < otherCar.getEngineCC())
        return "The compared car is more powerful.";

    return "Both cars have equal engine performance.";
}

bool Car::checkTaxStatus(int currentYear) const
{
    return (calculateAge(currentYear) > 10 || engineCC < 1000);
}

int Car::evaluateFamilySuitability() const
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

void Car::print(ostream& os) const
{
    os << "Car: " << brand << " " << model << " " << modelYear << endl
    << "Mileage: " << mileage << " km" << endl
    << "Transmission: " << transmission << endl
    << "Trunk: " << trunkCapacityLitres << "L" << endl;
}

// bike stuff below
Bike::Bike()
: Vehicle(), bikeType("Commuter"), dryWeightKg(0), hasDiscBrakes(false), coolingSystem("Air-Cooled") {}

Bike::Bike(string b, string m, int year, int mil, string chassis, int cc, string type, float weight, bool disc, string cooling)
: Vehicle(b, m, year, mil, chassis, cc), bikeType(type), dryWeightKg(weight), hasDiscBrakes(disc), coolingSystem(cooling) {}

void Bike::displaySpecs() const
{
    cout << "Bike Specifications: " << modelYear << " " << brand << " " << model << " " << engineCC << "cc \nType: " << bikeType << endl;
}

string Bike::getBikeType() const {return bikeType;}
float Bike::getDryWeightKg() const {return dryWeightKg;}
bool Bike::getHasDiscBrakes() const {return hasDiscBrakes;}
string Bike::getCoolingSystem() const {return coolingSystem;}

string Bike::requiresLicenseCategory() const
{
    return (engineCC <= 150) ? "Standard Motorcycle License Required." : "Heavy Bike License Required.";
}

float Bike::calculatePowerToWeightRatio() const
{
    if (dryWeightKg == 0)
        return 0;

    return engineCC / dryWeightKg;
}

int Bike::evaluateCommuterSuitability() const
{
    int score = 0;
    if (bikeType == "Commuter" || bikeType == "commuter")
        score += 4;
    if (dryWeightKg <= 120)
        score += 2;
    if (coolingSystem == "Air-Cooled")
        score += 4;

    return score;
}

void Bike::print(ostream& os) const
{
    os << "Bike: " << brand << " " << model << " " << modelYear << endl
    << "Type: " << bikeType << endl
    << "Engine: " << engineCC << "CC" << endl
    << "Cooling: " << coolingSystem;
}

// truck below
CommercialTruck::CommercialTruck() : Vehicle(), payloadCapacityTons(0), axleCount(2) {}

CommercialTruck::CommercialTruck(string b, string m, int year, int mil, string chassis, int cc, float payload, int axles)
: Vehicle(b, m, year, mil, chassis, cc), payloadCapacityTons(payload), axleCount(axles) {}

void CommercialTruck::displaySpecs() const
{
    cout << "Truck Specifications: " << modelYear << " " << brand << " " << model << " \nPayload: " << payloadCapacityTons << " Tons" << endl;
}

void CommercialTruck::print(ostream& os) const
{
    os << "Truck: " << brand << " " << model << " " << modelYear << endl
    << "Payload: " << payloadCapacityTons << " Tons"<< endl
    << "Axles: " << axleCount << endl;
}

// I have some free candy, get in the Van :)
Van::Van() : Vehicle(), seatingCapacity(0), isHighRoof(false) {}

Van::Van(string b, string m, int year, int mil, string chassis, int cc, int seats, bool highRoof)
: Vehicle(b, m, year, mil, chassis, cc), seatingCapacity(seats), isHighRoof(highRoof) {}

void Van::displaySpecs() const
{
    cout << "Van Specs: " << modelYear << " " << brand << " " << model << "  Seats: " << seatingCapacity << endl;
}

void Van::print(ostream& os) const
{
    os << "Van: " << brand << " " << model << " " << modelYear << endl
    << "Seats: " << seatingCapacity << endl
    << "High Roof: " << (isHighRoof ? "Yes" : "No") << endl;
}

// bus (no free candy here, maybe)
Bus::Bus() : Vehicle(), passengerCapacity(0), routeType("Local") {}

Bus::Bus(string b, string m, int year, int mil, string chassis, int cc, int capacity, string route)
: Vehicle(b, m, year, mil, chassis, cc), passengerCapacity(capacity), routeType(route) {}

void Bus::displaySpecs() const
{
    cout << "Bus Specs: " << modelYear << " " << brand << " " << model << "  Capacity: " << passengerCapacity << endl;
}

void Bus::print(ostream& os) const
{
    os << "Bus: " << brand << " " << model << " " << modelYear << endl
    << "Capacity: " << passengerCapacity << " passengers\n"
    << "Route: " << routeType << endl;
}
