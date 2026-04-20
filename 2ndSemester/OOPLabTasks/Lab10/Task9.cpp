#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  fstream file("Draft.txt", ios::in | ios::out);
  if (!file)
    {
        cout << "ERROR: File was unable to open.\n";
        return 0;
    }
    string word;
    while(file >> word)
    {
        if (word == "teh")
        {
            long pos = file.tellg();
            //pos - 3 because after >> is done reading a word, its at the end of the word, not the start
            file.seekp(pos-3);
            file << "the";
            cout << "Typo fixed at position: " << pos-3;
            break; //only first instance is fixed, as the task said
        }
    }
    file.close();
    return 0;
};
