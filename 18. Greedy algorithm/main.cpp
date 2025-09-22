#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCoins(vector<int> &coins, int amount){
    int n = coins.size();
    sort(coins.begin(), coins.end());
    int res = 0;

    // Start from the coin with the highest denomination
    for(int i = n - 1; i>= 0; i--){
        if(amount >= coins[i]){

            // Find the maximum number of ith coin we can use
            int cnt = (amount/ coins[i]);

            // Add the count to result
            res += cnt;

            // Subtrack the corresponding amount from the total amount 
            amount -= (cnt* coins[i]);
        }
        if(amount == 0)
            break;
    }
    return res;
}

int main() {
    vector<int> coins = {5, 2, 10, 1};
    int amount = 20;
  
    cout << minCoins(coins, amount);
    return 0;
}