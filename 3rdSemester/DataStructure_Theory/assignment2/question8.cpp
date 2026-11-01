#include <iostream>
#include <string>

using namespace std;

const int N = 4;

void solver(int maze[N][N], int row, int col, string ans, int& path_count)
{
    if (row < 0 || col < 0 || row >= N || col >= N || maze[row][col] == 0 || maze[row][col] == -1)
    {
        return;
    }

    if (row == N - 1 && col == N - 1)
    {
        cout << ans << endl;
        path_count++;
        return;
    }

    maze[row][col] = -1;

    solver(maze, row + 1, col, ans + 'D', path_count);
    solver(maze, row, col + 1, ans + 'R', path_count);
    solver(maze, row - 1, col, ans + 'U', path_count);
    solver(maze, row, col - 1, ans + 'L', path_count);

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

    int path_count = 0;

    if (maze[0][0] == 1 && maze[N - 1][N - 1] == 1)
    {
        solver(maze, 0, 0, "", path_count);
    }

    if (path_count == 0)
    {
        cout << "No path exists" << endl;
    }

    return 0;
}