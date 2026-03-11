#include <iostream>
#include <string>
#include <array>
using namespace std;

class PrayerTracker
{
	array <string, 5> dailyPrayerTimes;
	array<array<string,2>, 7> weeklyPrayerTimes;
public:
	void setDailyPrayerTimes()
	{
		for (int i = 0; i < 5; ++i)
		{
			cout <<"Enter Time for Prayer#"<<i<<": "<<endl;
			cin>>dailyPrayerTimes[i];
		}
	}

	void setWeeklyPrayerTimes()
	{
		for (int i = 0; i < 7; ++i)
		{
			cout << "Enter time for Jummah Prayer for Day#"<<i<<"; "<<endl;
			cin >>weeklyPrayerTimes[i][0];
		}
		for (int i = 0; i < 7; ++i)
		{
			cout << "Enter time for Eid Prayer for Day#"<<i<<"; "<<endl;
			cin >>weeklyPrayerTimes[i][1];
		}
	}

	const string* getDailyPrayeTimes()	 const 	{return dailyPrayerTimes;}
	const string* getWeeklyPrayerTimesColumns() const 	{return weeklyPrayerTimes;}
};

//in progress