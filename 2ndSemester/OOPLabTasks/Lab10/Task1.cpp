#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile("greeting.txt", ios::out);
    if (!outFile)
    {
        cout << "ERROR: File failed to open. Please restart.\n";
        return 1;
    }

    cout << "Enter Recipient's Name: ";
    string name;
    getline(cin, name);

    cout << "\nEnter Recipient's Message: ";
    string message;
    getline(cin, message);

    outFile << "Dear " << name << ",\n";
    outFile << message << "\n";
    outFile << "Best Regards!";
    outFile.close();

    cout << "\n\nVerifying File Data\n\n";

    ifstream inFile("greeting.txt", ios::in);
    if (!inFile)
    {
        cout << "ERROR: File failed to open. Please restart.\n";
        return 1;
    }

    string line;
    while(getline(inFile, line))
    {
        cout << line <<"\n";
    }

    inFile.close();
    return 0;
}
