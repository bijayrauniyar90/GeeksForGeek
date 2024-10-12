//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int pairWithMaxSum(vector<int>& arr) {
        int n = arr.size();

        // If the array has 1 or fewer elements, return -1 as there's no valid pair.
        if (n <= 1) return -1;

        int maxSum = 0;

        // Traverse the array, calculating the sum of adjacent elements and tracking the maximum sum.
        for (int i = 1; i < n; ++i) {
            maxSum = max(maxSum, arr[i] + arr[i - 1]);
        }

        return maxSum;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends