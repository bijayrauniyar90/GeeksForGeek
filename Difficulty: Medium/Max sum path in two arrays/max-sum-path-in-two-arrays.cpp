//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxPathSum(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        int prev_sum1 = 0, prev_sum2 = 0;
        int ans = 0;
        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (arr1[i] == arr2[j]) {
                // When a common element is found, add the maximum of the two sums
                ans += arr1[i] + max(prev_sum1, prev_sum2);
                prev_sum1 = 0;
                prev_sum2 = 0;
                i++;
                j++;
            } else if (arr1[i] < arr2[j]) {
                prev_sum1 += arr1[i];
                i++;
            } else {
                prev_sum2 += arr2[j];
                j++;
            }
        }

        // Add the remaining elements from arr1
        while (i < n1) {
            prev_sum1 += arr1[i];
            i++;
        }

        // Add the remaining elements from arr2
        while (j < n2) {
            prev_sum2 += arr2[j];
            j++;
        }

        // Add the maximum of the remaining sums
        ans += max(prev_sum1, prev_sum2);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends