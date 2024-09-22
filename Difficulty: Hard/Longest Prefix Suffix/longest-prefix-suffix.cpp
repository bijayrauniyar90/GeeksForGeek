//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
public:
    int lps(string str) {
        int n = str.size();
        vector<int> lpsArray(n, 0);  // Array to hold the longest prefix suffix values

        int len = 0;  // Length of the previous longest prefix suffix
        int i = 1;

        // Build the lpsArray
        while (i < n) {
            if (str[i] == str[len]) {
                len++;
                lpsArray[i] = len;
                i++;
            } else {
                // If there is a mismatch
                if (len != 0) {
                    // Set len to the previous longest prefix suffix value
                    len = lpsArray[len - 1];
                } else {
                    // No proper prefix suffix found, set lps[i] to 0
                    lpsArray[i] = 0;
                    i++;
                }
            }
        }

        // The value in lpsArray[n-1] contains the length of the longest prefix that is also a suffix
        return lpsArray[n - 1];
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends