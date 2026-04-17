#pragma once
#include <string>
#include <iostream>
#include "Vehicles.h"

using namespace std;

class Seller; // forward declaration

// abstract base class
class ListingBase
{
protected:
    const int listingID;
    Seller* sellerRef;
    Vehicle* vehicleItem;
    double askingPrice;
    string postDate;
    string listingLocation;
    bool isSold;
    bool isApproved;
    static int totalActiveListings;

public:
    ListingBase(Seller* s, Vehicle* v, double price, string loc);
    virtual ~ListingBase();

    int getListingID() const;
    Seller* getSellerRef() const;
    double getAskingPrice() const;
    bool getIsApproved() const;
    bool getIsSold() const;
    static int getTotalActiveListings();
    Vehicle* getVehicleItem() const;
    string getListingLocation() const;

    void setIsApproved(bool status);
    void updatePrice(double newPrice);
    void markAsSold();
    void applyDiscount(float percentage);

    // pure virtual function
    virtual double calculatePlatformFee() const = 0;

    // virtual print function to allow polymorphic operator<< overloading
    virtual void print(ostream& os) const = 0;

    // operator overloading
    bool operator<(const ListingBase& other) const;
    bool operator>(const ListingBase& other) const;

    // global operator overloading using friend functions
    friend ostream& operator<<(ostream& os, const ListingBase& listing);
};

// derived standard ad class
class StandardAd : public ListingBase
{
public:
    StandardAd(Seller* s, Vehicle* v, double price, string loc);

    double calculatePlatformFee() const override;
    void print(ostream& os) const override;
};

// derived featured ad class
class FeaturedAd : public ListingBase
{
private:
    int bumpCount;

public:
    FeaturedAd(Seller* s, Vehicle* v, double price, string loc);

    double calculatePlatformFee() const override;
    void print(ostream& os) const override;

    //operator overloading prefix and post fix ++
    FeaturedAd& operator++();    // prefix: bump ad immediately
    FeaturedAd operator++(int);
};
