//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // Function to find the maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int>& arr) {
        vector<int> result;
        deque<int> dq; // Store indices of useful elements for each window

        // Process the first k elements (first window)
        for (int i = 0; i < k; ++i) {
            // Remove elements from the deque that are smaller than the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // Add the maximum for the first window
        result.push_back(arr[dq.front()]);

        // Process the rest of the array
        for (int i = k; i < arr.size(); ++i) {
            // Remove elements that are out of the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements from the deque that are smaller than the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            // Add the current element index to the deque
            dq.push_back(i);

            // Add the maximum for the current window
            result.push_back(arr[dq.front()]);
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends