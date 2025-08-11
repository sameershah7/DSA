// Definition:
// Factorial time complexity occurs when the number of operations grows factorially with the input size n.
// It is the slowest and least efficient growth rate and happens in problems that require checking all possible permutations or combinations.

#include <iostream>
using namespace std;

void permute(int *a, int l, int r)
{

    if (l == r)
    {
        for (int i = 0; i <= r; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);     // Swap current index with l
            permute(a, l + 1, r); // Recurse
            swap(a[l], a[i]);     // Backtrack
        }
    }
}

int main()
{
    int a[] = {1, 2, 3};
    int n = 3;
    permute(a, 0, n - 1);
    return 0;
}
