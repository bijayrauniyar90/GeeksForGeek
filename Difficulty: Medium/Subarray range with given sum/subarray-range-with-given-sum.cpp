//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    static int subArraySum(std::vector<int>& arr, int tar) {
        int n = arr.size();
        int curr_sum = 0;
        int count = 0;
        std::unordered_map<int, int> sum_freq;

        // Initialize with sum 0 occurring once
        sum_freq[0] = 1;

        for (int i = 0; i < n; i++) {
            curr_sum += arr[i];

            // Check if the (curr_sum - tar) exists in the map
            if (sum_freq.find(curr_sum - tar) != sum_freq.end()) {
                count += sum_freq[curr_sum - tar];
            }

            // Update the frequency of the current sum in the map
            sum_freq[curr_sum]++;
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends