#include <iostream>
#include <vector>
using namespace std;

// Function to count decoding ways for the entire string.
int countWays(string &digits)
{
    int n = digits.length();

    // Create a dp array initialized to 0, with size n + 1.
    vector<int> dp(n + 1, 0);

    // Base case: An empty string has one valid decoding.
    dp[n] = 1;

    // Iterate from the end of the string to the beginning.
    for (int i = n - 1; i >= 0; i--)
    {
        // Single-digit decoding: check if current digit is not '0'.
        if (digits[i] != '0')
            dp[i] = dp[i + 1];

        // Two-digit decoding: check if next two digits are valid.
        if ((i + 1 < n) &&
            ((digits[i] == '1' && digits[i + 1] <= '9') || (digits[i] == '2' && digits[i + 1] <= '6')))
            dp[i] += dp[i + 2];
    }

    return dp[0];
}

// Using Space Optimised DP
int countWaysDP(string &digits)
{
    int n = digits.size();

    if (n == 0 || digits[0] == '0')
        return 0;

    // Two variable to store the previous results
    int prev1 = 1, prev2 = 0;

    for (int i = 0; i <= n; i++)
    {
        int curr = 0;

        if (digits[i - 1] != '0')
            curr += prev1;

        // Checking for valid two-digit decoding
        // (prev digit and current digit from a valid number b/w 10 to 26)
        if (i > 1)
        {
            int twoDigit = (digits[i - 2] - '0') * 10 + (digits[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26)
            {
                curr += prev2;
            }
        }
        // Update prev1 and prev2 for the next iteration.
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    string digits = "121232";
    cout << countWays(digits) << endl;
    cout<<countWaysDP(digits)<<endl;

    return 0;
}