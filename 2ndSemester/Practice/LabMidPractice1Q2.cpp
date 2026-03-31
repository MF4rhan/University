#include <iostream>
#include <string>
using namespace std;

class patient
{
  string name;
  const int id;
  int heartMonitorCount;
  int bpMonitorCount;
  int oxygenSensorCount;

  heartMonitor* HM;
  BPMonitor* BPM;
  oxygenSensor* OS;

public:
    patient(string nam, int i): name(nam), id(i), heartMonitorCount(0), bpMonitorCount(0), oxygenSensorCount(0)
    {
        HM = new heartMonitor[2];
        BPM = new BPMonitor[2];
        OS = new oxygenSensor[3];
    }

    void addHeartMonitor(HeartMonitor& H)
    {
        if(heartMonitorCount<2)
            HM[heartMonitorCount++]=H;
        else
           cout<<"Max number of heart rate monitors attached."<<endl;
    }

    void addBPMonitor(BPMonitor& B)
    {
        if(bpMonitorCount<2)
            BP[bpMonitorCount++]=B;
        else
            cout<<"Max number of BP Monitors attached."<<endl;
    }
    void addOxygenSensor(oxygenSensor O)
    {
        if(oxygenSensorCount<3)
            OS[oxygenSensorCount++]=O;
        else
            cout<<"Max number of Oxygen Sensors attached."<<endl;
    }

    void calcualteRiskScore()
    {
        //idk the risk logic or formula, wasn't mentioned in the paper.
        return;
    }

    display()
    {
        cout<<"Name: "<<name<<", ID: "<<id<<endl<<endl;
        for(int i=0; i<HeartMonitorCount; i++)
            cout<<"Heart Monitor "<<i+1<<": HeartRate: "<<HM[i].getHeartRate()<<" bpm"<<endl;
        cout<<endl;
        for(int i=0; i<bpMonitorCount; i++)
            cout<<"BP Monitor "<<i+1<<": "<<"Systolic: "<<BPM[i].getsys()<<" mmHg, Diastolic: "<<BPM[i].getdiastolic()<<endl;
        cout<<endl;
        for(int i=0; i<oxygenSensorCount; i++)
            cout<<"Oxygen Sensor "<<i+1<<": Oxygen Level: "<<HM[i].getHeartRate()<<"%"<<endl;
        cout<<endl;
        cout<<"Total Number of Heart Montiors: "<<HeartMonitorCount<<endl;
        cout<<"Total Number of BP Monitors: "<<bpMonitorCount<<endl;
        cout<<"Total Number of Oxygen Sensors: "<<oxygenSensorCount<<endl;
    }

};

class heartMonitor
{
  int heartRate;
public:
    heartMonitor(int hR): heartRate(hR) {}
    int getHeartRate()
    {return heartRate;}
};

class BPMonitor
{
  int systolic;
int diastolic;
public:
    BPMonitor(int sys, int dia): systolic(sys), diastolic(dia)  {}
    int getsys()
    {return systolic;}
    int getdiastolic()
    {return diastolic;}
};

class oxygenSensor
{
  int oxygenLevel;
public:
    oxygenSensor(int ol):oxygenLevel(ol)    {}
    int getOxygen()
    {return oxygenLevel;}
};

int main()
{

}
