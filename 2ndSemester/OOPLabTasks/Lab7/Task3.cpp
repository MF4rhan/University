#include <iostream>
#include <string>
using namespace std;

class Device
{
protected:
	const string deviceID;
	string status;
public:
	Device(string ID="N/A", string stat="OFF"): deviceID(ID), status(stat)	{}
	virtual ~Device()	{}

	virtual void turnOn()	{status="ON";}
	void turnOff()	{status="OFF";}
	string getStatus()	{return status;}
};

class Light: virtual public Device
{
protected:
	int brightness;
public:
	Light(string ID="N/A", string stat="OFF"): Device(ID, stat), brightness(0)	{}
	void turnOn() override { status="ON"; cout<<"Light "<<deviceID<<" turned ON"<<endl; }
	void dim(int level)
	{
		if(level <=100 && level>=0)
		{
			brightness=level;
			cout<<"Light "<<deviceID<<" brightness set to "<<level<<"%"<<endl;
		}
		else
			cout<<"Invalid Brightness Input.\n"<<endl;
	}

};

class Camera: virtual public Device
{
protected:
	bool isRecording;
public:
	Camera(string ID="N/A", string stat="OFF"): Device(ID, stat), isRecording(false)	{}

	void turnOn() override { status="ON"; cout<<"Camera "<<deviceID<<" started recording"<<endl; }
	void startRecording()
	{
		isRecording=true;
		cout<<"Camera "<<deviceID<<" started recording"<<endl;
	}
};

class Thermostat: public Light, public Camera
{
	int temperature;
public:
	Thermostat(string ID="N/A", string stat="OFF"):Device(ID,stat), Light(ID,stat), Camera(ID,stat), temperature(35)	{}
	void turnOn() override { status="ON"; cout<<"Thermostat "<<deviceID<<" temperature set to "<<temperature<<" degrees C"<<endl; }
	void setTemperature(int t)
	{
		temperature=t;
		cout<<"Thermostat "<<deviceID<<" temperature set to "<<t<<" degrees C"<<endl;
	}
};

class Routine
{
	const string routineID;
	string name;
	Device **devices;
	int count, capacity;
public:
	Routine(string ID="N/A", string n="N/A"): routineID(ID), name(n), count(0), capacity(1)	{devices = new Device*[capacity];}

	void addDevice(Device* d)
	{
		if(count==capacity)
		{
			capacity*=2;
			Device** temp = new Device* [capacity];

			for(int i=0; i<count; ++i)
				temp[i]=devices[i];

			delete[] devices;
			devices = temp;
			temp=nullptr;
		}
		devices[count++] = d;
	}

	void addDevice(Device* arr[], int l)
	{
		for(int i=0;i<l;++i)
			addDevice(arr[i]);
	}

	void execute()
	{
		for(int i=0; i<count; ++i)
		{
			devices[i]->turnOn();
		}
	}
	~Routine()	{delete[] devices;}
};

class Homeowner
{
private:
	const string homeownerID;
	string name;
public:
	Homeowner(string ID="N/A", string n="N/A"): homeownerID(ID), name(n)	{}

	void createRoutine(Routine r)	{r.execute();}

	void controlDevice(Device* d)	{d->turnOn();}
};


int main()
{
	Light l1("L1", "OFF");
	l1.dim(80);
	Camera c1("C1", "OFF");
	Thermostat t1("T1", "OFF");
	t1.setTemperature(24);

	l1.turnOn();
	l1.dim(50);
	c1.startRecording();
	t1.setTemperature(22);

	Routine r("R1", "Morning Mode");
	Device* arr[] = {&l1, &c1, &t1};
	r.addDevice(arr, 3);
	cout<<"Routine \"Morning Mode\" executed:"<<endl;
	r.execute();

	return 0;
}
