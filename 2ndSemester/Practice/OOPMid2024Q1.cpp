#include <iostream>
#include <string>
using namespace std;

class Player
{
	int ballScores[12];
	string PlayerName;
	int TotalScore;
	int turn;
public:
	Player(string n): PlayerName(n), TotalScore(0), turn(0)
	{
		for (int i = 0; i < 12; ++i)
		{
			ballScores[i]=0;
		}
	}
	void setScore(const int sc)
	{
		ballScores[turn]=sc;
		TotalScore+=sc;
		turn++;
	}

	void setball(const int io, const int val)	{ballScores[io]=val;}
	string getName() const {return PlayerName;}
	int getTurn() const {return turn;}
	int getTotal() const {return TotalScore;}
	int getBall(int e) const {return ballScores[e];}
};

class Game
{
public:
int temp;
	bool ValidateScore()
	{
		if(temp<7 && temp>-1)
			return true;
		else
			return false;
	}
	void playGame(Player& player)
	{
		for (int i = 0; i < 12; ++i)
		{
			cout<<"Enter Player: " << player.getName()<< "Score for Turn #" <<player.getTurn()<< ": "<< endl;
			cin>>temp;
			if (ValidateScore())
				{player.setScore(temp);}
			else	
				{player.setScore(0);}
		}
	}

	void findWinner(Player& player1, Player& player2)
	{
		if (player1.getTotal()>player2.getTotal())
			cout <<"Player: " << player1.getName()<< " is the Winner!"<<endl;
		else
			cout <<"Player: " << player2.getName()<< " is the Winner!"<<endl;
	}
	void sortBalls(Player& player1)
	{
		int temp;
		for (int j = 0; j < 11; ++j)
		{
			for (int i = 0; i < 11-j; ++i)
			{
				if(player1.getBall(i)>player1.getBall(i+1))
				{
					temp = player1.getBall(i);
					player1.setball(i, player1.getBall(i+1));
					player1.setball(i+1, temp);
				}
			}
		}
	}

	void DisplayMatch(Player& player1, Player& player2)
	{
		sortBalls(player1);
		sortBalls(player2);
		cout<<"Player: "<< player1.getName() << ": " << endl;
		for (int i = 0; i < 12; ++i)
		{
			cout << "Ball " << i+1 << ":";
			cout << player1.getBall(i) <<endl;
		}
		cout <<"\nAverage Score per Ball: " << player1.getTotal()/12.0 << endl;
		cout <<"\nTotal Score:" << player1.getTotal()<< endl;

		cout<<"Player: "<< player2.getName() << ": " << endl;
		for (int i = 0; i < 12; ++i)
		{
			cout << "Ball " << i+1 << ":";
			cout << player2.getBall(i) <<endl;
		}
		cout <<"\nAverage Score per Ball: " << player2.getTotal()/12.0 << endl;
		cout <<"\nTotal Score:" << player2.getTotal()<< endl;
	}
};