//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maxLength(string str) {
        int n = str.length();
        int left = 0, right = 0, maxlen = 0;
        
        // Left-to-right traversal
        for (int i = 0; i < n; i++) {
            if (str[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                maxlen = max(maxlen, 2 * left);
            } else if (right > left) {
                left = right = 0;  // reset when invalid
            }
        }
        
        // Reset counters for right-to-left traversal
        left = right = 0;
        
        // Right-to-left traversal
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                maxlen = max(maxlen, 2 * right);
            } else if (left > right) {
                left = right = 0;  // reset when invalid
            }
        }
        
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends