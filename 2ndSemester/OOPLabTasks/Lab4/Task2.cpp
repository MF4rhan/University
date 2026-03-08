#include <iostream>
#include <string>
using namespace std;

class Citizen
{
    const string ID;
    string Name;
    string Nationality;
    public:
    Citizen(string IDO, string nam, string nation): ID(IDO), Name(nam), Nationality(nation) {}
    void getDetails()
    {
        cout<< "ID: "<< ID<< endl;
        cout << "Name: " << Name << endl;
        cout << "Nationality: " << Nationality << endl;
    }
    //void setID(string IDO) {ID = IDO;} //This gives error because we are trying to assign to a constant
};

int main()
{
    Citizen obj1("1", "Farhan", "Japan");
    Citizen obj2("2", "Faraz", "Saudi Arabia");
    Citizen obj3("3", "Ahmed", "China");

    obj1.getDetails();
    obj2.getDetails();
    obj3.getDetails();
return 0;
}
