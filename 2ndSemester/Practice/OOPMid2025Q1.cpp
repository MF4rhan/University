#include <iostream>
#include <string>
using namespace std;

class User
{
	string name, about, number;
	public:
	User(string n="", string a="", string num="0") : name(n), about(a), number(num) {}
	void setAttributes(string n, string a, string num)
	{
		name=n;
		about=a;
		number=num;
	}
	string getName() const {return name;}
	string getAbout() const {return about;}
	string getNumber() const {return number;}
};

class Message
{
	string SenderName, text, timestamp;
	public:
	Message():SenderName(""), text(""), timestamp("") {}
	void setAttributes(string sn, string t, string ts)
	{
		SenderName = sn;
		text = t;
		timestamp = ts;
	}
	string getSenderName() const {return SenderName;}
	string getText() const {return text;}
	string getTimeStamp() const {return timestamp;}
};

class WhatsAppGroup
{
	string groupInfo, groupName, creationDate;
	User *admins[5], *memberList[20];
	int maxAd = 5, maxMem = 20, admincount, membercount, mmsgcount;
	Message *Messages = new Message[10];
public:
	~WhatsAppGroup()	{delete[] Messages;}
	WhatsAppGroup(string GI="", string GN="", string CD=""): groupInfo(GI), groupName(GN), creationDate(CD), admincount(0), membercount(0), mmsgcount(0) 
	{
		for (int i = 0; i < maxMem; ++i)
		{
			if (i<5)
			{
				admins[i]=nullptr;
			}
			memberList[i]=nullptr;
		}
	}
	WhatsAppGroup(const WhatsAppGroup& cop)
	{
		groupInfo = cop.groupInfo;
		groupName = cop.groupName;
		creationDate = cop.creationDate;
		for (int i = 0; i < maxMem; ++i)
		{
			if (i<5)
			{
				admins[i] = cop.admins[i];
			}
			if (i<10)
			{
				Messages[i]=cop.Messages[i];
			}
			memberList[i] = cop.memberList[i];
		}
	}

	void AddAdmin(User* u)
	{
		if (admincount <5)
		{
			for (int i = 0; i < maxAd; ++i)
			{
				if (admins[i]==nullptr)
				{
					admins[i] = u;
					admincount++;
					break;
				}
			}
		}
		else
		{
			cout << "The group already has 5 Admins."<<endl;
		}
	}

	void removeAdmin(User* u)
	{
		if (admincount<=1)
		{
			cout<<"The group must have at least 1 Admin, therefore cannot be removed." <<endl;
		}
		else
		{
			for (int i = 0; i < maxAd; ++i)
			{
				if (u==admins[i])
				{
					admins[i]=nullptr;
					admincount--;
					break;
				}
				else if (i==maxAd)
				{
					cout << "This User is not a part of the group."<<endl;
				}
			}
		}
	}

	void sendMessage(Message m)
	{
		if (mmsgcount==10)
		{
			for (int i = 0; i < 9; ++i)
			{
				Messages[i]=Messages[i+1];
			}
			Messages[9]= m;
		}
		else
		{
			Messages[mmsgcount]=m;
		}
	}

	//The question did'nt ask for a addMember method, but it would be pretty funny if there wasnt one, would it?
	void addMember(User *u)
	{
		if (membercount<maxMem)
		{
			for (int i = 0; i < maxMem; ++i)
			{
				if (memberList[i]==nullptr)
				{
					memberList[membercount]= u;
					membercount++;
					break;
				}
			}
			
		}
		else
		{
			cout << "Max members reached."<<endl;
		}
	}

	void removeMember(User* u)
	{
		for (int i = 0; i < maxMem; ++i)
		{
			if (u == memberList[i])
			{
				memberList[i]=nullptr;
				membercount--;
			}
			else if (i==maxMem-1)
			{
				cout <<"This user is not a member of this group." << endl;
			}
		}
	}

};
