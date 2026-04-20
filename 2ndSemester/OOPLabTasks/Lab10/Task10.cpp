#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile ("backup_log.txt", ios::app);
    if (!outFile)
    {
        cout << "ERROR: File failed to open.\n";
        return 1;
    }

    string entry;
    cout << "Enter your entries to the backup Log. Enter 'Exit' to exit.\n\n";
    while(1)
    {
        getline(cin, entry);
        if (entry == "exit" || entry == "Exit")
        {
            break;
        }

        outFile << entry << "\n";
        long pos = outFile.tellp();
        cout << "The log file has been updated.\n";
        cout << "The current size of the file in bytes is: " << pos;
        cout << "\n\n";
    }
    cout << "\nSystem closing.\n";
    outFile.close();
    return 0;
};
