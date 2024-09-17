//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0; // If there's only one element, no difference can be minimized.
        
        sort(arr.begin(), arr.end()); // Sort the array to easily find max and min values.
        
        // Initial maximum difference between largest and smallest values.
        int diff = arr[n-1] - arr[0]; 
        
        // Smallest and largest values after adding/subtracting k to/from the extreme elements.
        int small = arr[0] + k;
        int large = arr[n-1] - k;
        
        for (int i = 0; i < n - 1; i++) {
            int currentMin = min(small, arr[i+1] - k); // Minimize the smallest value.
            int currentMax = max(large, arr[i] + k); // Maximize the largest value.
            
            // If the minimum is negative, skip this iteration as heights can't be negative.
            if (currentMin < 0) continue;
            
            // Update the difference if a smaller one is found.
            diff = min(diff, currentMax - currentMin);
        }
        
        return diff;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends