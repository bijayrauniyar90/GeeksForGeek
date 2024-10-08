//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int pairsum(const vector<int>& arr) {
    int max1 = INT_MIN, max2 = INT_MIN;

    // Loop through the array to find the two largest distinct elements
    for (int i : arr) {
        if (i > max1) {
            max2 = max1;  // Update second largest before updating the largest
            max1 = i;     // Update the largest element
        } else if (i > max2 && i != max1) {
            max2 = i;     // Update second largest only if it’s distinct from the largest
        }
    }

    return max1 + max2;
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
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends