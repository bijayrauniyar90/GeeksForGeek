//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool checkSorted(vector<int> &arr) {
        int n = arr.size();
        int chances = 2;  // Allow at most two swaps

        for (int i = 0; i < n; ++i) {
            // While the current element is not at the correct position, try to swap it
            while (arr[i] != i + 1) {
                // If chances are exhausted, return false
                if (chances <= 0) return false;
                
                // Swap the element to its correct position
                swap(arr[i], arr[arr[i] - 1]);
                
                chances--;  // Decrement the chances after each swap
            }
        }
        return true;  // Return true if sorted successfully within 2 swaps
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends