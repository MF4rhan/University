#include <iostream>
#include <string>
using namespace std;

class GYM
{
string *Name;
string Address; 
int  capacity;
int *fees;

public:
	GYM(string nam,string addr,int cap, int fe):Name(new string(nam)), Address(addr), capacity(cap), fees(new int(fe)) {}
	GYM(const GYM &aoi):Name(new string(*aoi.Name)), Address(aoi.Address), capacity(aoi.capacity), fees(new int(*aoi.fees)) {}
	~GYM()
	{
		delete Name;
		delete fees;
	}
};