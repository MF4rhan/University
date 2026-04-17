#pragma once
#include <string>
#include <iostream>
using namespace std;

class Message;
class ListingBase;
class Review;
class Seller; // forward declaration needed for Buyer

// abstract base class "User"
class User
{
protected:
    int userID;
    string name;
    Message* inbox[10];
    int inboxCount;
    static int globalUserCount;

public:
    User(string n);
    virtual ~User();

    int getUserID() const;
    string getName() const;

    void receiveMessage(Message* msg);
    void viewInbox();

    // pure virtual function
    virtual void displayDashboard() const = 0;

    // admin needs access to private user data for moderation
    friend class Admin;
};

// derived class Admin
class Admin : public User
{
private:
    int clearanceLevel;
    int actionsLogged;
    int systemUpTime;

public:
    Admin(string uname, int cl, int uptime);

    void displayDashboard() const override;

    int getClearanceLevel() const;
    void reviewFlaggedContent(Review& flaggedReview);
    void banUser(int targetUserID);
    string generateSystemReport();
    void resetUserPassword(int targetUserID);
    void approveListing(ListingBase& listing);
    void removeListing(ListingBase& listing);
};

// derived class Buyer
class Buyer : public User {
private:
    string phoneNumber;
    string joinDate;
    ListingBase* favoriteAds[10];
    int favoriteCount;
    static int totalRegisteredBuyers;

public:
    Buyer(string n, string pn, string jd);
    ~Buyer();

    void displayDashboard() const override;
    static int getTotalRegisteredBuyers();

    void addToFavorites(ListingBase* ad);
    void removeFromFavorites(int adID);
    void displayFavorites();
    void draftMessage(Seller* seller, string text);

    // global operator overloading using friend function
    friend istream& operator>>(istream& in, Buyer& b);
};

// derived class Seller
class Seller : public User
{
private:
    string contactNumber;
    string locationAddress;
    int activeAdsCount;
    Review* reviews[10];
    int reviewCount;
    static int totalRegisteredSellers;

public:
    Seller(string n, string contact, string location);
    ~Seller();

    void displayDashboard() const override;
    static int getTotalRegisteredSellers();

    void incrementActiveAds();
    void decrementActiveAds();
    string determineSellerType();
    bool canOfferFinancing();
    void replyToMessage(int messageID, string replyText, Buyer* buyer);
    void addReview(Review* r);
    int getSenderIDByMessageID(int messageID) const;

    // global operator overloading using friend function
    friend istream& operator>>(istream& in, Seller& s);
};
