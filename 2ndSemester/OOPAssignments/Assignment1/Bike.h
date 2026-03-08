#pragma once
#include <string>
#include "VehicleCore.h"
using namespace std;

class Bike 
{
private:
    VehicleCore baseSpecs;  //composition
    string bikeType;       //sports, cruiser, commuter, cafe racer, or whatever else.
    float dryWeightKg;
    bool hasDiscBrakes;
    string coolingSystem;  //air cooled or liquid cooled

public:
    //constructors
    Bike();
    Bike(string b, string m, int year, int mil, string chassis, int cc, string type, float weight, bool disc, string cooling);
    Bike(const Bike& other);
    
    //getters
    VehicleCore getBaseSpecs() const;
    string getBikeType() const;
    float getDryWeightKg() const;
    bool getHasDiscBrakes() const;
    string getCoolingSystem() const;

    //methods
    string generateListingTitle();
    string requiresLicenseCategory();
    float calculatePowerToWeightRatio();
    int evaluateCommuterSuitability();
};