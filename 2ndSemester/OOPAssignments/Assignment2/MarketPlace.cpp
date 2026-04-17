#include "MarketPlace.h"
#include <iostream>

using namespace std;

// constructor and destructor for the marketplace
Marketplace::Marketplace()
: systemName("PakWheels OOP"), platformAdmin(nullptr), maxCapacity(100), listingCount(0), userCount(0)
{
    for (int i = 0; i < 100; i++)
    {
        allListings[i] = nullptr;
        platformUsers[i] = nullptr;
    }
}

Marketplace::Marketplace(string name, const Admin* admin, int capacity)
: systemName(name), platformAdmin(admin), maxCapacity(capacity), listingCount(0), userCount(0)
{
    for (int i = 0; i < 100; i++)
    {
        allListings[i] = nullptr;
        platformUsers[i] = nullptr;
    }
}

Marketplace::~Marketplace()
{
    // cleaning up dynamic arrays to prevent memory leaks
    for (int i = 0; i < listingCount; i++)
        delete allListings[i];
    for (int i = 0; i < userCount; i++)
        delete platformUsers[i];
}

string Marketplace::getSystemName() const {return systemName;}
int Marketplace::getListingCount() const {return listingCount;}
int Marketplace::getUserCount() const {return userCount;}
const Admin* Marketplace::getAdmin() const {return platformAdmin;}

//operator overloadings
Marketplace& Marketplace::operator+=(User* newUser)
{
    if (userCount >= maxCapacity)
    {
        cout << "System Error: Cannot register more users. Capacity reached." << endl;
        return *this;
    }
    platformUsers[userCount++] = newUser;
    cout << "User '" << newUser->getName() << "' successfully registered to the platform." << endl;
    return *this;
}

Marketplace& Marketplace::operator+=(ListingBase* newListing)
{
    if (listingCount >= maxCapacity)
    {
        cout << "System Error: Marketplace listing capacity reached." << endl;
        return *this;
    }
    allListings[listingCount++] = newListing;
    cout << "Listing successfully posted to the marketplace." << endl;
    return *this;
}

// function overloading
void Marketplace::search(string brand, int minYear) const
{
    cout << "\n Searching for Brand: " << brand << "  Minimum Year: " << minYear << endl;
    bool found = false;
    for (int i = 0; i < listingCount; i++)
    {
        Vehicle* v = allListings[i]->getVehicleItem();
        if (v->getBrand() == brand && v->getModelYear() >= minYear)
        {
            cout << *(allListings[i]) << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No listings found matching criteria." << endl;
}
void Marketplace::search(string brand) const
{
    cout << "\n Searching for Brand: " << brand << endl;
    bool found = false;
    for (int i = 0; i < listingCount; i++)
    {
        if (allListings[i]->getVehicleItem()->getBrand() == brand)
        {
            cout << *(allListings[i]) << endl; // uses overloaded << operator from Listings
            found = true;
        }
    }
    if (!found)
        cout << "No listings found for brand: " << brand << endl;
}

void Marketplace::filterByLocation(string city) const
{
    cout << "\n Listings in: " << city << endl;
    bool found = false;
    for (int i = 0; i < listingCount; i++)
    {
        if (allListings[i]->getListingLocation() == city)
        { //filtering
            cout << *(allListings[i]) << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No listings found in: " << city << endl;
}

// standard methods
double Marketplace::getTotalPlatformValue() const
{
    double total = 0;
    for (int i = 0; i < listingCount; i++)
    {
        total += allListings[i]->getAskingPrice();
    }
    cout << "Total Platform Asset Value: " << total << " PKR" << endl;
    return total;
}

void Marketplace::displayMarketplaceRules()
{
    cout << "===== Marketplace Rules =====" << endl;
    cout << "1. All listings must be approved by Admin before going live." << endl;
    cout << "2. Sellers must provide accurate vehicle information." << endl;
    cout << "3. Buyers are responsible for verifying vehicle condition." << endl;
    cout << "4. No fraudulent listings are allowed." << endl;
    cout << "5. Disputes must be reported to Admin." << endl;
    cout << "=============================" << endl;
}

void Marketplace::filterByMaxPrice(double maxPrice) const
{
    cout << "\n Listings under " << maxPrice << " PKR" << endl;
    bool found = false;
    for (int i = 0; i < listingCount; i++)
    {
        if (allListings[i]->getAskingPrice() <= maxPrice)
        {
            cout << *(allListings[i]) << endl;
            found = true;
        }
    }
    if (!found) cout << "No listings found under this price." << endl;
}
