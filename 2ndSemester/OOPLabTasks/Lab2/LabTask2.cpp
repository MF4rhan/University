#include <iostream>
#include <string>
using namespace std;

class Date
{
	string months[12] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int date, month, year;
	public:
	Date(int d, int m, int y)
	{
		if (d>=1 && d<=31)
			date=d;
		else
		{
			cout<< "Invalid date, default value of Date Assigned."<< endl<< endl;
			date=30;
		}
		
		if (m>=1 && m<=12)
			month=m;
		else
		{
			cout<< "Invalid month, default value of Month Assigned."<< endl<< endl;
			month=1;
		}
		
		if (y>=0)
			year=y;
		else
		{
			cout<< "Invalid year, default value of Year Assigned."<< endl<< endl;
			year=2026;
		}
			
	}
	
	void formatOne()
	{
		cout << month << "/" << date << "/" << year%100<< endl;
	}
	
	void formatTwo()
	{
		cout << months[month-1] <<" "<< date<<", "<<year <<endl;
	}
	
	void formatThree()
	{
		cout << date<< " "<< months[month-1]<< " " << year<<endl;
	}
};

int main()
{
	Date bolo1(5, -2, 2030), bolo2(0, 0, -4300);
	bolo1.formatOne();
	bolo1.formatTwo();
	bolo1.formatThree();
	
	bolo2.formatOne();
	bolo2.formatTwo();
	bolo2.formatThree();
	
return 0;
}
