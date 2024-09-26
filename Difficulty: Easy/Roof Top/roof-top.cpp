//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxStep(const vector<int>& arr) {
        int maxSteps = 0;   // Initialize to 0 since no steps is a valid scenario.
        int count = 0;
        int n = arr.size();
        
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                count++;
            } else {
                maxSteps = max(maxSteps, count);
                count = 0;  // Reset count if the condition breaks
            }
        }
        
        // Ensure the final count is considered
        maxSteps = max(maxSteps, count);
        
        return maxSteps;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends