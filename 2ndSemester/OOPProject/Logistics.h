#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class ShipmentOrder
{
private:
    const int orderID;
    string originNode;
    string destinationNode;
    double totalWeightKg;
    string priorityLevel;       // "STANDARD", "EXPRESS", "CRITICAL"
    string status;              // "PENDING", "IN_TRANSIT, "DELIVERED"
    string cargoType;           // "GENERAL", "PERISHABLE", "HAZARDOUS"
    bool isInternational;       // triggers CustomsAuditor
    int assignedAssetID;     // links to a TransportAsset

    static int globalActiveShipments;


public:
    ShipmentOrder(string oN, string dest, double Tw, string pL, string stat, string type, bool isInt, int AID);
    static void renderGlobalDashboard(); //definition in cpp

    ~ShipmentOrder();



};

class CargoCrate
{
private:
    int crateID;
    string contentsDescription;
    double weightKg;
    string fragileFlag;             // "FRAGILE", "STANDARD" - for CustomsAuditor
    string hamzatCode;              // "NONE", "FLAMMABLE", "BIOLOGICAL", "RADIOACTIVE"  - for CustomsAuditor
    string originCountry;           // - for CustomsAuditor


public:
    CargoCrate(int ID, string cD, double W, string fF, string ham, string country);
    double getWeight() const;
    stirng getHamzat() const;
    string getFragileFlag() const;
    CargoCrate operator+(const CargoCrate& other) const;
    //Not sure if this is right, check its syntax later
    //definition in cpp

};

class CustomsAuditor
{
private:
    int auditorID;
    string auditorName;
    string jurisdiction;
    string bannedHamzatCodes[10];   // For CargoCrate, or others
    double tariffRatePercent;


    friend class ShipmentOrder;

public:
CustomsAuditor(int ID, string name, string jurs, string ban, double trump);



};
