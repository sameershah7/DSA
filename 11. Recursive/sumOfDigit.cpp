#include <iostream>

using namespace std;

int sumOfDight(int n)
{
    if (n == 0)
        return 0;
    return (n % 10 + sumOfDight(n / 10));
}

int main()
{
    int num = 12345;
    int result = sumOfDight(num);
    cout << result << endl;
    return 0;
}