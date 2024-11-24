//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // Function to find the sum of contiguous subarray with the maximum sum.
    int maxSubarraySum(vector<int>& arr) {
        int maxSum = INT_MIN, currentSum = 0;

        for (int num : arr) {
            currentSum += num;
            maxSum = max(maxSum, currentSum); // Update maxSum if currentSum is greater
            if (currentSum < 0) currentSum = 0; // Reset currentSum if it drops below 0
        }

        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends