//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    void recPlaceQueen(vector<vector<int>>& res, vector<int>& placed, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        int c = placed.size();
        if (c == n) {
            res.push_back(placed);
            return;
        }

        for (int r = 0; r < n; r++) {
            int d1 = c - r + n; // Main diagonal
            int d2 = c + r; // Anti-diagonal
            if (cols[r] || diag1[d1] || diag2[d2]) continue;

            placed.push_back(r + 1); // Store 1-based index
            cols[r] = diag1[d1] = diag2[d2] = true;

            recPlaceQueen(res, placed, n, cols, diag1, diag2);

            placed.pop_back();
            cols[r] = diag1[d1] = diag2[d2] = false;
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> placed;
        vector<bool> cols(n, false); // Track occupied columns
        vector<bool> diag1(2 * n, false); // Track main diagonals
        vector<bool> diag2(2 * n, false); // Track anti-diagonals
        recPlaceQueen(res, placed, n, cols, diag1, diag2);
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends