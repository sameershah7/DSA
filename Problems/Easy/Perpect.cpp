#include <iostream>
using namespace std;

bool isPerfect(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    return sum == n;
}

int main()
{
    int n = 8128;
    cout << (isPerfect(n) ? "true" : "false");
    return 0;
}