#include <iostream>
using namespace std;

int main()
{
int size = 3;
int matriz[size][size] = {{1, 0, 0},
                          {0, 1, 0},
                          {0, 0, 1}};

int dia = 0;
int nondia = 0;
for (int i = 0; i < size; i++)
{
    for (int j=0; j < size; j++)
    {
        if (i == j && matriz[i][j] == 1)
        {
            dia++;
        }
        else
        {
            nondia++;
        }
    }
}

if (dia == size && nondia == ((size*size)-size))
{
    cout << "The Matriz is a Identity Matrix.\n";
}
else
{
    cout << "The Matriz is not a Identity Matrix, how sad.\n";
}

    return 0;
}