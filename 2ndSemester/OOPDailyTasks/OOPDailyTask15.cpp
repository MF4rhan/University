//25K-0538  Muhammad Farhan
#include <iostream>
#include <string>
using namespace std;
class SelfDrivingAI;
class EntertainmentAI;


class AiComponent
{
protected:

public:
    virtual void performTask()  {}
};

class NavigationAI: virtual public AiComponent
{
protected:
  string start, destination;
  int estimated_time; //in minutes
public:
    NavigationAI(string s, string d, int e):start(s), destination(d), estimated_time(e) {}

    void performTask () override
    {
        cout<<"The AI Module is performing Navigation"<<endl;
    }
    friend void operator*(NavigationAI& n, int i);
    friend bool operator==(const SelfDrivingAI& A, const NavigationAI& N);
};

class EntertainmentAI: virtual public AiComponent
{
protected:
    int volume; //0-100
    string playlist[30]; //playlist
    int count; //to counter number of songs added.
public:
    EntertainmentAI(int vol): volume(vol), count(0)   {}
    void performTask () override
    {
        cout<<"The AI Module is performing entertainment."<<endl;
    }
    friend void operator+=(EntertainmentAI& A1, const EntertainmentAI& A2);
};

class SelfDrivingAI: public NavigationAI, public EntertainmentAI
{
  float currentSpeed; //kmph
public:
    SelfDrivingAI(string s, string d, int e, int vol, float cs): NavigationAI(s, d, e), EntertainmentAI(vol), currentSpeed(cs)  {}
    void performTask () override
    {
        cout<<"The AI Module is performing self driving."<<endl;
    }
    friend bool operator==(const SelfDrivingAI& A, const NavigationAI& N);
};

//operator overloading below.
void operator*(NavigationAI& n, int i)
{
    n.estimated_time *= i;
};

bool operator==(const SelfDrivingAI& A, const NavigationAI& N)
{
    if(A.estimated_time==N.estimated_time)
        return true;
    else
        return false;
};

void operator+=(EntertainmentAI& A1, const EntertainmentAI& A2)
{
    int save=0;
    for(int i=0; i < 30; i++)
    {
        if(A1.playlist[i]=="")
        {
            for(int j=save; j<30; j++)
            {
                if (A2.playlist[j]!="")
                {
                    A1.playlist[i]=A2.playlist[j];
                    save=j+1;
                    break;
                }
            }
        }
    }
}

int main()
{
    NavigationAI N1("DHA Phase 5", "FAST University Main Campus", 90);
    SelfDrivingAI S1("DHA Phase 5", "FAST University Main Campus", 90, 50, 60);
    EntertainmentAI E1(30), E2(40);

    if (S1==N1)
        cout<<"Routes are identical."<<endl;
    else
        cout<<"Routes are different."<<endl;

    N1*5;

    if (S1==N1)
        cout<<"Routes are identical."<<endl;
    else
        cout<<"Routes are different."<<endl;

    E1+=E2; //I know, we have not added anything to the playlists yet since we havent made any setters, but lets assume we had one.

    return 0;
}
