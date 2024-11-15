//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    // Function to return the second largest element
    int getSecondLargest(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return -1; // Edge case: not enough elements
        
        int largest = INT_MIN, secondLargest = INT_MIN;

        // Iterate through the array
        for (int num : arr) {
            if (num > largest) {
                // Update second largest before largest
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest && num < largest) {
                // Update second largest if it's less than the current number and not equal to the largest
                secondLargest = num;
            }
        }

        // If no valid second largest was found, return -1
        return (secondLargest == INT_MIN) ? -1 : secondLargest;
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
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends