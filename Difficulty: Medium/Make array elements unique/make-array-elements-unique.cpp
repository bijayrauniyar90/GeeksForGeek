//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
        // Code here
     int minIncrements(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int ans = 0;
    int nextUnique = arr[0];  // Initialize the next required unique number to the first element.

    for (int i = 1; i < arr.size(); i++) {
        nextUnique = max(nextUnique + 1, arr[i]);  // Ensure `nextUnique` is greater than the previous.
        ans += nextUnique - arr[i];                // Increment count to make arr[i] reach `nextUnique`.
    }

    return ans;
}

};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends