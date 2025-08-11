#include <iostream>
#include <vector>
using namespace std;


//  Using a temporary array - O(n) Time and O(n) Space
// void reverseArray(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> temp(n);

//     for (int i = 0; i < n; i++)
//     {
//        temp[i] = arr[n - i - 1];
//     }

//     // copy into old arr
//     for (int j = 0; j < n; j++)
//     {
//         arr[j] = temp[j];
//     }
    

// }


// By Swapping Elements - O(n) Time and O(1) Space
void reverseArray(vector<int> &arr) {
    int n = arr.size();
    
    // Iterate over the first half and 
    // for every index i,
    // swap arr[i] with arr[n - i - 1]
    for(int i = 0; i < n/2; i++) {
    	swap(arr[i], arr[n - i - 1]);
    }
}

int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}