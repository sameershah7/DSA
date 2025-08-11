//O(1) means the algorithm takes the same amount of time, no matter how large the input is.
//It does not depend on the size of the input.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {10, 20, 30, 40, 50};

    // Accessing the third element directly — O(1)
    cout << "Element at index 2: " << numbers[2] << endl;

    return 0;
}
