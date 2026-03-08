#include "MarketPlace.h"
#include <iostream>
using namespace std;

//constructors
Marketplace::Marketplace()
:systemName("PakWheels"), platformAdmin(nullptr), maxCapacity(50), listingCount(0), buyerCount(0), sellerCount(0)   {}

Marketplace::Marketplace(string name, const Admin* admin, int capacity)
:systemName(name), platformAdmin(admin), maxCapacity(capacity), listingCount(0), buyerCount(0), sellerCount(0) {}

//getters
string Marketplace::getSystemName() const   {return systemName;}
int Marketplace::getListingCount() const    {return listingCount;}
int Marketplace::getBuyerCount() const  {return buyerCount;}
int Marketplace::getMaxCapacity() const {return maxCapacity;}

//methods
void Marketplace::addListing(AdListing* listing)
{
    if (listingCount >= maxCapacity)
    {
        cout << "Marketplace is full." << endl;
        return;
    }
    allListings[listingCount++] = listing;
    cout << "Listing added to marketplace." << endl;
}

void Marketplace::addBuyer(Buyer* buyer)
{
    if (buyerCount >= maxCapacity)
    {
        cout << "Cannot register more buyers." << endl;
        return;
    }
    registeredBuyers[buyerCount++] = buyer;
    cout << "Buyer " << buyer->getName() << " registered." << endl;
}

void Marketplace::searchByBrand(string brand)
{
    bool found = false;
    for (int i = 0; i < listingCount; i++)
    {
        if (allListings[i]->getVehicleBrand() == brand)
        {
            cout << "Listing ID : " << allListings[i]->getListingID() << endl;
            cout << "Brand      : " << allListings[i]->getVehicleBrand() << endl;
            cout << "Model      : " << allListings[i]->getVehicleModel() << endl;
            cout << "Price      : " << allListings[i]->getAskingPrice() << " PKR" << endl;
            cout << "Location   : " << allListings[i]->getListingLocation() << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No listings found for brand: " << brand << endl;
}

void Marketplace::filterByLocation(string city)
{
    bool found = false;
    for (int i = 0; i < listingCount; i++)
    {
        if (allListings[i]->getListingLocation() == city)
        {
            cout << "Listing ID : " << allListings[i]->getListingID() << endl;
            cout << "Brand      : " << allListings[i]->getVehicleBrand() << endl;
            cout << "Model      : " << allListings[i]->getVehicleModel() << endl;
            cout << "Price      : " << allListings[i]->getAskingPrice() << " PKR" << endl;
            cout << "Location   : " << allListings[i]->getListingLocation() << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No listings found in: " << city << endl;
}

void Marketplace::filterByMaxPrice(double maxPrice)
{
    bool found = false;
    for (int i = 0; i < listingCount; i++)
    {
        if (allListings[i]->getAskingPrice() <= maxPrice)
        {
            cout << "Listing ID : " << allListings[i]->getListingID() << endl;
            cout << "Brand      : " << allListings[i]->getVehicleBrand() << endl;
            cout << "Model      : " << allListings[i]->getVehicleModel() << endl;
            cout << "Price      : " << allListings[i]->getAskingPrice() << " PKR" << endl;
            cout << "Location   : " << allListings[i]->getListingLocation() << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No listings found under: " << maxPrice << " PKR" << endl;
}

void Marketplace::filterByMinYear(int minYear)
{
    bool found = false;
    for (int i = 0; i < listingCount; i++)
    {
        if (allListings[i]->getVehicleYear() >= minYear)
        {
            cout << "Listing ID : " << allListings[i]->getListingID() << endl;
            cout << "Brand      : " << allListings[i]->getVehicleBrand() << endl;
            cout << "Model      : " << allListings[i]->getVehicleModel() << endl;
            cout << "Year       : " << allListings[i]->getVehicleYear() << endl;
            cout << "Price      : " << allListings[i]->getAskingPrice() << " PKR" << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No listings found from year " << minYear << " or newer." << endl;
}

double Marketplace::getTotalPlatformValue()
{
    double total = 0;
    for (int i = 0; i < listingCount; i++)
        total += allListings[i]->getAskingPrice();
    cout << "Total Platform Value: " << total << " PKR" << endl;
    return total;
}

void Marketplace::verifyAndApplyPromo(string code, AdListing& ad)
{
    // hardcoded promo codes and their discount percentages
    if (code == "SAVE10")
        ad.applyDiscount(10);
    else if (code == "SAVE20")
        ad.applyDiscount(20);
    else if (code == "RAMADAN50")
        ad.applyDiscount(50);
    else
        cout << "Invalid promo code." << endl;
}

void Marketplace::addSeller(Seller* seller)
{
    if (sellerCount >= maxCapacity)
    {
        cout << "Cannot register more sellers." << endl;
        return;
    }
    registeredSellers[sellerCount++] = seller;
    cout << "Seller " << seller->getName() << " registered." << endl;
}

void Marketplace::displayMarketplaceRules()     //static - no object needed to call this
{
    cout << "===== Marketplace Rules =====" << endl;
    cout << "1. All listings must be approved by Admin before going live." << endl;
    cout << "2. Sellers must provide accurate vehicle information." << endl;
    cout << "3. Buyers are responsible for verifying vehicle condition." << endl;
    cout << "4. No fraudulent listings are allowed." << endl;
    cout << "5. Disputes must be reported to Admin." << endl;
    cout << "=============================" << endl;
}