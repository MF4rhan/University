#include <iostream>
#include <string>
using namespace std;

class MusicalComposition
{
protected:
	string title, composer, year;
public:
	void setData(string t, string c, string y)
	{
		title = t;
		composer = c;
		year = y;
	}
	void display() const
	{
		cout <<"Title:	 "<<title<<endl;
		cout <<"Composer:"<<composer<<endl;
		cout <<"Year:	 "<<year<<endl;
	}
};

class NationalAnthem: public MusicalComposition
{
protected:
	string nation;
public:
void setNation(string n)	{nation = n;}
void display() const
	{
		cout <<"Title:	 "<<title<<endl;
		cout <<"Composer:"<<composer<<endl;
		cout <<"Year:	 "<<year<<endl;
		cout <<"Nation:	 "<<nation<<endl;
	}
};

int main()
{
	NationalAnthem A1;
	A1.setData("Qaumi Tarana", "Hafeez Jalandari", "1950s something");
	A1.setNation("Pakistan");
	A1.display(); //because child class has its own display, it will use that over the parent.
	A1.MusicalComposition::display(); //here using parent
return 0;
}