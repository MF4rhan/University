#include <iostream>
#include <string>
using namespace std;

class Account
{
    const string account_number;
    string account_holder;
    double balance;
public:
    Account(string number, string name, double balan)
    : account_number(number), account_holder(name), balance(balan)
    {
    }

    double operator+(Account& acc2)
    {
        return balance + acc2.balance;
    }

    Account& operator-=(double transaction_amount)
    {
        balance -= transaction_amount;
        return *this;
    }

    Account& operator+=(double transaction_amount)
    {
        balance += transaction_amount;
        return *this;
    }

    bool operator>(const Account& acc)
    {
        if (balance > acc.balance)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    friend ostream& operator<<(ostream& out, const Account& acc1);
};

ostream& operator<<(ostream& out, const Account& acc1)
{
    out << "Account Number: " << acc1.account_number << endl;
    out << "Account Holder: " << acc1.account_holder << endl;
    out << "Balance: " << acc1.balance << endl << endl;
    return out;
}

int main()
{
    //making objects
    Account account1("JP12345", "Farhan", 1000);
    Account account2("PK12345", "Faraz", 2000);

    //getting total balance
    cout << "Total Balance: " << account1 + account2 << endl;

    //account details before transfer
    cout << account1;
    cout << account2;

    //transfering balance
    account2 -= 500;
    account1 += 500;

    //account details after transfer
    cout << account1;
    cout << account2;

    return 0;
}

