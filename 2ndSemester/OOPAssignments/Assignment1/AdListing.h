#pragma once
#include <string>
#include "Seller.h" 
using namespace std;

class AdListing {
private:
    const int listingID;    //const
    Seller* sellerref;  //aggregation
    double askingPrice;
    string postDate;
    string listingLocation;
    bool isSold;
    static int totalActiveListings; //static
    string vehicleBrand;
    string vehicleModel;
    bool isApproved;
    int vehicleYear;

public:
    AdListing();
    AdListing(Seller* s, double price, string loc, string brand, string model, int year);
    AdListing(Seller* s, double price, string loc, string brand, string model, int year, bool isFeatured);
//getters
    int getListingID() const;
    Seller* getSellerRef() const;
    double getAskingPrice() const;
    string getPostDate() const;
    string getListingLocation() const;
    string getVehicleBrand() const;
    string getVehicleModel() const;
    static int getTotalActiveListings();
    bool getIsApproved() const;
    bool getIsSold() const;
    int getVehicleYear() const;

//setters
    void setIsApproved(bool status);

//methods
    void updatePrice(double newPrice);
    void markAsSold();
    void bumpListing(string currentDate);
    void applyDiscount(float percentage);
    void comparePrice(AdListing& other);
};