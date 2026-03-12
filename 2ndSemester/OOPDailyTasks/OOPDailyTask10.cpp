//Roll: 25K-0538, Muhammad Farhan
#include <iostream>
#include <string>
using namespace std;

struct weeklyTiming	{string Times[7][2];};

class PrayerTracker
{
protected:
	string dailyPrayerTimes[5];
	weeklyTiming weeklyPrayerTimes;
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
			cin >>weeklyPrayerTimes.Times[i][0];
		}
		for (int i = 0; i < 7; ++i)
		{
			cout << "Enter time for Eid Prayer for Day#"<<i<<"; "<<endl;
			cin >>weeklyPrayerTimes.Times[i][1];
		}
	}

	const string* getDailyPrayeTimes()	 const 	{return dailyPrayerTimes;}
	const weeklyTiming& getWeeklyPrayerTimesColumns() const 	{return weeklyPrayerTimes;}
};

class DailyPrayerTracker: public PrayerTracker
{
protected:
	string* prayerHistory;
	int count;
public:
	DailyPrayerTracker():prayerHistory(nullptr), count(0)	{}
	~DailyPrayerTracker()	{delete[] prayerHistory;}
	void addPrayerTime(string time)
	{
		string* temp = prayerHistory;
		prayerHistory = new string[count+1];

		for (int i = 0; i < count; ++i)
			prayerHistory[i]=temp[i];
		prayerHistory[count]=time;
		++count;
		delete[] temp;
	}

	const string* getPrayerHistory() const	{return prayerHistory;}
};

class WeeklyPrayerTracker: public PrayerTracker
{
	protected:
	string* prayerHistory;
	int count;
public:
	WeeklyPrayerTracker():prayerHistory(nullptr), count(0)	{}
	~WeeklyPrayerTracker()	{delete[] prayerHistory;}
	void addPrayerTime(string time)
	{
		string* temp = prayerHistory;
		prayerHistory = new string[count+1];

		for (int i = 0; i < count; ++i)
			prayerHistory[i]=temp[i];
		prayerHistory[count]=time;
		++count;
		delete[] temp;
	}

	const string* getPrayerHistory() const	{return prayerHistory;}
};

class PrayerUpdater: private PrayerTracker
{
public:
	void dailyPrayerTimeUpdate(int index, string newtime)
	{
		if (index >= 0 && index<=4)
			dailyPrayerTimes[index]=newtime;
		else
			cout<<"Invalid Index Input.\n"<<endl;
	}
	void weeklyPrayerTimesUpdate(int row, int col, string newtime)
	{
		if (row>=0 && row<=6)
		{
			if (col>=0 && col<=1)
				weeklyPrayerTimes.Times[row][col] = newtime;
			else
				{cout<<"Invalid Column Input.\n"<<endl; return;}
		}
		else
			{cout<<"Invalid Row Input.\n"<<endl; return;}
	}
};

class DailyRemidner : public DailyPrayerTracker
{
protected:
	string reminders[5];
public:
	void setReminder(int index, string time)
	{
		if (index>=0 && index<=4)
			reminders[index]=time;
		else
			cout <<"Invalid Prayer Index.\n"<<endl;
	}
	string getReminder(int index) const
	{
		if (index>=0 && index<=4)
			return reminders[index];
		else
			{cout <<"Invalid Prayer Index.\n"<<endl;	return "Error.";}
	}
};