#include <iostream>
#include <string>
using namespace std;

class Rectangle
{
	float length, width;
public:
	Rectangle(float len= 1.0, float wid = 1.0): length(len), width(wid) {}

	float getArea()
	{
		return length*width;
	}

	void isSquare()
	{
		if (width == length)
			cout << "It is a square"<< endl;
		else
			cout << "It is a Rectangle"<<endl;
	}
	void setLength(float len)
	{
		length = len;
	}

	void setWidth(float wid)
	{
		width = wid;
	}
};