#include <iostream>
using namespace std;

class board
{
  int boardy[4][4];
  int size;
  
  public:
  board(): size(4)
  {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            boardy[i][j] = 0;
        }
        
    }

  }

  void isSolved()
  {
    if (NQueen(0))
    {
        cout << "\nN Queens have been placed.\n";
        printBoard();
    }
    else
    {
        cout << "\nNot Possible.\n";
    }
  }


  bool NQueen(int row)
  {
    if (row == size)
    {
        printBoard();
        return true;
    }

    for (int j = 0; j < size; j++) //going through each column of a row
    {
        if (isSafe(row, j))
        {
            boardy[row][j] = 1;
            /*
            if (NQueen(row+1))
            {
                return true;
            }
            */ //the above is if you want to find the FIRST VALID ARRANGEMENT, and not EVERY VALID ARRANGEMENT
            NQueen(row+1);
            boardy[row][j] = 0;
        }
    }
    return false;
  }

  bool isSafe(int row, int column)
  {
    int i, j;
    for (i = row; i >= 0 ; --i)
    {
        if (boardy[i][column] == 1)
        {
            return false;
        }
    }


    for (i = row-1, j = column-1; i >= 0 && j >= 0; --i, --j)
    {
        if (boardy[i][j] == 1)
        {
            return false;
        }
        
    }
    
    for (i = row-1, j = column+1; i >= 0 && j < size; --i, ++j)
    {
        if (boardy[i][j] == 1)
        {
            return false;
        }
        
    }

    return true;
  }

    void printBoard()
    {
        cout << endl;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(boardy[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }

            cout << endl;
        }
    }


};


int main()
{
    board boarder;
    boarder.NQueen(0);

    return 0;
}