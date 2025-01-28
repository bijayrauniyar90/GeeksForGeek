//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void fun(string &s, vector<string>&ans, unordered_set<string>&ss, int i){
        if(i==s.size()){
            if(ss.find(s)==ss.end()){ans.push_back(s);}
            ss.insert(s); return;
        }
        for(int ii=i; ii<s.size(); ii++){
            swap(s[ii], s[i]);
            fun(s,ans,ss,i+1);
            swap(s[ii], s[i]);
        }
    }
    vector<string> findPermutation(string &s) {
        vector<string>ans;
        unordered_set<string>ss;
        fun(s,ans,ss,0);
        return ans;
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
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends