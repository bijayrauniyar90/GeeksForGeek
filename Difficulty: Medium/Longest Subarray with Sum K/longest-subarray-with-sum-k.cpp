//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int longestSubarray(vector<int>& arr, int target) {
        // code here
        unordered_map<int,int> um;
        um.insert({0,-1});
        int n=arr.size();
        int ans=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(um.find(sum-target)!=um.end()){
                int temp=i-um[sum-target];
                ans=max(ans,temp);
            }
            if(um.find(sum)==um.end()){
              um[sum]=i;   
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends