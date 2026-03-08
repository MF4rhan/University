#include <iostream>
#include <string>
#include "Admin.h"
#include "MarketPlace.h"
#include "Seller.h"
#include "Buyer.h"
#include "Car.h"
#include "Bike.h"
#include "AdListing.h"
#include "Review.h"
#include "Message.h"
#include "VehicleCore.h"

using namespace std;

int main() 
{
    //setting up the main platform stuff
    // here i am adding things by default so you dont have to enter each and everything manually to test the program
    //here adding the admin, aka me
    Marketplace::displayMarketplaceRules(); 
    Admin mainAdmin(1, "Farhan", 3, 240);
    Marketplace pakWheels("PakWheels OOP", &mainAdmin, 100);

    //arrays to hold our objects in main so we can search through them in the menu later
    //using pointers so we dont accidentally lose data
    Seller* sellers[50];
    int sCount=0;
    Buyer* buyers[50];
    int bCount=0;
    AdListing* ads[100];
    int adCount=0;

    //here i am filling up some sellers and buyers by default
    sellers[sCount++] = new Seller("Ahmed", "0300-1234567", "Lahore"); //id 0
    sellers[sCount++] = new Seller("Ali", "0333-7654321", "Karachi");   //id 1
    
    buyers[bCount++] = new Buyer("Zain", "0311-0000000", "25-Nov-2023"); //id 0
    buyers[bCount++] = new Buyer("Omar", "0321-1111111", "01-Jan-2024"); //id 1

    //registering those sellers and buyers by default as well.
    for (int i = 0; i < sCount; i++) 
        pakWheels.addSeller(sellers[i]);
    for (int i = 0; i < bCount; i++) 
        pakWheels.addBuyer(buyers[i]);
    //here i am adding a car and a listing for it as well.
    Car* dummyCar = new Car("Honda", "Civic", 2020, 45000, "PK123", 1800, "Auto", true, 400, "Local");
    AdListing* dummyAd = new AdListing(sellers[0], 6500000, "Lahore", dummyCar->getBaseSpecs().getBrand(), dummyCar->getBaseSpecs().getModel(), dummyCar->getBaseSpecs().getModelYear());
    ads[adCount++] = dummyAd;
    pakWheels.addListing(dummyAd);
    mainAdmin.approveListing(*dummyAd); // preapproving it so it shows up in searches


    //now that all the default stuff is done, here is the actual program.
    bool running = true;
    while (running) 
    {
        cout<<endl;
        cout << "========================================="<<endl;
        cout << "   PAKWHEELS MAIN MENU" << endl;
        cout << "========================================="<<endl;
        cout << "1. Admin Panel"<<endl;
        cout << "2. Seller Panel"<<endl;
        cout << "3. Buyer Panel"<<endl;
        cout << "4. Marketplace (Search and Filter)"<<endl;
        cout << "5. Exit Program"<<endl;
        cout << "Enter choice: ";
        
        int mainChoice;
        cin >> mainChoice;

        switch (mainChoice) 
        {
            case 1: //admin section
            {
                cout << endl;
                cout << "--- ADMIN PANEL ---"<<endl;
                cout << "1. View System Report"<<endl;
                cout << "2. Approve a Listing"<<endl;
                cout << "3. Remove a Listing"<<endl;
                cout << "Enter choice: ";
                int adChoice;
                cin >> adChoice;

                if (adChoice == 1) 
                    mainAdmin.generateSystemReport();
                else if (adChoice == 2 || adChoice == 3) 
                {
                    cout << "Enter the Listing ID: ";
                    int lID;
                    cin >> lID;
                    bool found = false;
                    for (int i = 0; i < adCount; i++) 
                    {
                        if (ads[i]->getListingID() == lID) 
                        {
                            if (adChoice==2) 
                                mainAdmin.approveListing(*ads[i]);

                            if (adChoice==3) 
                                mainAdmin.removeListing(*ads[i]);

                            found=true;
                            break;
                        }
                    }
                    if (!found) 
                        cout << "Listing not found"<<endl;
                }//end of else if
                break;
            }//end of vase 1

            case 2: //selling panel
            {
                cout << "\n--- SELLER PANEL ---"<<endl;
                cout << "1. Register as new Seller"<<endl;
                cout << "2. Post a new Vehicle Ad"<<endl;
                cout << "3. Update Ad Price"<<endl;
                cout << "4. View Inbox & Reply"<<endl;
                cout << "Enter choice: ";
                int sChoice; 
                cin >> sChoice;

                if (sChoice==1) 
                {
                    string n, c, l;
                    cout << "Enter Name: ";
                    cin >> n;
                    cout << "Enter Contact: ";
                    cin >> c;
                    cout << "Enter Location: ";
                    cin >> l;
                    sellers[sCount] = new Seller(n, c, l);
                    pakWheels.addSeller(sellers[sCount]); // register new seller in marketplace
                    cout << "Registered, Your Seller ID is: " << sellers[sCount]->getSellerID() << endl;
                    sCount++;
                }
                else if (sChoice == 2) 
                {
                    cout <<"Enter your Seller ID: ";
                    int id; 
                    cin >> id;
                    Seller* currentSeller = nullptr;

                    for(int i=0; i<sCount; i++) 
                        if(sellers[i]->getSellerID() == id) 
                            currentSeller = sellers[i];

                    if(currentSeller==nullptr) 
                    {
                        cout << "Invalid Seller ID."<<endl;
                        break;
                    }

                    string brand, model, loc;
                    double price;
                    int year;
                    cout << "Enter Brand: ";
                    cin >> brand;
                    cout << "Enter Model: ";
                    cin >> model;
                    cout << "Enter Location: ";
                    cin >> loc;
                    cout << "Enter Price (PKR): ";
                    cin >> price;
                    cout << "Enter Year: ";
                    cin >> year;
                    ads[adCount] = new AdListing(currentSeller, price, loc, brand, model, year);
                    pakWheels.addListing(ads[adCount]);
                    cout << "Ad posted, waiting for Admin approval.\n";
                    adCount++;
                }
                else if (sChoice==3) 
                {
                    cout << "Enter Listing ID to update: ";
                    int lID;
                    cin >> lID;
                    cout << "Enter new price: ";
                    double newPrice;
                    cin >> newPrice;
                    for (int i = 0; i < adCount; i++) 
                    {
                        if (ads[i]->getListingID()==lID) 
                        {
                            ads[i]->updatePrice(newPrice);
                            break;
                        }
                    }
                }
                else if (sChoice==4) 
                {
                    cout << "Enter your Seller ID: ";
                    int id;
                    cin >>id;
                    for(int i=0; i<sCount; i++) 
                    {
                        if(sellers[i]->getSellerID()==id) 
                        {
                            sellers[i]->viewInbox();
                            cout << "Enter Message ID to reply to (or -1 to skip): ";
                            int mID;
                            cin >> mID;

                            if(mID != -1) 
                            {
                                cout << "Enter reply: ";
                                string reply; 
                                cin.ignore();//this will remove new line
                                getline(cin, reply); //this will take full message
                                // find the correct buyer to reply to using the message's senderID
                                int senderID = sellers[i]->getSenderIDByMessageID(mID);
                                Buyer* targetBuyer = nullptr;

                                for(int j = 0; j < bCount; j++)
                                    if(buyers[j]->getBuyerID()==senderID)
                                        targetBuyer = buyers[j];

                                if (targetBuyer == nullptr)
                                    cout << "Message ID not found.\n";
                                else
                                    sellers[i]->replyToMessage(mID, reply, targetBuyer);
                            }
                            break;
                        }
                    }
                }
                break;
            }

            case 3: //buyer panel
            {
                cout << "\n--- BUYER PANEL ---"<<endl;
                cout << "1. Register as new Buyer"<<endl;
                cout << "2. Add Listing to Favorites"<<endl;
                cout << "3. View Favorites"<<endl;
                cout << "4. Remove Listing from Favorites"<<endl;
                cout << "5. Send Message to Seller"<<endl;
                cout << "6. View Inbox"<<endl;
                cout << "Enter choice: ";
                int bChoice;
                cin>> bChoice;

                if (bChoice == 1) 
                {
                    string n, c, d;
                    cout << "Enter Name: ";
                    cin >> n;
                    cout << "Enter Phone: ";
                    cin >> c;
                    cout << "Enter Join Date: ";
                    cin >> d;
                    buyers[bCount] = new Buyer(n, c, d);
                    pakWheels.addBuyer(buyers[bCount]);
                    cout << "Registered, Your Buyer ID is: "<<buyers[bCount]->getBuyerID()<<endl;
                    bCount++;
                }
                else if (bChoice >= 2 && bChoice <= 6) 
                {
                    cout << "Enter your Buyer ID: ";
                    int id;
                    cin >> id;
                    Buyer* currentBuyer = nullptr;
                    for(int i=0; i<bCount; i++) 
                        if(buyers[i]->getBuyerID()==id) 
                            currentBuyer = buyers[i];

                    if(currentBuyer==nullptr) 
                    {
                        cout << "Invalid Buyer ID."<<endl;
                        break;
                    }

                    if (bChoice==2) 
                    {
                        cout << "Enter Listing ID to favorite: ";
                        int lID;
                        cin >> lID;
                        for(int i=0; i<adCount; i++)
                            if(ads[i]->getListingID() == lID)
                                currentBuyer->addToFavorites(ads[i]);
                    }
                    else if (bChoice==3) 
                        currentBuyer->displayFavorites();
                    else if (bChoice==4) 
                    {
                        cout << "Enter Listing ID to remove from favorites: ";
                        int lID;
                        cin >> lID;
                        currentBuyer->removeFromFavorites(lID);
                    }
                    else if (bChoice == 5) 
                    {
                        cout << "Enter Seller ID to message: ";
                        int sID;
                        cin >> sID;
                        Seller* targetSeller = nullptr;
                        for(int i=0; i<sCount; i++)
                            if(sellers[i]->getSellerID() == sID)
                                targetSeller = sellers[i];
                        
                        if(targetSeller) 
                        {
                            cout << "Enter message: ";
                            string msgText;
                            cin.ignore();//this will remove new line
                            getline(cin, msgText); //this will take full message
                            currentBuyer->draftMessage(targetSeller, msgText);
                        } 
                        else 
                            cout << "Seller not found."<<endl;
                    }
                    else if (bChoice== 6) 
                        currentBuyer->viewInbox();
                }
                break;
            }

            case 4: //searching area
            {
                cout << "\n--- MARKETPLACE ---"<<endl;
                cout << "1. Search by Brand"<<endl;
                cout << "2. Filter by Location"<<endl;
                cout << "3. Filter by Max Price"<<endl;
                cout << "4. Filter by Minimum Year"<<endl;
                cout << "Enter choice: ";
                int mChoice;
                cin >> mChoice;

                if (mChoice==1) 
                {
                    cout << "Enter Brand (ex: Honda): ";
                    string b;
                    cin >> b;
                    pakWheels.searchByBrand(b);
                } 
                else if (mChoice==2) 
                {
                    cout << "Enter Location (ex: Lahore): ";
                    string l;
                    cin >> l;
                    pakWheels.filterByLocation(l);
                }
                else if (mChoice==3) 
                {
                    cout << "Enter max price (PKR): ";
                    double maxP;
                    cin >> maxP;
                    pakWheels.filterByMaxPrice(maxP);
                }
                else if (mChoice == 4) 
                {
                    cout << "Enter minimum year (ex: 2018): ";
                    int minY;
                    cin >> minY;
                    pakWheels.filterByMinYear(minY);
                }
                break;
            }

            case 5: //exit
            {
                running=false;
                cout << "Exiting system. Goodbye."<<endl;
                break;
            }
            
            default:
                cout << "Invalid choice, Try again."<<endl;
        }
    }
    //freeing memory here
    for (int i = 0; i < sCount; i++)
        delete sellers[i];

    for (int i = 0; i < bCount; i++)
        delete buyers[i];

    for (int i = 0; i < adCount; i++)
        delete ads[i];

    delete dummyCar;

    return 0;
}