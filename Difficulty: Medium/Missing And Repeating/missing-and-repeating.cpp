//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    int xorAll = 0, xorArr = 0;
    int duplicate, missing;

    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xorAll ^= i;
    }

    // XOR all elements of the array
    for (int i = 0; i < n; i++) {
        xorArr ^= arr[i];
    }

    // XOR of xorAll and xorArr will give us (missing ^ duplicate)
    int xorResult = xorAll ^ xorArr;

    // Get the rightmost set bit in xorResult (which is the differentiating bit between missing and duplicate)
    int setBit = xorResult & ~(xorResult - 1);

    // Separate numbers based on the set bit
    int bucket1 = 0, bucket2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & setBit) {
            bucket1 ^= arr[i];
        } else {
            bucket2 ^= arr[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i & setBit) {
            bucket1 ^= i;
        } else {
            bucket2 ^= i;
        }
    }

    // Check which of bucket1 and bucket2 is the duplicate
    for (int i = 0; i < n; i++) {
        if (arr[i] == bucket1) {
            duplicate = bucket1;
            missing = bucket2;
            break;
        } else if (arr[i] == bucket2) {
            duplicate = bucket2;
            missing = bucket1;
            break;
        }
    }

    return {duplicate, missing};
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends