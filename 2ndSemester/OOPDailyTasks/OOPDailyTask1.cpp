#include <iostream>
using namespace std;

class Account
{
	int balance;
public:

	Account(int bal)
	{
		if (bal<0)
		{
			balance=0;
			cout << "Error: Negative Balance." << endl;
		}
		else
		{
			balance = bal;
		}
	}
	void credit(int add)
	{
		if (add>0)
		{
			balance+=add;
			cout << "Credit added to Current Balance amount." << endl;
		}
		else
		{
			cout << "Invalid amount, please try again." << endl;
		}
	}

	void debit(int deb)
	{
		if (deb <= balance && deb > 0)
		{
			balance -= deb;
			cout << "Withdrawl Successful!" << endl;
		}
		else if (deb > balance)
		{
			cout << "Withdrawl Failed. Withdrawl amount is greater than current balance." << endl;
		}
		else
		{
			cout << "Invalid withdrawl amount, please try again." << endl;
		}
	}

	int getBalance()
	{
		return balance;
	}

}; //end of class

int main()
{
	Account acc1(1000), acc2(0);
	//Checking Balance of both accounts.
	cout << "Account#1 Balance: " << acc1.getBalance() << endl;
	cout << "Account#2 Balance: " << acc2.getBalance() << endl;

	//Now adding more money into both accounts.
	acc1.credit(500);
	acc2.credit(-200); //This will show error.
	acc2.credit(5000);

	//Now making withdrawls.
	acc1.debit(1000);
	acc2.debit(3200);
	acc1.debit(1000);//This will show error.

	//Checking Balance of both accounts again.
	cout << "Account#1 Balance: " << acc1.getBalance() << endl;
	cout << "Account#2 Balance: " << acc2.getBalance() << endl;

return 0;
}