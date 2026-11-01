#include <iostream>
#include <string>

using namespace std;

void find_access_codes(int allowed_digits[], int total_allowed, int n, int target_sum, int start_index, int current_count, int current_sum, int current_code[], int& total_combinations)
{
    //base case, required number of digits selected
    if (current_count == n)
    {
        if (current_sum == target_sum)
        {
            total_combinations++;
            for (int i = 0; i < n; i++)
            {
                cout << current_code[i] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for (int i = start_index; i < total_allowed; i++)
    {
        //skip if adding this digit exceeds the target sum
        if (current_sum + allowed_digits[i] > target_sum)
        {
            continue;
        }

        //select digit
        current_code[current_count] = allowed_digits[i];

        //recurse using i + 1 to enforce strictly increasing order and avoid reuse
        find_access_codes(allowed_digits, total_allowed, n, target_sum, i + 1, current_count + 1, current_sum + allowed_digits[i], current_code, total_combinations);

        //backtrack, reset current position
        current_code[current_count] = 0;
    }
}

int main()
{
    int allowed_digits[] = {1, 2, 3, 4, 5};
    int total_allowed = 5;
    int n = 3;
    int target_sum = 9;

    int current_code[10];
    int total_combinations = 0;

    find_access_codes(allowed_digits, total_allowed, n, target_sum, 0, 0, 0, current_code, total_combinations);

    if (total_combinations == 0)
    {
        cout << "No valid access code found\n";
    }
    else
    {
        cout << "Total combinations: " << total_combinations << "\n";
    }

    return 0;
}