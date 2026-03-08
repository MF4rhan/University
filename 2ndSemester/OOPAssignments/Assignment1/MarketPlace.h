#pragma once
#include <string>
#include "AdListing.h"
#include "Buyer.h"
#include "Admin.h"
using namespace std;

class Marketplace
{
private:
    string systemName;
    AdListing* allListings[50]; //array of pointers to objects
    Buyer* registeredBuyers[50]; //array of pointers to objects
    Seller* registeredSellers[50]; //array of pointers to objects
    const Admin* platformAdmin; //aggregation + const pointer
    int maxCapacity;
    int listingCount;
    int buyerCount;
    int sellerCount;
public:
    //constructors
    Marketplace();
    Marketplace(string name, const Admin* admin, int capacity);

    //getters
    string getSystemName() const;
    int getListingCount() const;
    int getBuyerCount() const;
    int getMaxCapacity() const;

    //methods
    void addListing(AdListing* listing);
    void addBuyer(Buyer* buyer);
    void addSeller(Seller* seller);
    void searchByBrand(string brand);
    void filterByLocation(string city);
    double getTotalPlatformValue();
    void verifyAndApplyPromo(string code, AdListing& ad);
    static void displayMarketplaceRules();
    void filterByMaxPrice(double maxPrice);
    void filterByMinYear(int minYear);
};