#include <iostream>
#include <string>
using namespace std;

class Account
{
    int const account_id;
    int balance;
    static int number_of_accounts;

    public:
    Account(int bal): balance(bal), account_id(number_of_accounts++)
    {
    }

    void print_balance() //no arguements passed
    {
        cout << "Balance: " << balance << endl;
    }

    friend void show_total();
};

void show_total()
{
    cout << "Number of Accounts are: " << Account::number_of_accounts << endl;
}

int Account::number_of_accounts = 0;

int main()
{
    Account acc1(100);
    Account acc2(200);
    Account acc3(300);
    show_total(); //no arguements passed, yet it can still access private static members of the class.

    return 0;
}
