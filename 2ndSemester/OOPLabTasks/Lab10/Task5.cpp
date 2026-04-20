#include <iostream>
#include <string>
#include <fstream>
#include <sstream> //required for istringstream
using namespace std;

int main()
{
    ifstream inFile("story.txt");
    if (!inFile)
    {
        cout << "Error: story.txt not found." << endl;
        return 1;
    }

    string paragraph;
    // reading the entire paragraph into a single string
    if (getline(inFile, paragraph))
    {
        // feeding that string into the stringstream object
        istringstream obj(paragraph);
        string word;

        // extracting words one by one from the stream
        while (obj >> word)
        {
            cout << word << "\n"; // printing each word on a new line
        }
    }

    inFile.close();
    return 0;
}
