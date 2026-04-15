#include <iostream>
#include <string>
using namespace std;

class SmartDevice
{
public:
    virtual void turn_on() = 0;

    virtual void turn_off() = 0;

    virtual double get_status() = 0;
};

class LightBulb: public SmartDevice
{
    bool is_on;
    int brightness;
public:
    LightBulb(bool on, int bright) : is_on(on), brightness(bright)
    {
    }

    void turn_on() override
    {
        is_on = true;
    }

    void turn_off() override
    {
        is_on = false;
    }

    double get_status() override
    {
        return (double)brightness;
    }
};

class Thermostat: public SmartDevice
{
    bool is_on;
    double temperature;

public:
    Thermostat(bool on, double temp) : is_on(on), temperature(temp)
    {
    }

    void turn_on() override
    {
        is_on = true;
    }

    void turn_off() override
    {
        is_on = false;
    }

    double get_status() override
    {
        return temperature;
    }
};

int main()
{
    LightBulb light1(false, 70);
    Thermostat therm1(false, 35.67);

    light1.turn_on();
    light1.turn_off();
    cout << "Light Bulb Brightness: " << light1.get_status() << "%" << endl;

    therm1.turn_on();
    therm1.turn_off();
    cout << "Thermostat Temperature: " << therm1.get_status() << "C" << endl;

    return 0;
};
