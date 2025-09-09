#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &vc)
{
    for (auto i : vc)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> v1 = {20, 30, 40, 25, 15};

    // Converting vector into heap
    make_heap(v1.begin(), v1.end());

    // Display the maximum number of heap using front();
    // cout << "The Maximum element of heap is: " << v1.front() << endl;

    // v1.push_back(50);
    // cout << "Heap just after push_back(): " << endl;
    print(v1);
    cout << endl;

    // push_heap(v1.begin(), v1.end());
    // cout << "Heap after heap push: " << endl;
    // v1.pop_back();
    // sort_heap(v1.begin(), v1.end());

    // is_heap(v1.begin(), v1.end()) ? cout << "The container is heap " : cout << "The container is not heap";
    // using is_heap_until() to check position
    // till which container is heap
    auto it = is_heap_until(v1.begin(), v1.end());
    print(v1);

    return 0;
}