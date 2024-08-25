//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long countPairs(vector<int>& arr, vector<int>& brr) {
        int n = arr.size();
        int m = brr.size();
        
        sort(brr.begin(), brr.end());

        long long ans = 0;
        
        // Count occurrences of 1, 2, 3, and 4 in brr
        int one = 0, two = 0, three = 0, four = 0;
        for (int x : brr) {
            if (x == 1) one++;
            else if (x == 2) two++;
            else if (x == 3) three++;
            else if (x == 4) four++;
            else break; // Since brr is sorted, we can break early
        }

        for (int x : arr) {
            if (x == 1) continue;

            // Pairs with 1
            ans += one;

            if (x == 2) {
                // Count elements in brr greater than 2
                ans += m - (upper_bound(brr.begin(), brr.end(), 2) - brr.begin());
                // Exclude cases where x == 2 and y == 3 or y == 4
                ans -= (three + four);
            } else if (x == 3) {
                // Pairs with 2
                ans += two;
                // Count elements in brr greater than 3
                ans += m - (upper_bound(brr.begin(), brr.end(), 3) - brr.begin());
            } else {
                // Count elements in brr greater than x
                ans += m - (upper_bound(brr.begin(), brr.end(), x) - brr.begin());
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends