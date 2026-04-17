#include <iostream>
#include <string>
#include "Users.h"
#include "Vehicles.h"
#include "Listings.h"
#include "MarketPlace.h"
using namespace std;

int main()
{
    Marketplace::displayMarketplaceRules();

    Admin mainAdmin("Farhan", 3, 240);
    Marketplace pakWheels("PakWheels OOP", &mainAdmin, 100);

    // making local arrays to simulate the logic or menu
    // the actual system storage is handled inside Marketplace using operator+=
    Seller* sellers[50];
    int sCount = 0;
    Buyer* buyers[50];
    int bCount = 0;
    ListingBase* ads[100];
    int adCount = 0;

    // making some default data for simulation
    sellers[sCount] = new Seller("Ahmed", "03001234567", "Lahore");
    pakWheels += sellers[sCount++]; // Using overloaded +=

    sellers[sCount] = new Seller("Ali", "03337654321", "Karachi");
    pakWheels += sellers[sCount++];

    buyers[bCount] = new Buyer("Zain", "03110000000", "25-Nov-2023");
    pakWheels += buyers[bCount++];

    buyers[bCount] = new Buyer("Omar", "03211111111", "01-Jan-2024");
    pakWheels += buyers[bCount++];

    // default listings using polymorphism
    Vehicle* dummyCar = new Car("Honda", "Civic", 2020, 45000, "PK123", 1800, "Auto", true, 400, "Local");
    ListingBase* dummyAd = new StandardAd(sellers[0], dummyCar, 6500000, "Lahore");

    ads[adCount] = dummyAd;
    pakWheels += dummyAd; // using overloaded +=
    mainAdmin.approveListing(*dummyAd);
    adCount++;

    bool running = true;
    while (running)
    {
        cout << "\n========================================="<<endl;
        cout << "   PAKWHEELS OOP MAIN MENU" << endl;
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
            case 1: // admin panel/home
            {
                cout << "\n--- ADMIN PANEL ---\n1. View System Report\n2. Approve a Listing\n3. Remove a Listing\nEnter choice: ";
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
                            if (adChoice == 2)
                                mainAdmin.approveListing(*ads[i]);
                            if (adChoice == 3)
                                mainAdmin.removeListing(*ads[i]);

                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "Listing not found." << endl;
                }
                break;
            }

            case 2: // seller turf
            {
                cout << "\n--- SELLER PANEL ---\n1. Register as new Seller\n2. Post a new Vehicle Ad\n3. Update Ad Price\n4. View Inbox & Reply\nEnter choice: ";
                int sChoice;
                cin >> sChoice;

                if (sChoice == 1)
                {
                    Seller* newS = new Seller("Temp", "Temp", "Temp");
                    cin >> *newS; // using overloaded >>
                    sellers[sCount] = newS;
                    pakWheels += sellers[sCount];
                    cout << "Registered, Your Seller ID is: " << sellers[sCount]->getUserID() << endl;
                    sCount++;
                }
                else if (sChoice == 2)
                {
                    cout <<"Enter your Seller ID: ";
                    int id;
                    cin >> id;
                    Seller* currentSeller = nullptr;

                    for(int i=0; i<sCount; i++)
                    {
                        if(sellers[i]->getUserID() == id)
                            currentSeller = sellers[i];
                    }

                        if(currentSeller == nullptr)
                        {
                            cout << "Invalid Seller ID.\n";
                            break;

                        }

                        int type; cout << "1. Car or 2. Bike? ";
                        cin >> type;

                    string brand, model, loc; double price; int year;
                    cout << "Enter Brand: ";
                    cin >> brand;

                    cout << "Enter Model: ";
                    cin >> model;

                    cout << "Enter Year: ";
                    cin >> year;

                    cout << "Enter Location: ";
                    cin >> loc;

                    cout << "Enter Price (PKR): ";
                    cin >> price;

                    Vehicle* v = nullptr;
                    if (type == 1)
                        v = new Car(brand, model, year, 0, "Unknown", 1000, "Manual", false, 300, "Local");

                    else
                        v = new Bike(brand, model, year, 0, "Unknown", 150, "Commuter", 100, false, "Air-Cooled");

                    int adType; cout << "1. Standard Ad or 2. Featured Ad? ";
                    cin >> adType;

                    ListingBase* newAd = nullptr;
                    if (adType == 2)
                        newAd = new FeaturedAd(currentSeller, v, price, loc);

                    else
                        newAd = new StandardAd(currentSeller, v, price, loc);

                    ads[adCount] = newAd;
                    pakWheels += newAd;
                    cout << "Ad posted, waiting for Admin approvaln" << endl;
                    adCount++;
                }
                else if (sChoice == 3)
                {
                    cout << "Enter Listing ID to update: ";
                    int lID;
                    cin >> lID;

                    cout << "Enter new price: "; double newPrice;
                    cin >> newPrice;

                    for (int i = 0; i < adCount; i++)
                        if (ads[i]->getListingID() == lID)
                        {
                            ads[i]->updatePrice(newPrice);
                            break;

                        }
                }
                else if (sChoice == 4)
                {
                    cout << "Enter your Seller ID: ";
                    int id;
                    cin >> id;

                    for(int i=0; i<sCount; i++)
                    {
                        if(sellers[i]->getUserID() == id)
                        {
                            sellers[i]->viewInbox();
                            cout << "Enter Message ID to reply to (or -1 to skip): ";
                            int mID;
                            cin >> mID;

                            if(mID != -1)
                            {
                                cout << "Enter reply: ";
                                string reply; cin.ignore();
                                getline(cin, reply);

                                int senderID = sellers[i]->getSenderIDByMessageID(mID);
                                Buyer* targetBuyer = nullptr;
                                for(int j = 0; j < bCount; j++)
                                    if(buyers[j]->getUserID() == senderID)
                                        targetBuyer = buyers[j];

                                    if (targetBuyer) sellers[i]->replyToMessage(mID, reply, targetBuyer);
                                    else cout << "Message ID not found.\n";
                            }
                            break;
                        }
                    }
                }
                break;
            }

            case 3: // buyer's panel
            {
                cout << "\n--- BUYER PANEL ---\n1. Register as new Buyer\n2. Add Listing to Favorites\n3. View Favorites\n4. Remove Listing from Favorites\n5. Send Message to Seller\n6. View Inbox\nEnter choice: ";
                int bChoice;
                cin >> bChoice;

                if (bChoice == 1)
                {
                    Buyer* newB = new Buyer("Temp", "Temp", "Temp");
                    cin >> *newB; // using overloaded >>
                    buyers[bCount] = newB;

                    pakWheels += buyers[bCount];
                    cout << "Registered, Your Buyer ID is: " << buyers[bCount]->getUserID() << endl;
                    bCount++;
                }
                else if (bChoice >= 2 && bChoice <= 6)
                {
                    cout << "Enter your Buyer ID: "; int id; cin >> id;
                    Buyer* currentBuyer = nullptr;
                    for(int i=0; i<bCount; i++)
                        if(buyers[i]->getUserID() == id) currentBuyer = buyers[i];

                        if(currentBuyer == nullptr)
                        {
                            cout << "Invalid Buyer ID." <<endl;
                            break;

                        }

                        if (bChoice == 2)
                        {
                            cout << "Enter Listing ID to favorite: ";
                            int lID;
                            cin >> lID;

                            for(int i=0; i<adCount; i++)
                            {
                                if(ads[i]->getListingID() == lID)
                                    currentBuyer->addToFavorites(ads[i]);
                            }
                        }
                        else if (bChoice == 3)
                            currentBuyer->displayFavorites();
                        else if (bChoice == 4)
                        {
                            cout << "Enter Listing ID to remove: ";
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
                            {
                                if(sellers[i]->getUserID() == sID)
                                    targetSeller = sellers[i];
                            }

                                if(targetSeller)
                                {
                                    cout << "Enter message: ";
                                    string msgText;
                                    cin.ignore();
                                    getline(cin, msgText);
                                    currentBuyer->draftMessage(targetSeller, msgText);
                                }
                                else cout << "Seller not found." << endl;
                        }
                        else if (bChoice == 6)
                            currentBuyer->viewInbox();
                }
                break;
            }

            case 4: //serach area
            {
                cout << "\n--- MARKETPLACE ---\n1. Search by Brand\n2. Search by Brand and Minimum Year\n3. Filter by Location\n4. Filter by Max Price\nEnter choice: ";
                int mChoice;
                cin >> mChoice;

                if (mChoice == 1)
                {
                    cout << "Enter Brand (ex: Honda): ";
                    string b;
                    cin >> b;
                    pakWheels.search(b);
                }
                else if (mChoice == 2)
                {
                    cout << "Enter Brand: ";
                    string b;
                    cin >> b;

                    cout << "Enter Min Year: ";
                    int y;
                    cin >> y;

                    pakWheels.search(b, y);
                }
                else if (mChoice == 3)
                {
                    cout << "Enter Location: ";
                    string l;
                    cin >> l;

                    pakWheels.filterByLocation(l);
                }
                else if (mChoice == 4)
                {
                    cout << "Enter max price (PKR): ";
                    double maxP;
                    cin >> maxP;

                    pakWheels.filterByMaxPrice(maxP);
                }
                break;
            }

            case 5:
            {
                running = false;
                cout << "Exiting system. Goodbye.\n";
                break;
            }

            default:
                cout << "Invalid choice, Try again.\n";
        }
    }

    // cleaning up local pointers, the Marketplace destructor will clean up its internal arrays
    // Vehicle objects are destroyed inside ListingBase destructor
    // The rest is handled to avoid duplicates

    return 0;
}
