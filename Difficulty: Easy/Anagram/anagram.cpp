//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
   bool areAnagrams(string& s1, string& s2) {
    if (s1.size() != s2.size()) return false;

    int hash[26] = {0};
    for (int i = 0; i < s1.size(); i++) {
        hash[s1[i] - 'a']++;
        hash[s2[i] - 'a']--;
    }

    // Check if all counts in hash are zero
    for (int count : hash) {
        if (count != 0) return false;
    }

    return true;
}

};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends