//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
    unordered_set<int> elementSet(arr.begin(), arr.end());
    
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            // Check if 'sum' is in the set and is different from arr[i] and arr[j]
            if (elementSet.count(sum) && sum != arr[i] && sum != arr[j]) {
                return true;
            }
        }
    }
    return false;
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends