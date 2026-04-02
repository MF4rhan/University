#include <iostream>
#include <string>
using namespace std;

class Device
{
protected:
    const int DeviceID;
    string device_type;
    double power_rating;
    bool status;

public:
    Device(int id, string deviceT, double powerR, bool stat)
    :DeviceID(id), device_type(deviceT), power_rating(powerR), status(stat)
    {
    }

    virtual void turnOn()
    {
        status = true;
    }

    virtual void turnOff()
    {
        status = false;
    }

    virtual double calculatePowerUsage(int hours) = 0;
};

class Lights: public Device
{
public:
    Lights(int id, string deviceT, double powerR, bool stat)
    : Device(id, deviceT, powerR, stat)
    {
    }

    double calculatePowerUsage(int hours) override
    {
        return power_rating * hours;
    }
};

class Fan: public Device
{
    int fan_speed;

public:
    Fan(int id, string deviceT, double powerR, bool stat, int fanS)
    : Device(id, deviceT, powerR, stat), fan_speed(fanS)
    {
    }

    double calculatePowerUsage(int hours) override
    {
        return power_rating * hours * fan_speed;
    }
};

class AC: public Device
{
  int current_temperature;
  int desired_temperature;


public:
    AC(int id, string deviceT, double powerR, bool stat, int temperature, int desiredTemp)
    : Device(id, deviceT, powerR, stat), current_temperature(temperature), desired_temperature(desiredTemp)
    {
    }

    void turnOn() override
    {
        status = true;
        current_temperature = desired_temperature;
    }

    void turnOff() override
    {
        current_temperature = desired_temperature;
        status = false;
    }

    double calculatePowerUsage(int hours) override
    {
        return power_rating * hours * (1 - (current_temperature - desired_temperature) / 100);
    }
};

class SecuritySystem: public Device
{
    bool system_status_check;
    bool intrusion_detection;

public:
    SecuritySystem(int id, string deviceT, double powerR, bool stat, bool statusCheck, bool intrusion = false)
    : Device(id, deviceT, powerR, stat), system_status_check(statusCheck), intrusion_detection(intrusion)
    {
    }

    void turnOff() override
    {
        if(system_status_check == true)
        {
            status = false;
        }
        else
        {
            cout << "System Status Check Failed." << endl;
            intrusion_detection = true;
        }
    }

    double calculatePowerUsage(int hours) override
    {
        return power_rating + (system_status_check ? 500 : 100);
        //Question doesn't mention the rate, so I made my own.
    }

    friend void access_security_logs(SecuritySystem& system);
    friend class MaintenanceTool;
};

class User
{
protected:
    const string user_id;
    string user_role;
    int access_level;

public:
    User(string id, string role, int level)
    : user_id(id), user_role(role), access_level(level)
    {
    }

    friend void access_security_logs();

    void view_accessible_devices()
    {
        if (access_level == 1)
        {
            cout << "1. Lights \n 2. Fans \n 3. Air Conditioners" << endl;
        }
        else if (access_level == 2)
        {
           cout << "1. Lights \n 2. Fans \n 3. Air Conditioners \n 4. Security System" << endl;
        }
    }

    void show_security_logs(SecuritySystem& system)
    {
        if (user_role == "Maintenance Staff" || user_role == "Maintenance staff")
        {
            access_security_logs(system);
        }
        else
        {
            cout << "Access Denied." << endl;
        }
    }

};

void access_security_logs(SecuritySystem& system)
{
    cout << "Security Logs Accessed: " << endl;
    if (system.intrusion_detection == true)
    {
        cout << "-Intrusion Detected" << endl;
        cout << "-System Reset Required" << endl;
    }
    else
    {
        cout << "No Logs Recorded" << endl;
    }
}

class MaintenanceTool
{
public:
    void reset_security_alerts(SecuritySystem& system)
    {
        system.intrusion_detection = false;
    }
    //This class could have been a function but, the question's requirement I suppose.
};

int main()
{
    Lights light(101, "Light", 60.0, false);
    Fan fan(102, "Fan", 80.0, false, 3);
    AC ac(103, "AC", 200.0, false, 30, 22);
    SecuritySystem sec(104, "Security System", 150.0, false, true);

    User regular_user("U01", "Regular User", 1);
    User maintenance_user("U02", "Maintenance Staff", 2);

    cout << "--- Turning Devices On ---" << endl;
    light.turnOn();
    fan.turnOn();
    ac.turnOn();
    sec.turnOn();

    cout << endl;

    cout << "--- Power Usage (5 hours) ---" << endl;
    cout << "Lights: " << light.calculatePowerUsage(5) << "Watts" << endl;
    cout << "Fan: " << fan.calculatePowerUsage(5) << "Watts" << endl;
    cout << "AC: " << ac.calculatePowerUsage(5) << "Watts" << endl;
    cout << "Security System: " << sec.calculatePowerUsage(5) << "Watts" << endl;

    cout << endl;

    cout << "--- Accessible Devices ---" << endl;
    cout << "Regular User: " << endl;
    regular_user.view_accessible_devices();
    cout << "Maintenance Staff: " << endl;
    maintenance_user.view_accessible_devices();

    cout << endl;

    cout << "--- Security Log Access ---" << endl;
    cout << "Regular User attempts: " << endl;
    regular_user.show_security_logs(sec);
    cout << "Maintenance Staff attempts: " << endl;
    maintenance_user.show_security_logs(sec);

    cout << endl;

    cout << "--- Triggering Intrusion ---" << endl;
    SecuritySystem sec2(105, "Security System", 150.0, false, false);
    sec2.turnOff();
    maintenance_user.show_security_logs(sec2);

    cout << endl;

    cout << "--- Resetting Intrusion Alert ---" << endl;
    MaintenanceTool tool;
    tool.reset_security_alerts(sec2);

    cout << endl;

    cout << "Alert reset. Checking logs again: " << endl;
    maintenance_user.show_security_logs(sec2);

    return 0;
}
