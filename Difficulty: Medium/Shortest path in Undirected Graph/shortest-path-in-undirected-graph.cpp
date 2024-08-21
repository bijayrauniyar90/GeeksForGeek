//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src) {
        // Create an adjacency list
        vector<vector<int>> adjList(n);
        for (int i = 0; i < m; i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        // Initialize the result array with a large value (equivalent to 1000000)
        vector<int> res(n, INT_MAX);
        res[src] = 0;

        // Queue for BFS
        queue<int> q;
        q.push(src);

        // BFS
        vector<bool> visited(n, false);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (visited[curr]) {
                continue;
            }
            visited[curr] = true;

            for (int neighbor : adjList[curr]) {
                if (res[curr] + 1 < res[neighbor]) {
                    res[neighbor] = res[curr] + 1;
                    q.push(neighbor);
                }
            }
        }

        // Replace any INT_MAX values with -1 to indicate unreachable nodes
        for (int i = 0; i < n; i++) {
            if (res[i] == INT_MAX) {
                res[i] = -1;
            }
        }

        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends