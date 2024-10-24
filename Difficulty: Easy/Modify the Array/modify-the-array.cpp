//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        int index = 0; // Keeps track of the position to place the modified elements
        
        // First pass: modify array by doubling consecutive duplicates and ignoring zeros
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && arr[i] == arr[i + 1]) {
                arr[index++] = arr[i] * 2;
                i++; // Skip the next element since it's already processed
            } else if (arr[i] != 0) {
                arr[index++] = arr[i]; // Move non-zero elements
            }
        }
        
        // Second pass: fill the rest of the array with zeros
        while (index < n) {
            arr[index++] = 0;
        }
        
        return arr;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends