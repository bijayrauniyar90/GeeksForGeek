//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> dp;
    
    // Function to check if the remaining characters in the pattern are all '*'
    bool check(const string &s2, int idx2) {
        for (int i = idx2; i < s2.length(); ++i) {
            if (s2[i] != '*') return false;
        }
        return true;
    }

    // Helper function using recursion and memoization
    bool help(const string &s1, const string &s2, int idx1, int idx2) {
        if (idx1 == s1.length()) return check(s2, idx2);
        if (idx2 == s2.length()) return false;

        int &ans = dp[idx1][idx2];
        if (ans != -1) return ans;

        if (s1[idx1] == s2[idx2] || s2[idx2] == '?') {
            return ans = help(s1, s2, idx1 + 1, idx2 + 1);
        } else if (s2[idx2] == '*') {
            // Two possible moves:
            // 1. Move on the pattern (skip the '*')
            // 2. Use '*' to match the current character and move on the string
            return ans = help(s1, s2, idx1, idx2 + 1) || help(s1, s2, idx1 + 1, idx2);
        } else {
            return ans = false;
        }
    }

    int wildCard(string pattern, string str) {
        // Swap to ensure the logic aligns with the original implementation
        swap(pattern, str);

        int n = pattern.length();
        int m = str.length();
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        return help(pattern, str, 0, 0);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends