//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &a) {
        int n=a.size();
        int m=a[0].size();
        int k=n*m;
        int count=0;
        int starti=0;
        int startj=0;
        int endi=n-1;
        int endj=m-1; 
        vector<int>val;
        while(count!=k){ 
            for(int i=startj;i<=endj;i++){
                count++;
                val.push_back(a[starti][i]);
                if(count==k){
                    return val;
                }
            }
            starti++;
            for(int i=starti;i<=endi;i++){
                count++;
                val.push_back(a[i][endj]);
                if(count==k){
                    return val;
                }
            }
            endj--;
            for(int i=endj;i>=startj;i--){
                count++;
                val.push_back(a[endi][i]);
                if(count==k){
                    return val;
                }
            }
            endi--;
            for(int i=endi;i>=starti;i--){
                count++;
                val.push_back(a[i][startj]);
                if(count==k){
                    return val;
                }             
                
            }
            startj++;
        }
        return vector<int>{};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends