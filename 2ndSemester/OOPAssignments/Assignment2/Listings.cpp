#include "Listings.h"
#include "Users.h" // User.h is needed to call Seller methods

using namespace std;

int ListingBase::totalActiveListings = 0;

// Base implementaion
ListingBase::ListingBase(Seller* s, Vehicle* v, double price, string loc)
: listingID(totalActiveListings++), sellerRef(s), vehicleItem(v), askingPrice(price),
postDate("Pending"), listingLocation(loc), isSold(false), isApproved(false)
{
    if (sellerRef != nullptr)
    {
        sellerRef->incrementActiveAds();
    }
}

ListingBase::~ListingBase()
{
    delete vehicleItem; // freeing the allocated memory for the vehicle
}

int ListingBase::getListingID() const {return listingID;}
Seller* ListingBase::getSellerRef() const {return sellerRef;}
double ListingBase::getAskingPrice() const {return askingPrice;}
bool ListingBase::getIsApproved() const {return isApproved;}
bool ListingBase::getIsSold() const {return isSold;}
int ListingBase::getTotalActiveListings() {return totalActiveListings;}
void ListingBase::setIsApproved(bool status) {isApproved = status;}
Vehicle* ListingBase::getVehicleItem() const {return vehicleItem;}
string ListingBase::getListingLocation() const {return listingLocation;}

void ListingBase::updatePrice(double newPrice)
{
    if (newPrice < 0)
    {
        cout << "Invalid price." << endl;
        return;
    }
    askingPrice = newPrice;
    cout << "Price updated to " << askingPrice << " PKR." << endl;
}

void ListingBase::markAsSold()
{
    if (!isSold)
    {
        isSold = true;
        totalActiveListings--;
        if (sellerRef != nullptr)
        {
            sellerRef->decrementActiveAds();
        }
        cout << "Listing " << listingID << " marked as sold." << endl;
    }
    else
    {
        cout << "Listing " << listingID << " is already marked as sold." << endl;
    }
}

void ListingBase::applyDiscount(float percentage)
{
    if (percentage < 0 || percentage > 100)
    {
        cout << "Invalid discount percentage." << endl;
        return;
    }
    askingPrice -= (askingPrice * percentage / 100);
    cout << "New Price After Discount: " << askingPrice << " PKR" << endl;
}

bool ListingBase::operator<(const ListingBase& other) const
{
    return this->askingPrice < other.askingPrice;
}

bool ListingBase::operator>(const ListingBase& other) const
{
    return this->askingPrice > other.askingPrice;
}

ostream& operator<<(ostream& os, const ListingBase& listing)
{
    listing.print(os); // calling the printing method
    return os;
}

// standard ad stuff below
StandardAd::StandardAd(Seller* s, Vehicle* v, double price, string loc)
: ListingBase(s, v, price, loc) {}

double StandardAd::calculatePlatformFee() const
{
    return askingPrice * 0.02; // 2% fee for standard ads
}

void StandardAd::print(ostream& os) const
{
    os << "=== Standard Listing :" << listingID << " ===\n"
    << "Status: " << (isApproved ? (isSold ? "Sold" : "Active") : "Pending") << endl
    << "Price: " << askingPrice << " PKR"<< endl
    << "Location: " << listingLocation << endl
    << "Vehicle Details:\n" << *vehicleItem << endl // using vehicle overloaded << operator
    << "=============================";
}

// featured add stuff below
FeaturedAd::FeaturedAd(Seller* s, Vehicle* v, double price, string loc)
: ListingBase(s, v, price, loc), bumpCount(0)
{
    postDate = "Today (Featured)";
}

double FeaturedAd::calculatePlatformFee() const
{
    return askingPrice * 0.05; // 5% premium fee for featured ads
}

void FeaturedAd::print(ostream& os) const
{
    os << "=== Featured Listing: " << listingID << " ===" << endl
    << "Bumps: " << bumpCount << endl
    << "Status: " << (isApproved ? (isSold ? "Sold" : "Active") : "Pending") << endl
    << "Price: " << askingPrice << " PKR" << endl
    << "Location: " << listingLocation << endl
    << "Vehicle Details:\n" << *vehicleItem << endl // again using the Vehicle overloaded << operator
    << "=============================";
}

FeaturedAd& FeaturedAd::operator++()
{
    bumpCount++;
    postDate = "Just Now";
    return *this;
}

FeaturedAd FeaturedAd::operator++(int)
{
    FeaturedAd temp = *this;
    ++(*this);
    return temp;
}
