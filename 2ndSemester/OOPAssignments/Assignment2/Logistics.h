#pragma once
#include <iostream>
#include <string>
#include <vector>
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
    string assignedAssetID;     // links to a TransportAsset

    static int globalActiveShipments;


public:
    static void renderGlobalDashboard() {


    }






};

class CargoCrate
{
private:
    int crateID;
    string contentsDescription;
    double weightKg;
    string fragileFlag;             // "FRAGILE", "STANDARD" - for CustomsAuditor
    string hamzatCode;              // "NONE", "FLAMMABLE", "BIOLOGICAL"  - for CustomsAuditor
    string originCountry;           // - for CustomsAuditor


public:
    CargoCrate operator+(const CargoCrate& other) const { //Not sure if this is right, check its syntax later

    }

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






};
