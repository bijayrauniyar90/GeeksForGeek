//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        // Iterate over each position in the array
        for (int i = 0; i < n; i++) {
            // Calculate the maximum jump limit for this iteration
            int maxJump = min(i + k, n - 1);
            
            // Update the minimum cost for all reachable positions within the jump range
            for (int j = i + 1; j <= maxJump; j++) {
                dp[j] = min(dp[j], dp[i] + abs(arr[i] - arr[j]));
            }
        }

        return dp[n - 1];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends