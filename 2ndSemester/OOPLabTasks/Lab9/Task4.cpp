#include <iostream>
#include <string>
using namespace std;

class PaymentMethod
{
public:
    virtual void process_payment(double amount) = 0;
};

class CreditCard: public PaymentMethod
{
private:
    string card_number;

public:
    CreditCard(string card): card_number(card)
    {
    }

    void process_payment(double amount) override
    {
        if (card_number.length() == 16)
        {
            cout << "Validating Credit Card: " << card_number << endl;
            cout << "Transaction of " << amount << "$ is successful." << endl;
        }
        else
        {
            cout << "Error: Invalid Card Number Length." << endl;
        }
    }
};

class DigitalWallet: public PaymentMethod
{
private:
    double balance;

public:
    DigitalWallet(double in_balance): balance(in_balance)
    {
    }

    void process_payment(double amount) override
    {
        balance -=amount;
        cout << "Transaction of " << amount << "$ is successful." << endl;
        cout << "Remaining Balance: " << balance << endl;
    }
};

int main()
{
    //making objects
  CreditCard card1("1234567890123456");
  DigitalWallet wallet1(5000);

  //running card's overrided method
  card1.process_payment(1500);
  cout << endl;

  //running wallet's overrided method
  wallet1.process_payment(1000);
  cout << endl;

  return 0;
};
