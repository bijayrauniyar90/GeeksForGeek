//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string S) {
    stringstream s(S);
    string ans, token;
    vector<string> tokens;

    // Split the string into tokens based on '.'
    while (getline(s, token, '.')) {
        tokens.push_back(token);
    }

    // Reverse the tokens and construct the result
    for (int i = tokens.size() - 1; i >= 0; i--) {
        ans += tokens[i];
        if (i > 0) {
            ans += '.';  // Add '.' between words, not after the last word
        }
    }

    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends