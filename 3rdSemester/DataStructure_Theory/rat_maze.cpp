#include <iostream>
#include <string>
using namespace std;

const int N = 4;

void solver(int maze[N][N], int row, int col, string ans)
{
    if (row < 0 || col < 0 || row >= N || col >= N || maze[row][col] == 0 || maze[row][col] == -1)
    {
        return;
    }

    if (row == N-1 && col == N-1)
    {
        cout << ans << endl;
        return;
    }

    maze[row][col] = -1;

    solver(maze, row+1, col, ans + 'D'); //moving down
    solver(maze, row, col+1, ans + 'R'); //moving right
    solver(maze, row-1, col, ans + 'U'); //moving up
    solver(maze, row, col-1, ans + 'L'); //moving left

    maze[row][col] = 1;
}


int main()
{
    int maze[N][N] = {
      {1, 0, 0, 0},
      {1, 1, 0, 0},
      {0, 1, 0, 0},
      {1, 1, 1, 1}
    };
    string path = "";
    solver(maze, 0, 0, path);

    return 0;
}