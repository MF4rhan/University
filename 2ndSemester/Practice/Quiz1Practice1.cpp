#include <iostream>
#include <string>
using namespace std;

class SmartDevice
{
	string deviceName;
	int batteryLevel;
public:
	SmartDevice()
	{
		deviceName = "Generic";
		batteryLevel = 50;
	}
	SmartDevice(string name, int level)
	{
		deviceName = name;
		if (level<=100 && level>=0)
		{
			batteryLevel = level;
		}
		else
		{
			cout << "ERROR: Invalid Battery Level, Default value set."<< endl;
			batteryLevel = 50;
		}
	}

	void setName(string name)
	{
		deviceName = name;
	}
	void setBattery(int level)
	{
		if (level<=100 && level>=0)
		{
			batteryLevel = level;
		}
		else
		{
			cout << "ERROR: Invalid Battery Level"<< endl;
		}
	}
	string getName()
	{
		return deviceName;
	}
	int getLevel()
	{
		return batteryLevel;
	}

	void displayStatus()
	{
		cout << "Device: "<< deviceName<< "	" <<"Battery Level: "<< batteryLevel<< endl;
	}
};


int main()
{
SmartDevice device1, device2("OPPO", 90), device3("Vivo", 200);
device1.displayStatus();
device2.displayStatus();
device3.displayStatus();
device1.setName("samsung");
device1.setBattery(70);
device2.setBattery(234);
device1.displayStatus();
device2.displayStatus();
device3.displayStatus();
return 0;
}