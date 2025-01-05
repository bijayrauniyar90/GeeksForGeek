//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int key=target-arr[i];
            int index=upper_bound(arr.begin()+i+1,arr.end(),key-1)-arr.begin();
            // cout<<index<<" ";
            ans+=(index-i-1);
        }
        return ans;

}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends