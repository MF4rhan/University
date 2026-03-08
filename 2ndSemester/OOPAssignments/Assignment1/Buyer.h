#pragma once
#include <string>
#include "AdListing.h"
#include "Seller.h"
#include "Message.h"
using namespace std;

class Buyer 
{
private:
    const int buyerID;
    string name;
    string phoneNumber;
    string joinDate;
    AdListing* favoriteAds[10]; //aggregation
    int favoriteCount;
    static int totalRegisteredBuyers;   //static
    Message* inbox[10]; //aggregation
    int inboxCount;


public:
    //constructors
    Buyer();
    Buyer(string nn, string pn, string jd);
    ~Buyer();
    
    //getters
    int getBuyerID() const;
    string getName() const;
    string getPhoneNumber() const;
    string getJoinDate() const;
    int getFavoriteCount() const;
    static int getTotalRegisteredBuyers();

    //setters
    void setName(string n);
    void setPhoneNumber(string pn);

    //methods
    void addToFavorites(AdListing* ad);
    void removeFromFavorites(int adID);
    void displayFavorites();
    void draftMessage(Seller* seller, string text);
    void receiveMessage(Message* msg);
    void viewInbox();
};