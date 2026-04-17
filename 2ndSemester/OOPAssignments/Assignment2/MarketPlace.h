#pragma once
#include <string>
#include "Users.h"
#include "Listings.h"

using namespace std;

class Marketplace {
private:
    string systemName;
    const Admin* platformAdmin;

    ListingBase* allListings[100]; // polymorphic array for all types of ads
    User* platformUsers[100];      // polymorphic array to hold all types of users

    int maxCapacity;
    int listingCount;
    int userCount;

public:
    Marketplace();
    Marketplace(string name, const Admin* admin, int capacity);
    ~Marketplace();

    string getSystemName() const;
    int getListingCount() const;
    int getUserCount() const;
    const Admin* getAdmin() const;

    // function overloading here
    void search(string brand) const;
    void search(string brand, int minYear) const;

    void filterByLocation(string city) const;
    double getTotalPlatformValue() const;
    static void displayMarketplaceRules();
    void filterByMaxPrice(double maxPrice) const;

    // function overloading here
    Marketplace& operator+=(User* newUser);
    Marketplace& operator+=(ListingBase* newListing);
};
