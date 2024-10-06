//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void BFS(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        // Direction vectors for 8 neighboring cells
        int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty()) {
            // Access the front element of the queue
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Check all 8 directions
            for (int k = 0; k < 8; ++k) {
                int newX = x + dx[k];
                int newY = y + dy[k];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && 
                    grid[newX][newY] == '1' && !visited[newX][newY]) {
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islandCount = 0;

        // Traverse the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    // Start BFS for each new island found
                    BFS(i, j, n, m, grid, visited);
                    ++islandCount;
                }
            }
        }
        return islandCount;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends