#include "Review.h"
#include <iostream>
using namespace std;

//static variable definition
int Review::totalReviews = 0;

//constructors
Review::Review()
: reviewID(totalReviews++), reviewerID(0), targetSellerID(0),   rating(1), comment("N/A"), isFlagged(false)   {}

Review::Review(int reviewer, int targetSeller, int r, string c)
: reviewID(totalReviews++), reviewerID(reviewer), targetSellerID(targetSeller), rating(r), comment(c), isFlagged(false)   {}

//getters
int Review::getReviewID() const {return reviewID;}
int Review::getReviewerID() const   {return reviewerID;}
int Review::getTargetSellerID() const   {return targetSellerID;}
int Review::getRating() const   {return rating;}
string Review::getComment() const   {return comment;}
int Review::getTotalReviews()   {return totalReviews;}
bool Review::getIsFlagged() const   {return isFlagged;}

//setters
void Review::setRating(int r)           { rating = r; }
void Review::setComment(string c)       { comment = c; }

//methods
void Review::editReview(string newText) 
{
    comment = newText;
    cout << "Review " << reviewID << " updated." << endl;
}

bool Review::validateRating() 
{
    if (rating >= 1 && rating <= 5)
        return true;
    cout << "Invalid rating. Must be between 1 and 5." << endl;
    return false;
}

void Review::displayReview() {
    cout <<"--------------------------"<<endl;
    cout <<"Review ID:\t\t"<< reviewID<< endl;
    cout <<"Reviewer ID:\t\t"<< reviewerID<< endl;
    cout <<"Seller ID:\t\t"<<targetSellerID<< endl;
    cout <<"Rating:\t\t"<<rating << "/5"<< endl;
    cout <<"Comment:\t\t"<< comment<< endl;
    cout <<"Flagged:\t\t"<< (isFlagged ? "Yes" : "No")<<endl;
    cout <<"--------------------------" <<endl;
}

void Review::flagAsInappropriate() 
{
    isFlagged = true;
    cout << "Review "<<reviewID<<" has been flagged for Admin attention."<<endl;
}