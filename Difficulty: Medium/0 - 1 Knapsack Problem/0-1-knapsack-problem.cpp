//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = val.size();
        vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
        return knapsackHelper(n, W, wt, val, memo);
    }

private:
    int knapsackHelper(int index, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& memo) {
        // Base cases: no items left or no capacity left in knapsack
        if (index == 0 || W == 0) {
            return 0;
        }

        // Return the memoized result if already computed
        if (memo[index][W] != -1) {
            return memo[index][W];
        }

        // Case 1: Exclude the current item
        int excludeItem = knapsackHelper(index - 1, W, wt, val, memo);

        // Case 2: Include the current item (only if it fits in the knapsack)
        int includeItem = 0;
        if (wt[index - 1] <= W) {
            includeItem = val[index - 1] + knapsackHelper(index - 1, W - wt[index - 1], wt, val, memo);
        }

        // Store the result in the memoization table and return
        memo[index][W] = max(includeItem, excludeItem);
        return memo[index][W];
    }
};


//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends