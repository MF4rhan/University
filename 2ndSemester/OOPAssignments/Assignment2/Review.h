#pragma once
#include <string>
using namespace std;

class Review 
{
private:
    int reviewID;
    int reviewerID;
    int targetSellerID;
    int rating;
    string comment;
    static int totalReviews;
    bool isFlagged;

public:
    //constructors
    Review();
    Review(int reviewerID, int targetSellerID, int rating, string comment);

    //getters
    int getReviewID() const;
    int getReviewerID() const;
    int getTargetSellerID() const;
    int getRating() const;
    string getComment() const;
    static int getTotalReviews();
    bool getIsFlagged() const;

    //setters
    void setRating(int rating);
    void setComment(string comment);

    //methods
    void editReview(string newText);
    bool validateRating();
    void displayReview();
    void flagAsInappropriate();
};