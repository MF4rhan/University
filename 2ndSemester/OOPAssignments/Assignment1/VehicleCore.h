#pragma once
#include <string>

using namespace std;

class VehicleCore {
private:
    string brand;
    string model;
    int modelYear;
    int mileage;
    const string chassisNumber;
    int engineCC;

public:
    // constructors
    VehicleCore(); 
    VehicleCore(string b, string m, int year, int mil, string chassis, int cc); 
    VehicleCore(const VehicleCore& other);
    
    // getters
    string getBrand() const;
    string getModel() const;
    int getModelYear() const;
    int getMileage() const;
    string getChassisNumber() const; 
    int getEngineCC() const;

    // setter
    void setMileage(int m);

    // methods
    int calculateAge(int currentYear) const; 
    string getConditionCategory();
    void displayCoreSpecs() const;
    bool isLocallyManufactured();
};