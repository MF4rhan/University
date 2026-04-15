#include <iostream>
#include <string>
using namespace std;

class Activity
{
public:
    virtual void calculate_calories_burned() = 0;
};

class Running: public Activity
{
private:
    double distance_km;
    double time_min;

public:
    Running(double distance, double time)
    : distance_km(distance), time_min(time)
    {
    }

    void calculate_calories_burned() override
    {
        //using some random calorie formula for the sake of demonstration
        double calories = (distance_km * 60) + (time_min * 2);
        cout << "Calories burned by Running: " << calories << endl;
    }
};

class Cycling: public Activity
{
private:
    double speed_kmph;
    double time_hrs;

public:
    Cycling(double speed, double time)
    : speed_kmph(speed), time_hrs(time)
    {
    }

    void calculate_calories_burned() override
    {
        //using some random calorie formula for the sake of demonstration
        double calories = (speed_kmph * time_hrs) * 35;
        cout << "Calories burned by Cycling: " << calories << endl;
    }
};

int main()
{
  //making objects
    Running run1(2, 20);
    Cycling cycle1(30, 5);

    //testing the overrided method of Running class
    run1.calculate_calories_burned();
    cout << endl;

    //testing the overrided method of Cycling class
    cycle1.calculate_calories_burned();

    return 0;
};
