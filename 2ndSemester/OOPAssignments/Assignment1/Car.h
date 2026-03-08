#pragma once
#include <string>
#include "VehicleCore.h"

using namespace std;

class Car {
private:
    VehicleCore baseSpecs;  //composition
    string transmission;
    bool hasSunroof;
    int trunkCapacityLitres;
    string assemblyType;

public:
    //constructors
    Car();
    Car(string b, string m, int year, int mil, string chassis, int cc, string trans, bool sunroof, int trunk, string assembly);
    Car(const Car& other);
    
    // getters (we need all for later when we post it on AdListings)
    VehicleCore getBaseSpecs() const;
    string getTransmission() const;
    bool getHasSunroof() const;
    int getTrunkCapacityLitres() const;
    string getAssemblyType() const;

    //no setters, cause once the ad is posted, you cannot change it

    //methods
    string generateListingTitle();
    string comparePerformance(Car otherCar);
    bool checkTaxStatus(int currentYear);
    int evaluateFamilySuitability();
};