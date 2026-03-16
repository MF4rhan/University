#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class TransportAsset
{
protected:
    const int assetID;          // an ID for the vehicle
    double maxPlayLoadWeight;   // max weight capacity of that vehicle
    double currentLoad;         // the current load
    string assetName;           // the name of the vehicle
    string operationalStatus;   // maintainance, or working , or retired, etc.
    string homeDepot;           // where the home/base of the vehicle is

public:
    //pure virtual function
    virtual double calculateTransitTime(double distance) const = 0;
    //more methods later





};


class GroundTransport: virtual public TransportAsset
{
protected:
    string licensePlate;        // license plate for customs audit later prob
    double speedKmph;           // average speed, probably used for transit time later
    string roadClearanceLevel;  // local, highway, offroad, water etc
    double fuelLevel;           // from 1-100 pc


public:
    double calculateTransitTime(double distance) const override {}



};

class AirTransport: virtual public TransportAsset
{
protected:
    string tailNumber;          // aircraft registration
    double cruiseAltitudeM;     // in meters
    double airSpeedKmph;        // in kmph
    int maxFlightRangeKm;       // max range in km
    bool requiresRunway;        // false for drones/VTOL

public:
    double calculateTransitTime(double distance) const override {}


};

class HeavyLiftDrone: public GroundTransport, public AirTransport
{
private:
    string droneModel;
    double batteryLevel;       // from 1-100 pc
    bool isAutonomous;         // always true, but still good to flag anyway
    int maxHoverTimeMinutes;   // minutes time before it dies
    double urbanSpeedKmph;     // slower in city corridors
    double aerialSpeedKmph;    // open-air speed


public:
    double calculateTransitTime(double distance) const override {}





};

class WaterTransport
{
private:
    string vesselRegistrationNumber;
    double speedKnots;              // water speed in knots, cuz thats what ships use
    string vesselType;              // cargo ship or ferry or barge, etc
    double draughtMeters;           // how deep it sits in water
    int maxCrewCapacity;
    string portOfRegistry;          // home port
    bool isOceanGoing;              // false = river/canal only


public:



};
