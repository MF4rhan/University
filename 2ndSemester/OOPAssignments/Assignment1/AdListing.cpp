#include "AdListing.h"
#include <iostream>
using namespace std;

int AdListing::totalActiveListings = 0;

AdListing::AdListing()
:listingID(totalActiveListings++), sellerref(nullptr), askingPrice(0.0), postDate("N/A"), listingLocation("N/A"), isSold(false),
 vehicleBrand("N/A"), vehicleModel("N/A"), isApproved(false)   {}

AdListing::AdListing(Seller* s, double a, string LL, string brand, string model, int year)
:listingID(totalActiveListings++), sellerref(s), askingPrice(a), postDate("Pending"), listingLocation(LL), isSold(false),
 vehicleBrand(brand), vehicleModel(model), isApproved(false), vehicleYear(year)
{
    if (sellerref!=nullptr)
        sellerref->incrementActiveAds();
}

AdListing::AdListing(Seller* s, double a, string LL, string brand, string model, int year, bool isFeatured)
:listingID(totalActiveListings++), sellerref(s), askingPrice(a), postDate("Pending"), listingLocation(LL), isSold(false),
 vehicleBrand(brand), vehicleModel(model), vehicleYear(year), isApproved(false)
{
    if (sellerref!=nullptr)
        sellerref->incrementActiveAds();
    if (isFeatured)
        bumpListing("Today");
}

int AdListing::getListingID() const     {return listingID;}
Seller* AdListing::getSellerRef() const     {return sellerref;}
double AdListing::getAskingPrice() const    {return askingPrice;}
string AdListing::getPostDate() const       {return postDate;}
string AdListing::getListingLocation() const    {return listingLocation;}
string AdListing::getVehicleBrand() const   {return vehicleBrand;}
string AdListing::getVehicleModel() const   {return vehicleModel;}
int AdListing::getTotalActiveListings()     {return totalActiveListings;}
bool AdListing::getIsApproved() const   {return isApproved;}
bool AdListing::getIsSold() const {return isSold;}
int AdListing::getVehicleYear() const {return vehicleYear;}

void AdListing::setIsApproved(bool status) {isApproved = status;}


void AdListing::updatePrice(double newPrice)
{
    if (newPrice < 0)
    {
        cout << "Invalid price." << endl;
        return;
    }
    askingPrice = newPrice;
    cout << "Price updated to " << askingPrice << " PKR." << endl;
}

void AdListing::markAsSold() {
    if (!isSold) 
    {
        isSold = true;
        totalActiveListings--;
        if (sellerref != nullptr)
            sellerref->decrementActiveAds();
        cout << "Listing " << listingID << " has been marked as sold." << endl;
    } 
    else
        cout << "Listing " << listingID << " is already marked as sold." << endl;
}

void AdListing::bumpListing(string currentDate) {postDate = currentDate;}

void AdListing::applyDiscount(float percentage)
{
    if (percentage < 0 || percentage > 100) 
    {
        cout << "Invalid discount percentage." << endl;
        return;
    }
    cout << "Price After Discount:\t" << askingPrice - (askingPrice * percentage / 100) << endl;
}

void AdListing::comparePrice(AdListing& other)
{
    if (askingPrice < other.askingPrice)
        cout << "Listing " << listingID << " is cheaper by "<< other.askingPrice - askingPrice << " PKR." << endl;
    else if (askingPrice > other.askingPrice)
        cout << "Listing " << other.listingID << " is cheaper by "<< askingPrice - other.askingPrice << " PKR." << endl;
    else
        cout << "Both listings are priced the same." << endl;
}