#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream file("article.txt", ios::in);
    if (!file)
    {
        cout << "ERROR: File failed to open.\n";
        return 1;
    }

    long total_characters = 0;
    long total_words = 0;
    long total_lines = 0;
    long total_punctuations = 0;
    string line;

    while(getline(file, line))
    {
        total_lines++;
        total_characters += (line.length() + 1); // +1 for the newline that getline skips
        istringstream idk(line);
        string tempword;
        while (idk >> tempword)
        {
            total_words++;
        }
        for (char &ch : line)
            //this is basically a normal for loop, but it runs and increments till it runs out of index and stops
        {
            if (ispunct(ch))
            {
                total_punctuations++;
            }
        }
    }
    file.close();

    ofstream outFile("Report.txt", ios::out);
    outFile << "----File Report----\n";
    outFile << "Total Lines: \t" << total_lines << "\n";
    outFile << "Total Words: \t" << total_words << "\n";
    outFile << "Total Characters: \t" << total_characters << "\n";
    outFile << "Punctuations Marks: \t" << total_punctuations << "\n";
    outFile.close();

    cout << "Report successfully created.\n";
    return 0;
}
