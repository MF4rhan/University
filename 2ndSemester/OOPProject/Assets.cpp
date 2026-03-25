#include "Assets.h"
#include "Logistics.h"
using namespace std;

//TransportAssets stuff
TransportAsset::TransportAsset(int id, double maxload, double load, string name, string status, string depot)
:assetID(id), maxPlayLoadWeight(maxload), currentLoad(load), assetName(name), operationalStatus(status), homeDepot(depot)   {}

//Ground Transport stuff
GroundTransport::GroundTransport(int id, double maxload, double load, string name, string status, string depot, string plate, double speed, string level, double fuel)
:TransportAsset(id, maxload, load, name, status, depot), licensePlate(plate), speedKmph(speed), roadClearanceLevel(level), fuelLevel(fuel)  {}

double GroundTransport::calculateTransitTime(double distance) const override
{
    //logic later
}

GroundTransport& GroundTransport::operator+(const CargoCrate& crate)
{
    if (currentLoad + crate.getWeight() > maxPayLoadWeight) {
        // throw PayloadExceededException("Ground vehicle payload exceeded!");
    }
    currentLoad += crate.getWeight();
    return *this;
}

//Air Transport stuff

AirTransport::AirTransport(int id, double maxload, double load, string name, string status, string depot, string num, double alt, double speed, int range, bool runway)
:TransportAsset(id, maxload, load, name, status, depot), tailNumber(num), cruiseAltitudeM(alt), airSpeedKmph(speed), maxFlightRangeKm(range), requiresRunway(runway)    {}

double AirTransport::calculateTransitTime(double distance) const
{
    //logic later
}

AirTransport& AirTransport::operator+(const CargoCrate& crate)
{
    if (crate.getHamzat() != "NONE")
    {
        // throw PayloadExceededException("Hamzat cargo rejected - air transport restriction!");
    }
    if (currentLoad + crate.getWeight() > maxPayLoadWeight)
    {
        // throw PayloadExceededException("Air transport payload exceeded!");
    }
    currentLoad += crate.getWeight();
    return *this;
}

//HeavyLiftDrone stuff
HeavyLiftDrone::HeavyLiftDrone(int id, double maxload, double load, string name, string status, string depot, string plate, double Gspeed, string level, double fuel, string num, double alt, double Aspeed, int range, bool runway, string Dmodel, double battery, bool auton, int hover, double HDGspeed, double HDAspeed)
:TransportAsset(id, maxload, load, name, status, depot), GroundTransport(id, maxload, load, name, status, depot, plate, Gspeed, level, fuel), AirTransport(id, maxload, load, name, status, depot, num, alt, Aspeed, range, runway), droneModel(Dmodel), isAutonomous(auton), maxHoverTimeMinutes(hover), urbanSpeedKmph(HDGspeed), aerialSpeedKmph(HDAspeed)  {}

double HeavyLiftDrone::calculateTransitTime(double distance) const
{
   //logic later
}

HeavyLiftDrone& HeavyLiftDrone::operator+(const CargoCrate& crate)
{
    if (crate.getHamzat() != "NONE")
    {
        // throw PayloadExceededException("Drone rejected hamzat - aerial safety rule");
    }
    if (crate.getWeight() > 50.0)
    {
        // throw PayloadExceededException("Single crate too heavy for drone!");
    }
    if (currentLoad + crate.getWeight() > maxPayLoadWeight)
    {
        // throw PayloadExceededException("Drone payload exceeded!");
    }
    currentLoad += crate.getWeight();
    return *this;
}

//Water Transport stuff
WaterTransport::WaterTransport(int id, double maxload, double load, string name, string status, string depot, string Rnum, double knots, string type, double draught, int maxcrew, string portreg, bool ocean)
:TransportAsset(id, maxload, load, name, status, depot), vesselRegistrationNumber(Rnum), speedKnots(knots), vesselType(type), draughtMeters(draught), maxCrewCapacity(maxcrew), portOfRegistry(portreg), isOceanGoing(ocean)    {}

double WaterTransport::calculateTransitTime(double distance) const
{
    //logic later
}

WaterTransport& WaterTransport::operator+(const CargoCrate& crate)
{
    if (crate.getFragileFlag() == "FRAGILE") {
        // throw PayloadExceededException("Fragile cargo rejected - water transport restriction!");
    }
    if (currentLoad + crate.getWeight() > maxPayLoadWeight) {
        // throw PayloadExceededException("Water transport payload exceeded!");
    }
    currentLoad += crate.getWeight();
    return *this;
}
