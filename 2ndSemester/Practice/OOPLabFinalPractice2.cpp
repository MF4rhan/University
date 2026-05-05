#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <fstream>
using namespace std;

template <typename T>
class Weapon
{
protected:
    T damage;

public:
    Weapon(T var): damage(var)
    {
    }
};


template <typename T>
class Sword : public Weapon<T>
{
private:
    int level;

public:
    Sword(T var, int lev) : Weapon<T>(var), level(lev)
    {}

void display()
    {
        cout << "Damage: " << this->damage << "\n";
        cout << "Level: " << level << "\n"; //or this->level;
    }
};

int main()
{
    Sword<float> S1(100.4, 10);
    S1.display();

    return 0;
}
