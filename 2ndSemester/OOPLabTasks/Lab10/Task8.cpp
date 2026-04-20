#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{

    ifstream file("article.txt");
    if (!file)
    {
        cout << "ERROR: File failed to open.\n";
        return 1;
    }

    //first, to reach the middle, i must get the total size of the article, then divide it by 2.
    file.seekg(0, ios::end);
    long total_size = file.tellg();
    long middle = total_size/2;
    //remember, since this is the middle of the middle of the line, the first line will be partial
    file.seekg(middle, ios::beg);
    cout << "Jumping to byte: " << middle<< "\n";

    string line;

    for (int i = 0; i < 10 ; ++i)
    {
        if (getline(file, line))
        {
            cout << line << "\n";
        }
        else
        {
            break;
        }
    }
    file.close();
    return 0;
};
