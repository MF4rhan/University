#include "Seller.h"
#include "Message.h"
#include <iostream>
#include "Buyer.h"
using namespace std;


//static declaration
int Seller::totalRegisteredSellers=0;

//constructors
Seller::Seller()
:sellerID(totalRegisteredSellers++), name("Unknown"), contactNumber("None"), locationAddress("N/A"), activeAdsCount(0),inboxCount(0), reviewCount(0)
{
    for (int i = 0; i < 10; ++i)
        inbox[i]=nullptr;
}
Seller::Seller(string n, string cn, string la)
: sellerID(totalRegisteredSellers++), name(n), contactNumber(cn), locationAddress(la), activeAdsCount(0),inboxCount(0), reviewCount(0)
{
    for (int i = 0; i < 10; ++i)
        inbox[i]=nullptr;
}
Seller::~Seller()
{
    for (int i = 0; i < inboxCount; i++)
    {
        delete inbox[i];
        inbox[i] = nullptr;
    }
}

//setters
void Seller::setNumber(string n)    {contactNumber=n;} 
void Seller::setAddress(string a)   {locationAddress=a;}

//getters
int Seller::getSellerID() const {return sellerID;}
string Seller::getName() const  {return name;}
string Seller::getContactNumber() const {return contactNumber;}
string Seller::getLocationAddress() const   {return locationAddress;}
int Seller::getActiveAdsCount() const   {return activeAdsCount;}
int Seller::getTotalRegisteredSellers() {return totalRegisteredSellers;}
//methods
void Seller::incrementActiveAds()   {activeAdsCount++;}
void Seller::decrementActiveAds()   {activeAdsCount--;}
string Seller::determineSellerType()
{
    if (activeAdsCount==0 || activeAdsCount==1)
        return "New Seller.";
    else if (activeAdsCount>1 && activeAdsCount<=5)
        return "Regular Seller.";
    else
        return "Dealership/Power Seller.";
}
 bool Seller::canOfferFinancing()
{
    if (determineSellerType()=="Dealership/Power Seller.")
         return true; //basically, can handle take loans, or bank financing, etc.
    else
        return false; //payorder or cash only.
}

 void Seller::receiveMessage(Message* m) 
{
    if (inboxCount >= 10) 
    {
        cout << "Inbox full." <<endl;
        return;
    }
    else
        inbox[inboxCount++] = m;
}

void Seller::viewInbox() 
{
    if (inboxCount==0) 
    {
        cout << "Inbox is empty."<< endl;
        return;
    }
    else
        for (int i = 0; i <inboxCount; ++i) 
        {
            inbox[i]->markAsRead();
            inbox[i]->formatMessageThread();
        }
}

void Seller::replyToMessage(int messageID, string replyText, Buyer* buyer) 
{
    for (int i = 0; i < inboxCount; i++) 
    {
        if (inbox[i]->getMessageID() == messageID) 
        {
            Message* reply = new Message(sellerID, inbox[i]->getSenderID(), replyText, "Now");
            buyer->receiveMessage(reply);
            cout << "Reply sent to buyer." <<endl;
            return;
        }
    }
    cout << "Message not found." << endl;
}

void Seller::addReview(Review r)
{
    if (reviewCount >= 10)
    {
        cout << "Review limit reached." << endl;
        return;
    }
    reviews[reviewCount++] = r;
    cout << "Review added." << endl;
}

int Seller::getSenderIDByMessageID(int messageID) const
{
    for (int i = 0; i < inboxCount; i++)
        if (inbox[i]->getMessageID() == messageID)
            return inbox[i]->getSenderID();
    return -1;
}