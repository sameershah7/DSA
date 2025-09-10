#include <bits/stdc++.h>
using namespace std;

int height(int N)
{
    return floor(log2(N));
}

int main()
{
    int N = 4;
    cout << height(N);
    return 0;
}