//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Depth-First Search helper function
    void DFS(vector<int>& visit, int u, vector<int> adj[]) {
        visit[u] = true;
        for (auto v : adj[u]) {
            if (!visit[v])
                DFS(visit, v, adj);
        }
    }

    // Helper function to check if the graph can form a circle
    bool Solve(const vector<int>& mark, int src, vector<int> adj[]) {
        vector<int> visit(26, 0);
        DFS(visit, src, adj);
        
        // Check if all marked nodes are visited
        for (int i = 0; i < 26; i++) {
            if (mark[i] && !visit[i])
                return false;
        }
        return true;
    }

    // Main function to determine if the strings form a circle
    int isCircle(vector<string>& arr) {
        vector<int> adj[26];
        vector<int> in_degree(26, 0);
        vector<int> out_degree(26, 0);
        vector<int> mark(26, 0);
        int src = -1;

        // Construct the graph
        for (const string& str : arr) {
            int u = str[0] - 'a';
            int v = str.back() - 'a';
            adj[u].push_back(v);
            out_degree[u]++;
            in_degree[v]++;
            mark[u] = mark[v] = 1;
            if (src == -1) src = u; // Set source to the first character of the first string
        }

        // Ensure in-degrees and out-degrees match for all marked characters
        for (int i = 0; i < 26; i++) {
            if (in_degree[i] != out_degree[i])
                return 0;
        }

        // Check if the graph is connected using DFS
        return Solve(mark, src, adj);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends