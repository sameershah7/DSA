#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the maximum stolen value
int maxLoot(vector<int> &hval) {
    int n = hval.size();

    if (n == 0)
        return 0;
    if (n == 1)
        return hval[0];

    // Set previous 2 values
    int secondLast = 0, last = hval[0];

    // Compute current value using previous two values
    // The final current value would be our result
    int res;
    for (int i = 1; i < n; i++) {
        res = max(hval[i] + secondLast, last);
        secondLast = last;
        last = res;
    }
    return res;
}

int main() {
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    cout << maxLoot(hval) << endl;
    return 0;
}