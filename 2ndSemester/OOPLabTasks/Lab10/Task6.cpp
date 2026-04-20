#include <iostream>
#include <fstream>
#include <string>
#include <cctype> //required for isupper()
using namespace std;

int main()
{
    ifstream inFile("secret.txt");
    if (!inFile)
    {
        cout << "Error: secret.txt not found." << endl;
        return 1;
    }

    char ch;
    int upper_count = 0;

    while (inFile.get(ch))
    {
        if (isupper(ch))
        {
            upper_count++;
        }
    }

    cout << "Total signals (uppercase letters) found: " << upper_count << "\n";

    inFile.close();
    return 0;
}
