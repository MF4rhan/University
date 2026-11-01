#include <iostream>
#include <string>

using namespace std;

class Board
{
private:
    int grid[6][8];
    int total_arrangements;
    string course_names[4];

public:
    Board() : total_arrangements(0)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                grid[i][j] = 0;
            }
        }

        course_names[0] = "Programming";
        course_names[1] = "Database Systems";
        course_names[2] = "Operating Systems";
        course_names[3] = "Computer Networks";
    }

    //checks damaged seat, row, column, and diagonal conflicts
    bool is_safe(int row, int col)
    {
        // seat (3, 3) is unavailable
        if (row == 3 && col == 3)
        {
            return false;
        }

        //check row
        for (int j = 0; j < 8; j++)
        {
            if (grid[row][j] != 0)
            {
                return false;
            }
        }

        //check column
        for (int i = 0; i < 6; i++)
        {
            if (grid[i][col] != 0)
            {
                return false;
            }
        }

        //check diagonals against already placed courses
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (grid[i][j] != 0)
                {
                    int row_diff = row - i;
                    int col_diff = col - j;

                    if (row_diff < 0)
                    {
                        row_diff = -row_diff;
                    }
                    if (col_diff < 0)
                    {
                        col_diff = -col_diff;
                    }

                    if (row_diff == col_diff)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    void print_board()
    {
        cout << "Arrangement " << total_arrangements << ":\n";
        for (int c = 0; c < 4; c++)
        {
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (grid[i][j] == c + 1)
                    {
                        cout << course_names[c] << " at (" << i << ", " << j << ")\n";
                    }
                }
            }
        }
        cout << "\n";
    }

    //recursive backtracking function
    void assign_seats(int course_index)
    {
        // base case, all 4 courses placed successfully
        if (course_index == 4)
        {
            total_arrangements++;
            print_board();
            return;
        }

        // programming must be placed in row 0
        if (course_index == 0)
        {
            for (int col = 0; col < 8; col++)
            {
                if (is_safe(0, col))
                {
                    grid[0][col] = course_index + 1;
                    assign_seats(course_index + 1);
                    grid[0][col] = 0;
                }
            }
        }
        else
        {
            //other courses can be placed in any remaining row from 1 to 5
            for (int row = 1; row < 6; row++)
            {
                for (int col = 0; col < 8; col++)
                {
                    if (is_safe(row, col))
                    {
                        grid[row][col] = course_index + 1;
                        assign_seats(course_index + 1);
                        grid[row][col] = 0;
                    }
                }
            }
        }
    }

    int get_total()
    {
        return total_arrangements;
    }
};

int main()
{
    Board exam_hall;

    exam_hall.assign_seats(0);

    if (exam_hall.get_total() == 0)
    {
        cout << "No valid arrangement exists\n";
    }
    else
    {
        cout << "Total valid arrangements: " << exam_hall.get_total() << "\n";
    }

    return 0;
}