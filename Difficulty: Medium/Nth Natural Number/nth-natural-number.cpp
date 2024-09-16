//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    long long findNth(long long n) {
        long long result = 0;
        long long placeValue = 1;
        
        while (n > 0) {
            result += (n % 9) * placeValue;  // Add the base-9 digit
            n /= 9;  // Move to the next base-9 digit
            placeValue *= 10;  // Shift to the next place value in base-10
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends