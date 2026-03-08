#pragma once
#include "Message.h"
#include "Review.h"
#include <string>
class Buyer;
using namespace std;

class Seller {
private:
    const int sellerID;
    string name;
    string contactNumber;
    string locationAddress;
    int activeAdsCount;
    static int totalRegisteredSellers;  //static
    Message* inbox[10]; //aggregation
    int inboxCount;
    Review reviews[10]; //array of objects
    int reviewCount;

public:
    Seller();
    Seller(string n, string contact, string location);
    ~Seller();
    //getters
    int getSellerID() const;
    string getName() const;
    string getContactNumber() const;
    string getLocationAddress() const;
    int getActiveAdsCount() const;
    //setters
    void setNumber(string n);
    void setAddress(string a);
//methods
    void incrementActiveAds();
    void decrementActiveAds();
    string determineSellerType();
    bool canOfferFinancing();
    static int getTotalRegisteredSellers();
    void receiveMessage(Message* msg);
    void viewInbox();
    void replyToMessage(int messageID, string replyText, Buyer* buyer);
    void addReview(Review r);
    int getSenderIDByMessageID(int messageID) const;

};