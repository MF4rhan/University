#include <iostream>
#include <fstream>
#include <string>
#include <ctime> // The required library
using namespace std;

int main() {
    // getting the current system time
    time_t now = time(0);

    // converting it to a readable string
    char* dt = ctime(&now);

    ofstream logFile("systemlog.txt", ios::app);
    if (!logFile)
    {
        cout << "Error: Unable to open log file." << endl;
        return 1;
    }

    logFile << "System started at: " << dt;

    logFile.close();
    cout << "Startup logged successfully.\n";
    return 0;
}
