#include "Buyer.h"
#include "Message.h"
#include <iostream>
using namespace std;

int Buyer::totalRegisteredBuyers = 0;

Buyer::Buyer()
:buyerID(totalRegisteredBuyers++), name("None"), phoneNumber("N/A"), joinDate("N/A"), favoriteCount(0), inboxCount(0)
{
	for (int i = 0; i < 10; ++i)
	{
		favoriteAds[i]=nullptr;
		inbox[i]=nullptr;
	}
}

Buyer::Buyer(string n, string pn, string jd)
	:buyerID(totalRegisteredBuyers++), name(n), phoneNumber(pn), joinDate(jd), favoriteCount(0), inboxCount(0)
{
	for (int i = 0; i < 10; ++i)
	{
		favoriteAds[i]=nullptr;
		inbox[i]=nullptr;
	}
}

Buyer::~Buyer()
{
    for (int i = 0; i < inboxCount; i++)
    {
        delete inbox[i];
        inbox[i] = nullptr;
    }
}

//getters
int Buyer::getBuyerID() const	{return buyerID;}
string Buyer::getName() const	{return name;}
string Buyer::getPhoneNumber() const	{return phoneNumber;}
string Buyer::getJoinDate() const	{return joinDate;}
int Buyer::getFavoriteCount() const	{return favoriteCount;}
int Buyer::getTotalRegisteredBuyers()	{return totalRegisteredBuyers;}

//setters
void Buyer::setName(string n)	{name=n;}
void Buyer::setPhoneNumber(string pn)	{phoneNumber=pn;}

//methods
void Buyer::addToFavorites(AdListing* ad)
{
	if (favoriteCount>=10)
	{
		cout << "Favorite List is full."<<endl;
		return;
	}
	else
	{
		favoriteAds[favoriteCount++]=ad;
		cout << "Listing added to Favoites."<<endl;
	}
}

void Buyer::removeFromFavorites(int adID)
{
    for (int i = 0; i < favoriteCount; ++i)
    {
        if (favoriteAds[i]->getListingID() == adID)
        {
            for (int j = i; j < favoriteCount - 1; ++j)
                favoriteAds[j] = favoriteAds[j + 1];
            favoriteAds[--favoriteCount] = nullptr;
            cout << "Listing " << adID << " removed from favorites." << endl;
            return;
        }
    }
    cout << "Listing " << adID << " was not found in your favorites." << endl;
}

void Buyer::displayFavorites() 
{
    if (favoriteCount == 0) {
        cout << "No favorites yet." << endl;
        return;
    }
    else
	    for (int i = 0; i < favoriteCount; i++) 
	    {
	        cout << "Favorite " << i+1 <<":"<<endl;
	        cout << "Listing ID:\t\t"<< favoriteAds[i]->getListingID()<<endl;
	        cout << "Price:\t\t" << favoriteAds[i]->getAskingPrice()<<" PKR"<<endl;
	        cout << "Location:\t\t" << favoriteAds[i]->getListingLocation() << endl;
	    }
}
void Buyer::draftMessage(Seller* seller, string text)
{
	if (seller==nullptr) 
	{
       cout << "Invalid seller." << endl;
       return;
    }
    else
    {
	    Message* msg = new Message(buyerID, seller->getSellerID(), text, "Now");
	    seller->receiveMessage(msg);
	    cout << "Message sent to " << seller->getName() << endl;
	}
}

void Buyer::receiveMessage(Message* msg) 
{
   if (inboxCount>=10) 
   	{
    	cout <<"Inbox full."<<endl;
        return;
    }
   else
   		inbox[inboxCount++] =msg;
}

void Buyer::viewInbox() 
{
    if (inboxCount==0) 
    {
        cout <<"Inbox is empty."<<endl;
        return;
    }
    else
	    for (int i= 0; i < inboxCount; ++i) 
	    {
	        inbox[i]->markAsRead();
	        inbox[i]->formatMessageThread();
	    }
}

