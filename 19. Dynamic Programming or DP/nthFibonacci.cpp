#include <iostream>
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

int main(){
    int n = 15;
    int result  = nthFibonacci(n);
    cout<<result;
}