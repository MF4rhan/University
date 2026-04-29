#include <iostream>
#include <string>
using namespace std;

class InsufficientFundsException
{
private:
    string error_message;

public:
    InsufficientFundsException(string msg) : error_message(msg)
    {}

    string getMessage()
    {
        return error_message;
    }
};

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double in_balance) : balance(in_balance)
    {
    }

    void withdraw(double amount)
    {
            if (amount > balance)
            {
                throw InsufficientFundsException("Insufficient Funds to complete withdrawl.");
            }
            balance -= amount;
            cout << "Withdrawl Successful.\n";
    }

    double getBalance()
    {
        return balance;
    }
};

int main()
{
    BankAccount account_one(600);
    try
    {
        cout << "Current Balance: " << account_one.getBalance() << "\n";
        account_one.withdraw(200);
        cout << "Current Balance: " << account_one.getBalance() << "\n";
        account_one.withdraw(800);
    }
    catch(InsufficientFundsException e)
    {
        cout << "Error: " << e.getMessage() << "\n";
    }
    cout << "Current Balance: " << account_one.getBalance() << "\n";

    return 0;
}
