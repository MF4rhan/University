#include <iostream>
#include <string>
using namespace std;

class Robot
{
//int w,a,s,d;
int x,y;
public:
//constructors
Robot(): x(0),y(0) {}
Robot(int xo, int yo): x(xo),y(yo) {}
Robot(const Robot &copy)
	{
		x=copy.y;
		y=copy.x;
	}
//movement methods
void moveLeft(int d) {x-=d;}
void moveRight(int d) {x+=d;}
void moveUp(int d) {y+=d;}
void moveDown(int d) {y-=d;}
//main command method
void commands(string act, int d)
	{
		for (int i = 0; i < act.size(); ++i)
		{
			if (act[i]=='L')	{moveLeft(d);}
			else if(act[i]=='R')	{moveRight(d);}
			else if(act[i]=='F')	{moveUp(d);}
			else if(act[i]=='B')	{moveDown(d);}
			else {cout<<"Invalid movement, Please try again."<<"\n\n";}
		}
	}
	//accessors
	int getX()	{return x;}
	int getY()	{return y;}
	//mutators are not needed in my opinion, just use command function.
};

int main()
{
	Robot Car;
	Car.commands("RRRLFBB", 3);
	cout << "X position: "<< Car.getX()<<"\n";
	cout << "Y position: "<< Car.getY()<<"\n\n";
	Robot CarSwap(Car);
	cout << "X position: "<< CarSwap.getX()<<"\n";
	cout << "Y position: "<< CarSwap.getY()<<"\n";
return 0;
}