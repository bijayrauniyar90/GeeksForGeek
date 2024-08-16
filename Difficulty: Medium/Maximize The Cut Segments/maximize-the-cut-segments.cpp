//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
        //Your code here
        int findMaxSegs(int n, int x, int y, int z, vector<int>& memo) {
    if (n == 0) {
        return 0;
    }
    if (memo[n] != -1) {
        return memo[n];
    }

    int res = INT_MIN;
    if (n >= x) {
        res = max(res, 1 + findMaxSegs(n - x, x, y, z, memo));
    }
    if (n >= y) {
        res = max(res, 1 + findMaxSegs(n - y, x, y, z, memo));
    }
    if (n >= z) {
        res = max(res, 1 + findMaxSegs(n - z, x, y, z, memo));
    }

    memo[n] = res;
    return memo[n];
}

int maximizeTheCuts(int n, int x, int y, int z) {
    vector<int> memo(n + 1, -1);
    int result = findMaxSegs(n, x, y, z, memo);
    return max(0, result);  // Ensure non-negative result
}

};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends