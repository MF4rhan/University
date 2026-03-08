#include <iostream>
#include <string>
using namespace std;
void inputValue(struct BaseBall player[]);
void getValue(struct BaseBall player[]);
void search(struct BaseBall player[]);

struct BaseBall
{
	string name;
	int runs;
	int hits;
};

int main()
{
	struct BaseBall player[3];
	int choice;
	do
	{
		cout << "1. Enter Player Data."<<endl;
		cout << "2. Show Player Data."<<endl;
		cout << "3. Search Player and Update"<<endl;
		cout << "4. Exit Program."<<endl;
		cout << "Enter your choice:"<<endl;
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				inputValue(player);
				break;
				
			case 2:
				getValue(player);
				break;
				
			case 3:
				search(player);
				break;
				
			case 4:
				break;
		}
		
	} while(choice!=4);
	
return 0;
}

void inputValue(BaseBall player[])
{
	for(int i=0;i<3;i++)
	{
		cout << "Enter Player "<<i+1<< " Data"<< endl;
		cout <<"Enter Player Name:";
		cin >>player[i].name;
		cout <<"Enter Number of Home Runs:";
		cin >>player[i].runs;
		cout <<"Enter Number of Hits:";
		cin >>player[i].hits;
		cout << endl;
	}
}

void getValue(BaseBall player[])
{
	for(int i=0;i<3;i++)
	{
		cout << "Player "<<i+1<< " Data"<< endl << endl;
		cout <<"Name: "<< player[i].name<<endl;
		cout <<"Home Runs: "<< player[i].runs<<endl;
		cout <<"Hits: "<< player[i].hits<<endl<<endl;
	}
}

void search(BaseBall player[])
{
	string namo;
	int flag=0;
	int choice;
	int i=0;
	cout << "Enter player name to search: " <<endl;
	cin >> namo;
	for(i=0; i<3; i++)
	{
		if(namo == player[i].name)
		{
			cout << "Player "<<i+1<< " Data"<< endl << endl;
			cout <<"Name: "<< player[i].name<<endl;
			cout <<"Home Runs: "<< player[i].runs<<endl;
			cout <<"Hits: "<< player[i].hits<<endl;
			cout<<endl;
			flag=1;
			break;
		}
	}
	if (flag=0)
	{
		cout <<"Player not found."<< endl << endl;
	}
	do
	{
		cout << "1. Update Player Data."<<endl;
		cout << "2. Return to main menu."<<endl;
		cout << "Enter your choice:"<<endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout <<"Enter Player Name:";
				cin >>player[i].name;
				cout <<"Enter Number of Home Runs:";
				cin >>player[i].runs;
				cout <<"Enter Number of Hits:";
				cin >>player[i].hits;
				cout<<endl;
				return;
			
			case 2:
				break;
		}
	}while(choice!=2);
}

