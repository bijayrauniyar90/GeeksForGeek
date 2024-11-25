//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxProduct = nums[0];  // Initialize with the first element
        int currentMax = nums[0]; // Tracks maximum product ending at current position
        int currentMin = nums[0]; // Tracks minimum product ending at current position

        for (int i = 1; i < n; ++i) {
            // If the current number is negative, swap the max and min
            if (nums[i] < 0) {
                swap(currentMax, currentMin);
            }

            // Update currentMax and currentMin
            currentMax = max(nums[i], currentMax * nums[i]);
            currentMin = min(nums[i], currentMin * nums[i]);

            // Update the global maximum product
            maxProduct = max(maxProduct, currentMax);
        }

        return maxProduct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends