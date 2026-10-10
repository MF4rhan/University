#include <iostream>
#include <string>

using namespace std;

void solver(int N, int targetSum, string targetCode, string currentCode, int currentSum, bool used[10], int digit, bool &foundTarget)
{
    // base case: checking if we reached the required length
    if (currentCode.length() == N)
    {
        // print only if the sum matches our target
        if (currentSum == targetSum)
        {
            cout << currentCode << endl;
            
            // check if this valid code is the one we are looking for
            if (currentCode == targetCode)
            {
                foundTarget = true;
            }
        }
        return;
    }

    // base case: stop if we checked all digits from 0 to 9
    if (digit > 9)
    {
        return;
    }

    bool isValid = true;

    // condition: no digit may be repeated
    if (used[digit] == true)
    {
        isValid = false;
    }

    // condition: the first digit cannot be 0
    if (currentCode.length() == 0 && digit == 0)
    {
        isValid = false;
    }

    // branch 1: if the digit is allowed, add it to the code
    if (isValid == true)
    {
        used[digit] = true; // mark as used
        
        // move to the next position, restart checking from digit 0
        solver(N, targetSum, targetCode, currentCode + (char)(digit + '0'), currentSum + digit, used, 0, foundTarget);
        
        used[digit] = false; // backtrack to try other combinations
    }

    // branch 2: skip this digit and try the next one (acts as our loop)
    solver(N, targetSum, targetCode, currentCode, currentSum, used, digit + 1, foundTarget);
}

int main()
{
    int N = 3;
    int targetSum = 6;
    string targetCode = "123";
    
    // tracks which digits 0-9 are currently in our path
    bool used[10] = {false};
    bool foundTarget = false;
    
    solver(N, targetSum, targetCode, "", 0, used, 0, foundTarget);
    
    if (foundTarget == true)
    {
        cout << "Target code found" << endl;
    }
    else
    {
        cout << "Target code not found" << endl;
    }

    return 0;
}