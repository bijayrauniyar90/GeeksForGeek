//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    vector<string> ans;
    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<char> dirSymbols{'D', 'R', 'U', 'L'};

    void find(vector<vector<int>>& mat, int i, int j, int n, vector<vector<bool>>& vis, string st) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(st);
            return;
        }
        
        vis[i][j] = true;

        for (int k = 0; k < 4; ++k) {
            int ni = i + directions[k][0];
            int nj = j + directions[k][1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && mat[ni][nj] == 1 && !vis[ni][nj]) {
                find(mat, ni, nj, n, vis, st + dirSymbols[k]);
            }
        }

        vis[i][j] = false;  // Backtrack
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
            return {};
        }
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        find(mat, 0, 0, n, vis, "");
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends