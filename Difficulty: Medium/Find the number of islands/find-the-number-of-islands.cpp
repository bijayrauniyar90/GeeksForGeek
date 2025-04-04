//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public: 
  int n,m; 
  vector<vector<char>> A;
  int dx[8]={+1,-1,+0,+1,-1,+1,+0,-1}; 
  int dy[8]={+1,-1,+1,+0,+1,-1,-1,+0}; 
  void Fill(int i,int j) { 
      A[i][j]='W'; 
      for(int k=0;k<8;k++) { 
          int k1=dx[k]+i; 
          int k2=dy[k]+j; 
          if(k1>=0 && k1<n && k2>=0 && k2<m && A[k1][k2]=='L')  
          Fill(k1,k2);
      }
  }
    int countIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++) 
        A.push_back(grid[i]);
    n=grid.size(); 
    m=grid[0].size();  
    int cnt=0;
     for(int i=0;i<n;i++) 
     for(int j=0;j<m;j++) { 
         if(A[i][j]=='L') { 
             cnt++; 
             Fill(i,j);
         }
     } 
     return cnt;
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
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends