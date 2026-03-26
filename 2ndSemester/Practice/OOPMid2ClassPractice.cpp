//25K-0538, Muhammad Farhan
#include <iostream>
#include <string>
using namespace std;

class Stairs
{
protected:
int numSteps;
float stepHeight;
float stepWidth;
static int stairsCount;
string location;
public:
    Stairs(int nS, float sH, float sW, string loc)
    :numSteps(nS), stepHeight(sH), stepWidth(sW), location(loc)
    {stairsCount++;}

    int getCount() const
    {
        return stairsCount;
    }
};

class ConveyorBelt
{
protected:
    float length;
    float width;
    float speed;
    float capacity;
    static int conveyorbeltCount;
public:
    ConveyorBelt(float len, float wid, float spe, float cap)
    :length(len), width(wid), speed(spe)
    {
        capacity = (((int)cap/10)+((int)cap%10))/2.0;
        conveyorbeltCount++;
    }
    ConveyorBelt(float spe, float cap)
    :speed(spe), length(10), width(10)
    {
        capacity = (((int)cap/10)+((int)cap%10))/2.0;
        conveyorbeltCount++;
    }

    virtual void operateBelt(int currWeight)
    {
        if(currWeight<5)
        {
            speed = speed*2;
            cout<<"The time required is"<< length/speed<< " minutes."<<endl;

        }
        else if (currWeight>50)
        {
            speed = speed/2;
             cout<<"The time required is"<< length/speed<< " minutes."<<endl;
        }
        else
        {
             cout<<"The time required is"<< length/speed<< " minutes."<<endl;
        }
    }
    int getBeltCount() const
    {
        return conveyorbeltCount;
    }

   friend class IndustrialBelt;
};

class Escalator: public Stairs, public ConveyorBelt
{
    char direction;
    int currentLocation;
    static int escalatorCount;
public:
    Escalator(int nS, float sH, float sW, string loc, float spe, float cap, char D, int curr)
    : Stairs(nS, sH, sW, loc), ConveyorBelt(spe, cap), direction(D), currentLocation(curr)
    {escalatorCount++;}

    void moveUp(int weight)
    {
        if(weight>capacity)
        {
            cout<<"Overweight, Escalator cannot work."<<endl;
            return;
        }
        else if (weight>capacity*0.8)
        {
            cout<<"Weight above 80 percent of capacity, reducing speed, Escalator going up."<<endl;
            speed= speed*0.8;
            direction = 'U';
            return;
        }
        else
        {
            cout<<"Escalator working normally, going up."<<endl;
            direction = 'U';
        }

    }
    void moveDown(int Weight)
    {
        if(Weight>capacity)
        {
            cout<<"Overweight, Escalator cannot work."<<endl;
            return;
        }
        else
        {
            cout<<"Escalator working normally, going down."<<endl;
            direction = 'D';
            speed = speed*1.1;
        }
    }

    int getEscalator()  const
    {
        return escalatorCount;
    }

    void operator++()
    {
        if(direction=='U')
            currentLocation++;
        else
            return;
    }
    void operator--()
    {
        if(direction=='D')
            currentLocation--;
        else
            return;
    }

};

class IndustrialBelt :public ConveyorBelt
{
    float minWeight;
    bool operable;
    static int industrialCount;
public:
    IndustrialBelt(float len, float wid, float spe, float cap, float min, bool op)
    : ConveyorBelt(len, wid, spe, cap), minWeight(min), operable(op)    {industrialCount++;}

    bool checkWeight(int currWeight)
    {
        if(currWeight<minWeight)
        {operable = false; return false;}
        else
        {operable = true; return true;}
    }

    void operateBelt(int currWeight) override
    {
        if(currWeight<5 && operable && currWeight>minWeight)
        {
            ConveyorBelt::operateBelt(currWeight);
        }
        else if (currWeight>50 && operable && currWeight>minWeight)
        {
            ConveyorBelt::operateBelt(currWeight);
        }
        else if (operable && currWeight>minWeight)
        {
          ConveyorBelt::operateBelt(currWeight);
        }
    }

    void operateBelt(int currWeight, int sped)
    {
        if(currWeight<5 && operable && currWeight>minWeight)
        {
            speed = sped;
            ConveyorBelt::operateBelt(currWeight);
        }
        else if (currWeight>50 && operable && currWeight>minWeight)
        {
            speed = sped;
            ConveyorBelt::operateBelt(currWeight);
        }
        else if (operable && currWeight>minWeight)
        {
            speed = sped;
            ConveyorBelt::operateBelt(currWeight);
        }
    }

    IndustrialBelt& operator =(const ConveyorBelt& belt)
    {
        length = belt.length;
        width = belt.width;
        speed= belt.speed;
        capacity = belt.capacity;
        return *this;
    }
};


int Stairs::stairsCount=0;
int ConveyorBelt::conveyorbeltCount=0;
int Escalator:: escalatorCount=0;
int IndustrialBelt:: industrialCount=0;

int main()
{

}
