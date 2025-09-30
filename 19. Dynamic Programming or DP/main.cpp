#include <iostream>
#include <vector>
using namespace std;

// Dynamic programming DP is a way of solving by breaking them into smaller sub problems and storing their result so that you don't have to solve the same subproblem again and again

// Function to calculate number of way using dynamic programming
int climbStair(int n)
{
    vector<int> dp(n + 1, 0);

    // Base cades
    dp[0] = 1; // 1 way to stay at step 0 (do nothing)
    dp[1] = 1; // 1 way to climb 1 step

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    // ways to reach step i = from step (i -1) + from step (i - 2)

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter number of steps: ";
    cin >> n;
    cout << "Number of ways to climb " << n << " steps = " << climbStair(n) << endl;
    return 0;
}