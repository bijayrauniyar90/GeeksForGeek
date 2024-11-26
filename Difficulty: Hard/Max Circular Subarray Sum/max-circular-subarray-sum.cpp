//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
   int circularSubarraySum(vector<int>& arr) {
    int n = arr.size();
    int totalSum = 0, maxSum = INT_MIN, curMax = 0;
    int minSum = INT_MAX, curMin = 0;

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];

        // Standard Kadane's algorithm for maximum subarray sum.
        curMax = max(arr[i], curMax + arr[i]);
        maxSum = max(maxSum, curMax);

        // Kadane's algorithm for minimum subarray sum.
        curMin = min(arr[i], curMin + arr[i]);
        minSum = min(minSum, curMin);
    }

    // If all numbers are negative, the maximum circular sum is the maximum element.
    if (maxSum < 0) {
        return maxSum;
    }

    // Maximum of non-circular sum (maxSum) and circular sum (totalSum - minSum).
    return max(maxSum, totalSum - minSum);
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends