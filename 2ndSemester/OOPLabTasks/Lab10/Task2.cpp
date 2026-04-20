#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  ofstream outFile ("Diary.txt", ios::app);
  if (!outFile)
    {
        cout << "ERROR: File failed to open.\n";
        return 1;
    }

    string entry;
    cout << "Enter your entries to the Diary. Enter 'Exit' to exit.\n\n";
  while(1)
    {
        getline(cin, entry);
        if (entry == "exit" || entry == "Exit")
        {
            break;
        }

        outFile << entry << "\n";
    }
    cout << "The Diary has been saved and closed.\n";
    outFile.close();
    return 0;
};
