#include <iostream>
#include <string>
using namespace std;

class Account
{
    int balance;
    public:
        Account(int bal): balance(bal)
        {
        }
    friend Account& operator+(Account& acc, int bal);

    void print_balance()
    {
        cout << "Balance: " << balance << endl;
    }
};

Account& operator+(Account& acc, int bal) //Account object will always be the first arguement.
{
    acc.balance += bal;
    return acc;
}

int main()
{
    Account acc(100);
    acc.print_balance(); //before
    acc = acc + 100;
    acc.print_balance(); //after
    //acc = 100 + acc; This line will cause Errors.
    //acc.print_balance();
    return 0;
}
