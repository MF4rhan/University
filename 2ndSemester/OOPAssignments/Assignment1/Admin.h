#pragma once
#include <string>
#include "Review.h"
#include "Buyer.h"
#include "Seller.h"
#include "AdListing.h"
using namespace std;

class Admin 
{
private:
    int adminID;
    string username;
    int clearanceLevel;
    int actionsLogged;
    int systemUpTime;

public:
    //constructors
    Admin();
    Admin(int id, string username, int clearanceLevel, int systemUpTime);

    //getters
    int getAdminID() const;
    string getUsername() const;
    int getClearanceLevel() const;
    int getActionsLogged() const;
    int getSystemUpTime() const;

    //setters
    void setClearanceLevel(int level);

    //methods
    void reviewFlaggedContent(Review flaggedReview);
    void banUser(int userID);
    string generateSystemReport();
    void resetUserPassword(int userID);
    void approveListing(AdListing& listing);
    void removeListing(AdListing& listing);
};