#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inFile("article.txt", ios::in);
    if (!inFile)
    {
        cout << "ERROR: File could not be opened.\n";
        return 1;
    }
    long byte;

    cout << "Mini File Debugger Starting...\n";
    cout << "Starting Pointer Position: " << inFile.tellg() << "\n";

    cout << "Enter byte offset to jump to: ";
    cin >> byte;
    cin.ignore();

    inFile.seekg(byte, ios::beg);
    cout << "Pointer Position after jump: " << inFile.tellg();
    char ch;
    for(int i = 0; i < 100 ; i++)
    {
        if (inFile.get(ch))
        {
            cout << ch;
        }
        else
        {
            cout << "\nEnd of the file reached.\n";
            break;
        }
    }

    cout << "\nFinal pointer Position: " << inFile.tellg();

    inFile.close();
    return 0;
}
