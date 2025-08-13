#include <bits/stdc++.h>

using namespace std;

int countPairs(vector<int> &arr, int k)
{
    int n = arr.size();
    int cnt = 0;

    // [Naive Approach] Generating all pairs - O(n^2) Time and O(1) Space

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (arr[i] - arr[j] == k)
    //         {
    //             cnt++;
    //         }
    //     }
    // }

    sort(arr.begin(), arr.end());
    int i = 0, j = 0;
  
    while(j < n) {
        
        // If the difference is greater than k, increase 
        //the difference by moving pointer j towards right
    	if(arr[j] - arr[i] < k) 
        	j++;
       
        // If difference is greater than k, decrease the 
        // difference by moving pointer i towards right
        else if(arr[j] - arr[i] > k)
        	i++;
      
        // If difference is equal to k, count all such pairs
        else {
			int ele1 = arr[i], ele2 = arr[j];
            int cnt1 = 0, cnt2 = 0;
          
            // Count frequency of first element of the pair
            while(j < n && arr[j] == ele2) {
                j++;
                cnt2++;
            }
          
            // Count frequency of second element of the pair
            while(i < n && arr[i] == ele1) {
                i++;
                cnt1++;
            }
          
            // If both the elements are same, then count of
            // pairs = the number of ways to choose 2 
            // elements among cnt1 elements
            if(ele1 == ele2) 
            	cnt += (cnt1 * (cnt1 - 1))/2;
          
            // If the elements are different, then count of
            // pairs = product of the count of both elements
            else 
            	cnt += (cnt1 * cnt2);
        }
    }
    return cnt;
}

int main()
{
    vector<int> arr = {1, 4, 1, 4, 5, 6, 7};
    int k = 3;

    cout << countPairs(arr, k);
    return 0;
}