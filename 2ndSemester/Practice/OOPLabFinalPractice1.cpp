#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

class Account
{
private:
    int account_number;
    char name[30];
    float balance;

public:
    Account(int in_account = 0, const char* namae = "None", float  in_balance= 0.00) : account_number(in_account), balance(in_balance)
    {
        strncpy(name, namae, 29);
        name[29] = '\0';
    }

    void display()
    {
        cout << "Acount Number: " << account_number << "| Name: " << name << "| Balance: " << balance << "\n";
    }

    int get_account_number()
    {
        return account_number;
    }

    void set_balance(float bal)
    {
        balance = bal;
    }
};

class DatabaseException
{
private:
    string error;

public:
    DatabaseException(string msg): error(msg)
    {}

    void get_error()
    {
       cerr << "DATABASE ERROR: " << error << "\n";
    }
};

class TaskManager
{
private:
  const char* filename = "bank.dat";

public:
    void add_account(Account* acc)
    {
        ofstream file(filename, ios::binary | ios::app);
        if (!file)
        {
            throw DatabaseException("file could not open");
        }
        file.write((char*)acc, sizeof(Account));
        cout << "Account has been added." << "\n";
        file.close();
    }

    void display_accounts()
    {
        Account temp;
        ifstream file(filename, ios::binary);
        if (!file)
        {
            throw DatabaseException("file could not open");
        }
        while (file.read((char*)&temp, sizeof(Account)))
        {
            temp.display();
        }
        file.close();
    }

    void delete_account(int target_number)
    {
        Account temp;
        bool found = false;
        ifstream file(filename, ios::binary);
        ofstream tempfile("Temp.dat", ios::binary);
        if (!file || !tempfile)
        {
            throw DatabaseException("files could not open");
        }
        while (file.read((char*)&temp, sizeof(Account)))
        {
            if (temp.get_account_number() == target_number)
            {
                found = true;
            }
            else
            {
                tempfile.write((char*)&temp, sizeof(Account));
            }
        }
        //you must close files BEFORE removing or renaming them
        file.close();
        tempfile.close();

        if (found)
        {
            remove(filename);
            rename("Temp.dat",filename);
        }
        else
        {

            remove("Temp.dat");
            throw DatabaseException("ID could not be found");
        }
    }

    void update_account(int target_number, float new_balance)
    {
        Account temp;
        bool found = false;
        ifstream file(filename, ios::binary);
        ofstream tempfile("Temp.dat", ios::binary);
        if (!file || !tempfile)
        {
            throw DatabaseException("file could not open");
        }
        while (file.read((char*)&temp, sizeof(Account)))
        {
            if (temp.get_account_number() == target_number)
            {
                found = true;
                temp.set_balance(new_balance);
                tempfile.write((char*)&temp, sizeof(Account));
            }
            else
            {
                tempfile.write((char*)&temp, sizeof(Account));
            }
        }
        //you must close files BEFORE renaming and removing them
        file.close();
        tempfile.close();

        if (found)
        {
            remove(filename);
            rename("Temp.dat",filename);
        }
        else
        {
            remove("Temp.dat");
            throw DatabaseException("ID could not be found");
        }
    }

};

int main()
{
    try
    {
Account* account1 = new Account(101, "Ali", 5000);
Account* account2 = new Account(102, "Zain", 8000);
TaskManager Filer;
Filer.add_account(account1);
Filer.add_account(account2);

Filer.display_accounts();

delete account1;
delete account2;
    }
    catch (DatabaseException& e)
    {
        e.get_error();
    }

    return 0;
}
