#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile ("Signup.txt", ios::app);
    if (!outFile)
    {
        cout << "ERROR: File failed to open.\n";
        return 1;
    }

    string name, email;
    while(1)
    {
        cout << "Enter user Name (Enter 'Exit' to exit.)\n";
        getline(cin, name);
        if (name == "exit" || name == "Exit")
        {
            break;
        }
        cout << "\nEnter user Email. (Enter 'Exit' to exit.)\n";
        getline(cin, email);
        if (email == "exit" || email == "Exit")
        {
            break;
        }

        outFile << "Name: "<< name << "\n";
        outFile << "Email: "<< email << "\n\n";
    }
    cout << "The signup file has been saved and closed.\n";
    outFile.close();
    return 0;
};
