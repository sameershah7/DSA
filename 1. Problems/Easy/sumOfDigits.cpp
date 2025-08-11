#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    int sum = 0;
    while (n != 0)
    {
        // Extract the last digit
        int last = n % 10;

        // Add last digit to sum
        sum += last;

        // Remove the last digit
        n /= 10;
    }
    return sum;
}

int sumOfDigitsRec(int n) {
    
    // Base Case
    if (n == 0)
        return 0;

    // Recursive Case
    return (n % 10) + sumOfDigitsRec(n / 10);
}

int main()
{
    int n = 123;
    cout << sumOfDigits(n)<<endl;
    cout<< sumOfDigitsRec(n)<<endl;

    return 0;
}