#include <iostream>
#include <vector>
using namespace std;

int nthFibonacci(int n){
    if(n <= 1) return n;
    
    // To store the curr fibonacci number
    int curr = 0;

    // TO store the pervious fibonacci number
    int prev1 = 1;
    int prev2 = 0;

    // Loop to calculate fibonacci number from 2 to n
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return  curr;   
}

// Bottom-Up approach
int fibBottomUp(int n){
    if( n <= 1) return n;

    // vector to store fibonacci number
    vector<int> dp(n + 1);

    //Initialize the first two fib num
    dp[0] = 0;
    dp[1] = 1;

    // Filling the vector iteratively
    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];

    // Return nthFib num
    return dp[n];
}

int main(){
    int n = 15;
    int result  = nthFibonacci(n);
    result = fibBottomUp(n); 
    cout<<result;
}