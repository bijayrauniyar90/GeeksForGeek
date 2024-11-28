//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int myAtoi(char *s) {
        // Define constants for integer limits
        const int MAX = INT_MAX; // 2^31 - 1
        const int MIN = INT_MIN; // -2^31
        
        int i = 0, sign = 1;
        long result = 0;
        
        // Skip leading whitespace
        while (s[i] == ' ') i++;
        
        // Handle optional sign
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Convert characters to integer, stopping on non-digit
        while (s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
            
            // Handle overflow and underflow cases
            if (sign == 1 && result > MAX) return MAX;
            if (sign == -1 && -result < MIN) return MIN;
            
            i++;
        }
        
        return static_cast<int>(result * sign);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends