//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        if (arr.empty()) return "-1";
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        string first = arr[0];
        string last = arr[n - 1];
        string ans = "";
        
        for (int i = 0; i < first.size(); ++i) {
            if (first[i] == last[i]) {
                ans += first[i];
            } else {
                break;
            }
        }
        
        return ans.empty() ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends