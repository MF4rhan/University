#include <iostream>
#include <string>
using namespace std;

class Book
{
	string title;
	string author;
	double price;
public:
	Book(string t, string a) : title(t), author(a), price(0.0) {}

	Book(string t, string a, double p): title(t), author(a), price(p) {}

	void setPrice(double p)
	{
		price=p;
	}
	void Display()
	{
		cout <<"Title: "<< title<<"	"<<"Author: "<<author<< "	"<<"Price: "<<price<<endl;
	}
};

int main()
{
	Book books1("Booker", "Farhan"), books2("Butcher", "Hamza", 30.99);
	books1.setPrice(13.98);
	books1.Display();
	books2.Display();
return 0;
}