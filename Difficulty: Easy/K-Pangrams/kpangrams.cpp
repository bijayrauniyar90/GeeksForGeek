//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <string>
using namespace std;

class Solution {
public:
    bool kPangram(string str, int k) {
        int charCount[26] = {0};
        int uniqueCount = 0;
        
        // Count non-space characters and unique characters
        for (char ch : str) {
            if (ch != ' ') {
                if (charCount[ch - 'a'] == 0) {
                    uniqueCount++;
                }
                charCount[ch - 'a']++;
            }
        }

        // If total non-space characters are less than 26, it's not possible
        if (str.size() - count(str.begin(), str.end(), ' ') < 26) {
            return false;
        }

        // Calculate the number of missing characters
        int missingChars = 26 - uniqueCount;

        // Check if we can replace at most 'k' characters to get all 26 letters
        return missingChars <= k;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends