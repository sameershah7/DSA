#include <iostream>
using namespace std;

int singleDigit(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if (n % 9)
    {
        return n % 9;
    }
    return n % 9;
}

int main()
{
    int n = 674;
    cout<< singleDigit(n);
    return 0;
}